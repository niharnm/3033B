#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

motor Intake = motor(PORT20, ratio6_1, false);
motor LadyBrown = motor(PORT19,ratio6_1,false);


digital_out Clamp = digital_out(Brain.ThreeWirePort.H);  
digital_out Doinker = digital_out(Brain.ThreeWirePort.A);
digital_out IntakeLevel = digital_out(Brain.ThreeWirePort.B);



void vexcodeInit( void ) {
   Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);

  
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
  
  LadyBrown.spin(reverse,100,pct);
  wait(250,msec);
  LadyBrown.stop();
  LadyBrown.resetPosition();
 
}

void Raise(void){
  LadyBrown.spinToPosition(0.9,rev);
  LadyBrown.stop(hold);
}

void Release(void){
  LadyBrown.spinToPosition(0,rev);
  LadyBrown.stop(hold);
}

void Score(void){
  LadyBrown.spinToPosition(6.5,rev);
  LadyBrown.stop(hold);
}

void ClampIn(){
  Clamp.set(true);
}
void ClampOut(){
  Clamp.set(false);
}
void DoinkerIn(){
  Doinker.set(false);
}
void DoinkerOut(){
  Doinker.set(true);
}
void IntakeLiftUp(){
  IntakeLevel.set(true);
}
void IntakeLiftDown(){
  IntakeLevel.set(false);
}

void toggleDoinker(void){
  if(Doinker.value()){
    Doinker.set(false);
  }
  else{
    Doinker.set(true);
  }
  wait(250, msec);
}


void toggleClamp(void){
  if(Clamp.value()){
    Clamp.set(false);
  }
  else{
    Clamp.set(true);
  }
  wait(250, msec);
}