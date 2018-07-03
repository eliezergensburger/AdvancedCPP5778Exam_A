#include "Gym.h"
#include <iostream>
using namespace std;

int main()
{
	Gym jctGym;

	Aerobic a = Aerobic(101, "treadmill", 200);
	jctGym.devices.push_back(a);

	Trainee johndoe = Trainee("john doe");
	jctGym.trainees.push_back(johndoe);

	ExerciseAerobic ex = ExerciseAerobic(a, 30, 120);

	johndoe.addExercise(&ex, "03 07 2018");

	return 0;
}