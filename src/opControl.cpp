#include "opControl.h"

pros::MotorGroup leftG({1, -2, 3});
pros::MotorGroup rightG({-4, 5, -6});

pros::Controller cont1(pros::E_CONTROLLER_MASTER);



void control(){
	pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);  // Prints status of the emulated screen LCDs

		// Arcade control scheme
		int dir = cont1.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = cont1.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		left_mg.move(dir - turn);                      // Sets left motor voltage
		right_mg.move(dir + turn);                     // Sets right motor voltage
		pros::delay(20);                               // Run for 20 ms then update
}
