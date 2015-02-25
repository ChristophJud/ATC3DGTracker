#ifndef _PointATC3DG_
#define _PointATC3DG_

// Device Vendor ID (idVendor)
#ifndef BIRD_VENDOR
//#define BIRD_VENDOR     1204
#define BIRD_VENDOR     0x21e2
#endif

// Device Product ID (idProduct)
#ifndef BIRD_PRODUCT
//#define BIRD_PRODUCT	4099 // medSAFE
//#define BIRD_PRODUCT  4101 // trakSTAR
#define BIRD_PRODUCT    0x1008 // driveBAY2
#endif

// Device Endpoint-Out
#ifndef BIRD_EP_OUT
#define BIRD_EP_OUT     0x02
#endif

// Device Endpoint-In
#ifndef BIRD_EP_IN
#define BIRD_EP_IN      0x86
#endif

// forward declarations
struct usb_device;
struct usb_dev_handle;

class PointATC3DG {
public:
    PointATC3DG();
    ~PointATC3DG();

    // evaluate whether initialized properly
    bool operator!() const;
    bool ok() const;

    int setSuddenOutputChangeLock( int iSensorId );

    int setSensorRotMat( int iSensorId );
    int setSensorTopHemisphere( int iSensorId );
    int setSensorHemisphere( int iSensorId, char cSphereId );
    int setMeasurementRate( double dRate );

    int getNumberOfSensors( void );
    int getCoordinatesAngles( int iSensorId,
        double& dX, double& dY, double& dZ,
        double& dAzimuth, double& dElevation, double& dRoll );
    int getCoordinatesMatrix( int iSensorId,
        double& dX, double& dY, double& dZ,
        double* pMat );

    bool transmitterAttached();
    bool sensorAttached(const int& iSensorId);

protected:
    struct usb_device* find_device( int iVendorId, int iProductId );

    int check_bird_errors( void );
    void error( int val, const char* msg, ... );

protected:
    struct usb_device *dev;
    struct usb_dev_handle *handle;

    char dataout[16];
    char datain[32];

    bool isOk;
    double posk;
};

#endif // _PointATC3DG_

