#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	PID::Kp=Kp;
	PID::Ki=Ki;
	PID::Kd=Kd;
	prev_cte=0.0;
	p_error=0.0;
	i_error=0.0;
	d_error=0.0;
}

void PID::UpdateError(double cte) {
	p_error=cte;
	i_error+=cte;
	d_error=cte-prev_cte;
	prev_cte=cte;
    

}

double PID::TotalError() {
	

	double control=Kp*p_error+Ki*i_error+Kd*d_error;
    //std::cout << "kp: " << Kp << " ki" << Ki <<"kd"<<Kd<< std::endl;
    //std::cout << "p_error: " << p_error << " i_error:" << i_error <<"d_error:"<<d_error<< std::endl;
    if (control>1)
    {
      control=1;
    }
   else if(control<-1)
   {
     control=-1;
   }
  
	return control;
}

