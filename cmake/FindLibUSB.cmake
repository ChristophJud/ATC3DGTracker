# Once done this will define
#
# LIBUSB_FOUND
# LIBUSB_INCLUDE_PATH
# LIBUSB_LIBRARY
# 

FIND_PATH (LIBUSB_INCLUDE_DIR usb.h
        PATHS /usr/include/
	DOC "The directory where the USB headers reside")

FIND_LIBRARY (LIBUSB_LIBRARY
      NAMES libusb.so
      PATHS /usr/lib/
      DOC "The libusb shared library") 
 
IF (LIBUSB_INCLUDE_DIR AND LIBUSB_LIBRARY)
	SET (LIBUSB_FOUND TRUE)
ELSE (LIBUSB_INCLUDE_DIR AND LIBUSB_LIBRARY)
	SET (LIBUSB_FOUND FALSE)
	message("USB library not found. Try to install it by sudo apt-get install libusb-dev")
ENDIF (LIBUSB_INCLUDE_DIR AND LIBUSB_LIBRARY)

SET (LIBUSB_LIBRARY ${LIBUSB_LIBRARY})
SET (LIBUSB_INCLUDE_DIR ${LIBUSB_INCLUDE_DIR})




