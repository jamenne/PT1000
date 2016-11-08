/*

PT1000Control.cpp


Created by Janine Müller on 07.10.2016

*/

#include <gpib/ib.h>
#include <gpib/gpib_user.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "time.h"
#include <sstream>
#include <cmath>

#include "PT1000Control.h"

using namespace std;

//---------------------PT1000 class---------------------//

// Constructor
PT1000::PT1000(MultiMeter &MultiM) :
	_MultiM(MultiM),
	_value(314), //resistance in Ohm
	_temperature(314) // temperature in °C
{
	
};

//Destructor
PT1000::~PT1000(){

};

MultiMeter& PT1000::GetMultiMeter(){

	return this->_MultiM;
}

void PT1000::Initialize(){

	this->_MultiM.Set4WireFunction();
	this->_MultiM.SetAutorange4Wire();
	this->_MultiM.SetTriggerContinously();

}

double PT1000::GetTemperature(bool below_0Celsius){
	
	double A = 3.9083e-3; // °C^-1
	double B = -5.775e-7; //°C^-2
	double C = -4.183e-12; // °C^-4
	double R0 = 1000;

	this->_value = _MultiM.Fetch();

	if (below_0Celsius == true)
	{
		this->_temperature = (-R0*A + sqrt((R0*R0*A*A) - (4*R0*B*(R0 - this->_value))))/(2*R0*B); // returns temperature in °C
	}
	
	else this->_temperature = (-R0*A + sqrt((R0*R0*A*A) - (4*R0*B*(R0 - this->_value))))/(2*R0*B); // returns temperature in °C

	cout << "Measured PT1000 temperature to: " << this->_temperature << "°C" << endl;

	return this->_temperature;
}













