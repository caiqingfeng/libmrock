## A powerful c++ library
### highlights
* heavy usage with boost, zeromq, protobuf, redis and well-integrated
* a well-designed pesistence-layer (redis+mysql)
* a portable client/server network library across ios, android, linux, macos
* very suitable for non-http applications like real time games 

### who use this library
used inside Luyun Information Technologies Inc., 2012-2016. My colleage Chenfeng also contributed to this library. @ivychill

### why open source
* hope be helpful to anyone who wants to write a high efficient client-server applications
* less bandwidth to maintain this library since 2016
* welcome any volunteers

## Dependencies
* OS: Linux (ubuntu 16.04/18.04 tested)  
* OS: MacOS 12+ 
* Compiler: g++ 4.2+
* cmake
* scons
* mysql mysql-server, mysql-client, libmysqld-dev
* redis

### install autotools
$ sudo apt-get install autotools-dev  
$ sudo apt-get install autoconf  
$ sudo apt-get install automake  
$ sudo apt-get install perl  

### install Boost 1.56: 
have to download boost source code first.   
$ cd vendor  
$ cd boost_1_56_0  
$ ./bootstrap.sh  
$ ./b2  
$ sudo ./b2 install   

### install log4cplus 
$ cd vendor  
$ cd log4cplus-1.2.0   
$ ./configure  
$ make  
$ sudo make install  

### install protobuf 2.5.0 
$ cd vendor  
$ cd protobuf-2.5.0  
$ ./configure  
$ make  
$ sudo make install  

### install zeromq 4.0.4 
$ cd vendor  
$ cd zeromq-4.0.4  
$ ./configure  
$ make  
$ sudo make install  

### install cryptopp5.62
$ cd vendor  
$ cd cryptopp562  
$ make  
$ sudo make install  

you may see a complaint like:
cp: cannot stat `*.so': No such file or directory
make: [install] Error 1 (ignored)
just ignore it. It's okay.

### install hiredis
$ cd vendor  
$ cd hiredis  
$ make  
$ sudo make install   


### install Mysql connector/c++ 1.1.3
$ cd vendor  
$ cd mysql-connector-c++-1.1.3  
$ cmake .  
$ make  
$ sudo  make install  

if get a complaint during compiling like this：
cannot find libmysqlclient_r.so, 
$ cd /usr/lib/x86_64-linux-gnu   
$ sudo ln -s libmysqlclient.so.20 libmysqlclient_r.so  

### install jsoncpp-0.6.0
$ cd vendor  
$ cd mysql-connector-c++-1.1.3  
$ scons platform=linux-gcc   
you need copy manually ./buildscons/linux-gcc-4.6/src/lib_json/libjson_linux-gcc-4.6_libmt.a and 
 ./buildscons/linux-gcc-4.6/src/lib_json/libjson_linux-gcc-4.6_libmt.so to /usr/local/lib
and execute  
$ cd /usr/local/lib && sudo ln –s   libjson_linux-gcc-4.6_libmt.so    libjson_linux-gcc-4.x_libmt.so  
$ sudo cp –R include/json /usr/local/include  
$ cd /usr/local/include && sudo ln –s json   jsoncpp-0.6.0-rc2  

*note: if your g++'s version is 7, replace 4.6 with 7.
check buildscons

### install googletest 1.8.0
$ cd vendor   
$ cd googletest   
$ cmake .  
$ make   
$ sudo make install   

### compile and run test
$ make clean all test  

### use this library
1. put libmrock in a easy-searchable path
2. in your c++ project, declare include path and link liabrary (i will give an example when i have some bandwidth)

:-) and you are good to go.


# License
This library is licensed under the Apache Public License 2.0 and two clause BSD license. Please read the included LICENSE file for details.

# Patches
Anybody can contribute to log4cplus development. If you are contributing a source code change, use a reasonable form: a merge request of a Git branch or a patch file attached to a ticket in Bugs tracker or sent email to me. Unless it is obvious, always state what branch or release tarball is your patch based upon.