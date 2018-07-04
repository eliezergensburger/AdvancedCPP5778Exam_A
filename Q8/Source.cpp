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
	AerobicPowerDevice ap = AerobicPowerDevice(303, "meshulav 200", 450, "legs");

	jctGym.devices.push_back(&a);
	jctGym.devices.push_back(&p);
	jctGym.devices.push_back(&ap);

	ExerciseAerobic ex = ExerciseAerobic(a, 30, 120);
	ExercisePower exp = ExercisePower(p, 15, 20);
	ExercisePowerAerobic expa = ExercisePowerAerobic(ap, 10, 15, 20, 153);

	cout << ex.getDevice()->deviceInfo() << endl;
	cout << ex.toString() << endl;
	cout << endl;

	cout << exp.getDevice()->deviceInfo() << endl;
	cout << exp.toString() << endl;
	cout << endl;

	cout << expa.getDevice()->deviceInfo() << endl;
	cout << expa.toString() << endl;
	cout << endl;

	johndoe.addExercise(&ex, "03 07 2018");
	johndoe.addExercise(&exp, "03 07 2018");
	johndoe.addExercise(&expa, "03 07 2018");

	johndoe.workout(202);
	cout << endl;

	johndoe.fullworkout();
	cout << endl;

	cout << "**********************" << endl;
	cout << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^" << endl;
	johndoe.printAllAerobicExercises();
	cout << "^^^^^^^^^^^^^^^^^^^^^^" << endl;
	johndoe.printAllPowerExercises();
	cout << "^^^^^^^^^^^^^^^^^^^^^^" << endl;
/*	Trainee & tt = *(jctGym.trainees.front());
	jctGym.trainees.front()->printAllPowerExercises();
	cout << "trainee full workout " << endl;
	tt.fullworkout();
	*/
	system("pause");
	return 0;
}
