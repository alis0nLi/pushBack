#include "opControl.h"

void opControl()
{
    pros::Optical optical_sensor(16);
    pros::c::optical_rgb_s_t rgb_value;

    rgb_value = optical_sensor.get_rgb();
    printf("Red value: %lf \n", rgb_value.red);

    printf("Blue value: %lf \n", rgb_value.blue);

    pros::delay(20);
}
