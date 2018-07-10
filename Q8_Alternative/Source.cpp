#include "Gym.h"
#include <iostream>

using namespace std;

int main()
{
	Gym jctGym;

	jctGym.addTrainee(new Trainee("john doe"));

	DeviceAerobic a = DeviceAerobic(101, "treadmill", 200);
	DevicePower p = DevicePower(202, "dumbbells 5kg", "shoulders");
	DeviceAerobicPower ap = DeviceAerobicPower(303, "meshulav 200", 450, "legs");

	jctGym.addDevice(&a);
	jctGym.addDevice(&p);
	jctGym.addDevice(&ap);

	ExerciseAerobic ex = ExerciseAerobic(a, 30, 120);
	ExercisePower exp = ExercisePower(p, 15, 20);
	ExerciseAerobicPower  exap = ExerciseAerobicPower(ap, 10, 15, 20, 153);

	cout << ex.getDevice()->deviceInfo() << endl;
	cout << ex.toString() << endl;
	cout << endl;

	cout << exp.getDevice()->deviceInfo() << endl;
	cout << exp.toString() << endl;
	cout << endl;

	cout << exap.getDevice()->deviceInfo() << endl;
	cout << exap.toString() << endl;
	cout << endl;

	Trainee* p_johndoe = jctGym.getTrainee("john doe");
	p_johndoe->addExercise(&ex, "03 07 2018");
	p_johndoe->addExercise(&exp, "03 07 2018");
	p_johndoe->addExercise(&exap, "03 07 2018");

	p_johndoe->workout(202);
	cout << endl;

	p_johndoe->fullworkout();
	cout << endl;

	cout << "**********************" << endl;
	cout << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^" << endl;
	p_johndoe->printAllAerobicExercises();
	cout << "^^^^^^^^^^^^^^^^^^^^^^" << endl;
	p_johndoe->printAllPowerExercises();
	cout << "^^^^^^^^^^^^^^^^^^^^^^" << endl;
	/*	Trainee & tt = *(jctGym.trainees.front());
	jctGym.trainees.front()->printAllPowerExercises();
	cout << "trainee full workout " << endl;
	tt.fullworkout();
	*/
	system("pause");
	return 0;
}
