#include <iostream>

#include "Utils.h"
#include "PointATC3DG.h"


int main( int argc, char** argv ){
	PointATC3DG bird;

	if( !bird ) return -1;

	bird.setSuddenOutputChangeLock( 0 );

	double dX, dY, dZ, dAzimuth, dElevation, dRoll;
	
	int numsen=bird.getNumberOfSensors();
	std::cout << "nSensors: " << numsen << std::endl;

	int rec_count=0;	 
	time_t ta=time(NULL);
	while (!kbhit()) 
	{	
		rec_count++;
	//	usleep( 100000 );
		for( int i = 0; i <numsen  ; ++i ) 
		{
			bird.getCoordinatesAngles( i, dX, dY, dZ, dAzimuth, dElevation, dRoll );
			std::cout << "\rX: " << dX << ", \tY: " << dY << ", \tZ: " << dZ;
        		std::cout << ", \tA: " << dAzimuth << ", \tE: " << dElevation << ", \tR: " << dRoll << std::endl;
		}
	}
	time_t tb=time(NULL);
	std::cout << rec_count << " samples collected" << std::endl;
	std::cout << tb-ta << " seconds elapsed" << std::endl;
	std::cout << rec_count/(tb-ta) << " samples per second" << std::endl;
	return 0;
}


