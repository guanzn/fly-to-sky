#include "motorc.h"
#include "public.h"
#include "PWM.h"

extern struct _pid x_pitch;
extern struct _pid y_roll;
extern struct _pid z_yaw;
extern struct _pid direct;
extern u16 acc;
extern u8 DirectX;
extern u8 DirectY;
void balance_pid(float pitch,float roll,float yaw)
{
/* directxy  PID caculate   */	
	pitch =pitch - (DirectX -100)/10;
	roll = roll - (DirectY -100)/10;
	
/* balance_pitch PID caculate   */
	x_pitch.oldoutput=x_pitch.newoutput;
	x_pitch.newoutput = x_pitch.kp*(pitch)+ x_pitch.ki*x_pitch.integral+x_pitch.kd*(pitch-x_pitch.oldangle);
	if(acc >= 300)	x_pitch.integral += pitch/100; 
	else x_pitch.integral=0;
	x_pitch.oldangle=pitch;
	x_pitch.oldoutput=x_pitch.newoutput;
	if(x_pitch.integral > 200) x_pitch.integral=200;
	if(x_pitch.integral < -200) x_pitch.integral=-200;	
	if(x_pitch.newoutput<-800) x_pitch.newoutput=-800;
	if(x_pitch.newoutput>800) x_pitch.newoutput=800;
	
/* balance_roll PID caculate   */
	y_roll.oldoutput=y_roll.newoutput;
	y_roll.newoutput = y_roll.kp*(roll)+ y_roll.ki*y_roll.integral+y_roll.kd*(roll-y_roll.oldangle);
	if(acc >= 300)y_roll.integral += roll/100;
	else y_roll.integral=0;
	y_roll.oldangle=roll;
	y_roll.oldoutput=y_roll.newoutput;
	if(y_roll.integral > 200) y_roll.integral=200;
	if(y_roll.integral < -200) y_roll.integral=-200;	
	if(y_roll.newoutput<-800) y_roll.newoutput=-800;
	if(y_roll.newoutput>800) y_roll.newoutput=800;
	
/* balance_yaw PID caculate   */
	z_yaw.oldoutput=y_roll.newoutput;
	z_yaw.newoutput = z_yaw.kp*(roll);//+ z_yaw.ki*z_yaw.integral+z_yaw.kd*(yaw-z_yaw.oldangle);
//	z_yaw.integral += roll; 
//	z_yaw.oldangle=pitch;
//	z_yaw.oldoutput=z_yaw.newoutput;
	if(z_yaw.newoutput<-800) z_yaw.newoutput=-800;
	if(z_yaw.newoutput>800) z_yaw.newoutput=800;
	
	if(acc<10)
	{	
		PWM_Output(0,0,0,0);
		
	}
	else
	{
		PWM_Output(acc+x_pitch.newoutput-y_roll.newoutput-z_yaw.newoutput,
							 acc-x_pitch.newoutput-y_roll.newoutput+z_yaw.newoutput,
							 acc-x_pitch.newoutput+y_roll.newoutput-z_yaw.newoutput,
							 acc+x_pitch.newoutput+y_roll.newoutput+z_yaw.newoutput);  //pitch  1+4  2+3  roll 1+2 3+4
	}
}


