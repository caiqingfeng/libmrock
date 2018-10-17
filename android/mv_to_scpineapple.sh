cd include
rm -rf ../../../scpineapplev2/phonegap/platforms/android/jni/libmrock/*
cp -rf ./* ../../../scpineapplev2/phonegap/platforms/android/jni/libmrock
cd ../lib
cp -rf ./* ../../../scpineapplev2/phonegap/platforms/android/jni/libmrock
cd ..
