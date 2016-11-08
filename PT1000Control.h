/*

PT1000Control.h


Created by Janine Müller on 12.10.2016


*/

#ifndef ____PT1000__
#define ____PT1000__

#include <string>
#include <vector>

#include "../MultiMeter/MultiMeter.h"


class PT1000
{

public:
	PT1000(MultiMeter &MultiM);
	~PT1000();
	MultiMeter& GetMultiMeter();
	void Initialize();
	void Close();

	double GetTemperature(bool below_0Celsius);

private:

	MultiMeter& _MultiM; // MultiMeter for 4 wire measurement of resistance
	double _value; // resistance in Ohm
	double _temperature; // temperature in °C

};


#endif /* defined(____PT1000__) */