using namespace vex;

extern brain Brain;
extern motor Intake;
extern motor LadyBrown ;

extern digital_out Clamp ;
extern digital_out Doinker;
extern digital_out IntakeLevel;
//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:


void Raise(void);
void Score(void);
void Release(void);
void ClampIn(void);
void ClampOut(void);
void DoinkerIn(void);
void DoinkerOut(void);
void IntakeLiftUp(void);
void IntakeLiftDown(void);
void vexcodeInit( void );
void toggleDoinker(void);
void toggleClamp(void);
void opcontrol();
void usercontrol();