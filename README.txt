README
------------
* User rights:
    This software has been written originally by an unknown customer of NDI Europe GmbH.
    It has been refactored, packed into a cmake project and uploaded to github by
    Christoph Jud (christoph.jud@unibas.ch) with the Apache 2.0 license.

* Prerequisites:
    Have the development release libusb installed (this should be easy to do through your
    Linux distribution's package management system, e.g., YaST in SUSE Linux)

* Files:
    lib/PointATC3DG.cpp
      Driver, based on libusb

    include/PointATC3DG.h
      Header file containing declaration of driver functions.

    src/PointATC3DG_test.cpp 
      Example commandline program. Continuously outputs sensor's coordinates
      and rotation angles.

    CMakeLists.txt
      cmake files to compile driver and example program.


* Compile:
    mkdir build
    cd build
    ccmake ..
    c
    (set CMAKE_BUILD_TYPE to release)
    (set CMAKE_INSTALL_PREFIX to your installation directory)
    g
    make
    make install
 
    This will also compile the example program PointATC3DG_test.cpp
    Make sure that you have added the directory lib of your installation directory to
    the LD_LIBRARY_PATH.

* Support for medSAFE and trackSTAR / driveBAY
    in PointATC3DG.h uncomment the appropriate defination for the tracker you have
#define BIRD_PRODUCT	0x4099 // medSAFE
OR
#define BIRD_PRODUCT    0x4101 // trakSTAR
OR
#define BIRD_PRODUCT    0x1008 // driveBAY2
#define BIRD_VENDOR     0x21e2

    You can derive these ids with e.g. lsusb.


*libusb configuration:
    The main problem is to get the access rights to the USB device configured
    correctly. If the example program compiled above works then
    you are done. If not then you will have to configure the permissions.
   
    You can try to run ATC3DG_test as user root. If the test program runs
    as root, but not as a regular user, then you confirmed that you are facing
    a permission problem. In that case keep reading! 
   
   
    The problem is that libusb usually only works for the root user. One way
    to fix this is to create a libusb group on the system, add the desired
    user to the group and configure udev to give that libusb group ownership
    of the device.
   
    This means, basically, finding the udev configuration file that has libusb
    and fixing it so that it says MODE="0664", GROUP="libusb". You can 
   
    copy 99-libusb.rules to /lib/udev/rules.d/  

    as well.
 
    In order to get the device to fall into libusb we had to execute
   
      rmmod ehci_hcd
   
    to remove the module from the kernel. To get it to work all the time we
    added 
   
      blacklist ehci_hcd
   
    to the /etc/modules.d/blacklist file. 

