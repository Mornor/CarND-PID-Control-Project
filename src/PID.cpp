#include <iostream>
#include <limits>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp; // Proportionnal term
	this->Ki = Ki; // Integral term 
	this->Kd = Kd; // Differential term

	// Init the Proportionnal error to a high value
	// Because, at the very beginning, I assume the car is far from the CTE 
	this->p_error = numeric_limits<double>::max();  

	// Init the Integral term to 0
	// Because, at the very beginning, the total area (Integral definition) between the position of the car 
	// and the CTE is null (because the car has not started yet)
	this->i_error = 0.0;

	// Init the Differential error to 0
	// Because, at the very beginning, the position of the car is assumed to be far away from CTE
	this->d_error = 0.0; 
}

void PID::UpdateError(double cte) {
}

double PID::TotalError() {
	return 0.0; 
}

