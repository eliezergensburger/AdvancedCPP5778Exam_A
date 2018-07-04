#include "Gym.h"
#include <iostream>
using namespace std;

int main()
{
	Gym jctGym;

	Trainee johndoe = Trainee("john doe");
	jctGym.trainees.push_back(&johndoe);

	AerobicDevice a = AerobicDevice(101, "treadmill", 200);
	PowerDevice p = PowerDevice(202, "dumbbells 5kg", "shoulders");

	jctGym.devices.push_back(&a);
	jctGym.devices.push_back(&p);

	ExerciseAerobic ex = ExerciseAerobic(a, 30, 120);
	ExercisePower exp = ExercisePower(p, 15, 20);

	cout << ex.getDevice()->description() << endl;
	cout << ex.toString() << endl;

	cout << exp.getDevice()->description() << endl;
	cout << exp.toString() << endl;

	johndoe.addExercise(&ex, "03 07 2018");
	johndoe.addExercise(&exp, "03 07 2018");

	johndoe.workout(202);
	johndoe.fullworkout();
	cout << "**********************" << endl;
	johndoe.printAllAerobicExercises();
	johndoe.printAllPowerExercises();
	cout << "^^^^^^^^^^^^^^^^^^^^^^" << endl;
	Trainee & tt = *(jctGym.trainees.front());
	jctGym.trainees.front()->printAllPowerExercises();
	cout << "trainee full workout " << endl;
	tt.fullworkout();
	system("pause");
	return 0;
}
