// Project PID Controller
// File PID.cpp
// Author: Jelena Kocic
// Date: 24.06.2017.

#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) 
{
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  
  p_error = 0;
  i_error = 0;
  d_error = 0;
}

void PID::UpdateError(double cte) 
{
  // we have to calculate d_error befoere we calculate p_error
  // in order to get: d_error = cte - pervious_cte
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte ;
  
}

double PID::TotalError(double speed) 
{
  return Kp*p_error/speed + Ki*i_error + Kd*d_error;
}

