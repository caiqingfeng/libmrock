#!/bin/bash

WORK_PATH=`cd $(dirname $0) && pwd`

if [ ! -d ${WORK_PATH}/include ]; then (mkdir ${WORK_PATH}/include); fi
if [ ! -d ${WORK_PATH}/lib ]; then (mkdir ${WORK_PATH}/lib); fi

ARCHS=${ARCHS:-"armv7 armv7s arm64 i386 x86_64"}
DEVELOPER=$(xcode-select -print-path)
LIPO=$(xcrun -sdk iphoneos -find lipo)
SDK=$(xcodebuild -showsdks \
    | grep iphoneos | sort | tail -n 1 | awk '{print substr($NF, 9)}'
    )

export CXX=clang
export AR=libtool
export ARFLAGS="-static -o"
export RANLIB=ranlib
OTHER_CFLAGS="-DNDEBUG -g -O0 -pipe -fPIC -fcxx-exceptions"
OTHER_CPPFLAGS="-DNDEBUG -g -O0 -pipe -fPIC -fcxx-exceptions -std=c++11 -stdlib=libc++ -D_MOBILE_ -I/opt/ios-cross-compile/boost_1.56/ -I${WORK_PATH} -I${WORK_PATH}/zmq -I${WORK_PATH}/protobuf/include -I${WORK_PATH}/cryptopp -I/usr/local/include"
OTHER_CXXFLAGS="-DNDEBUG -g -O0 -pipe -fPIC -fcxx-exceptions -std=c++11 -stdlib=libc++ -D_MOBILE_ -I/opt/ios-cross-compile/boost_1.56/ -I${WORK_PATH} -I${WORK_PATH}/zmq -I${WORK_PATH}/protobuf/include -I${WORK_PATH}/cryptopp -I/usr/local/include"
OTHER_LDFLAGS="-stdlib=libc++"

make init

for ARCH in ${ARCHS}
do
    case ${ARCH} in
        armv7)
	    PLATFORM="iPhoneOS"
	    HOST="${ARCH}-apple-darwin"
	    export BASEDIR="${DEVELOPER}/Platforms/${PLATFORM}.platform/Developer"
	    export ISDKROOT="${BASEDIR}/SDKs/${PLATFORM}${SDK}.sdk"
	    export CXXFLAGS="-arch ${ARCH} -isysroot ${ISDKROOT} ${OTHER_CXXFLAGS}"
	    export CPPFLAGS="-arch ${ARCH} -isysroot ${ISDKROOT} ${OTHER_CPPFLAGS}"
	    export LDFLAGS="-arch ${ARCH} -isysroot ${ISDKROOT} ${OTHER_LDFLAGS}"
            ;;
        armv7s)
	    PLATFORM="iPhoneOS"
	    HOST="${ARCH}-apple-darwin"
	    export BASEDIR="${DEVELOPER}/Platforms/${PLATFORM}.platform/Developer"
	    export ISDKROOT="${BASEDIR}/SDKs/${PLATFORM}${SDK}.sdk"
	    export CXXFLAGS="-arch ${ARCH} -isysroot ${ISDKROOT} ${OTHER_CXXFLAGS}"
	    export CPPFLAGS="-arch ${ARCH} -isysroot ${ISDKROOT} ${OTHER_CPPFLAGS}"
	    export LDFLAGS="-arch ${ARCH} -isysroot ${ISDKROOT} ${OTHER_LDFLAGS}"
            ;;
        arm64)
	    PLATFORM="iPhoneOS"
	    HOST="${ARCH}-apple-darwin"
	    export BASEDIR="${DEVELOPER}/Platforms/${PLATFORM}.platform/Developer"
	    export ISDKROOT="${BASEDIR}/SDKs/${PLATFORM}${SDK}.sdk"
	    export CXXFLAGS="-arch ${ARCH} -isysroot ${ISDKROOT} ${OTHER_CXXFLAGS}"
	    export CPPFLAGS="-arch ${ARCH} -isysroot ${ISDKROOT} ${OTHER_CPPFLAGS}"
	    export LDFLAGS="-arch ${ARCH} -isysroot ${ISDKROOT} ${OTHER_LDFLAGS}"
            ;;
        i386)
	    PLATFORM="iPhoneSimulator"
	    HOST="${ARCH}-apple-darwin"
	    export BASEDIR="${DEVELOPER}/Platforms/${PLATFORM}.platform/Developer"
	    export ISDKROOT="${BASEDIR}/SDKs/${PLATFORM}${SDK}.sdk"
	   	export CXXFLAGS="-m32 -arch ${ARCH} -isysroot ${ISDKROOT} -miphoneos-version-min=${SDK} ${OTHER_CXXFLAGS}"
	    export CPPFLAGS="-m32 -arch ${ARCH} -isysroot ${ISDKROOT} -miphoneos-version-min=${SDK} ${OTHER_CPPFLAGS}"
	    export LDFLAGS="-m32 -arch ${ARCH} ${OTHER_LDFLAGS}"
            ;;
        x86_64)
	    PLATFORM="iPhoneSimulator"
	    HOST="${ARCH}-apple-darwin"
	    export BASEDIR="${DEVELOPER}/Platforms/${PLATFORM}.platform/Developer"
	    export ISDKROOT="${BASEDIR}/SDKs/${PLATFORM}${SDK}.sdk"
	    export CXXFLAGS="-arch ${ARCH} -isysroot ${ISDKROOT} -miphoneos-version-min=${SDK} ${OTHER_CXXFLAGS}"
	    export CPPFLAGS="-arch ${ARCH} -isysroot ${ISDKROOT} -miphoneos-version-min=${SDK} ${OTHER_CPPFLAGS}"
	    export LDFLAGS="-arch ${ARCH} ${OTHER_LDFLAGS}"
	    echo "LDFLAGS $LDFLAGS"
            ;;
        *)
            echo "Unsupported architecture ${ARCH}"
            exit 1
            ;;
    esac

    export PATH="${DEVELOPER}/Toolchains/XcodeDefault.xctoolchain/usr/bin:${DEVELOPER}/Toolchains/XcodeDefault.xctoolchain/usr/sbin:$PATH"

    echo "Building for ${PLATFORM} ${SDK} ${ARCH} ..."

    make clean
    make
    make install
    mv lib/libmrock-frontend.a lib/libmrock-frontend-${ARCH}.a
done

make clean

echo "Creating universal library..."
xcrun -sdk iphoneos lipo -create lib/libmrock-frontend-i386.a lib/libmrock-frontend-x86_64.a lib/libmrock-frontend-armv7.a lib/libmrock-frontend-armv7s.a lib/libmrock-frontend-arm64.a -output lib/libmrock-frontend.a
