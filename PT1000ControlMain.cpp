/*

PT1000.cpp

Created by Janine Müller on 07.10.2016

*/

#include <iostream>
#include <fcntl.h> //keyboard interupt

#include "../gpib/gpib.h"
#include "PT1000Control.h"

int main(int argc, char const *argv[])
{

	// ----------Flags for while(true) interrupt------------- //
	int fd = STDIN_FILENO;
	int flags = fcntl(fd, F_GETFL, 0);
	fcntl(fd, F_SETFL, flags | O_NONBLOCK);

	//--------------------------GPIB adapter----------------------------//
	int masterUD = InitializeMaster();

	//--------------------------MultiMeter----------------------------//	

	MultiMeter MultiM;

	int MultiMeterPad = 17;

	MultiM.Initialize(masterUD, MultiMeterPad);

	PT1000 Thermometer(MultiM);

	Thermometer.Initialize();

	do{

		cout << "Temperature:\t" << Thermometer.GetTemperature(false);
		

	}while(getchar() != 'q');

	return 0;
}
