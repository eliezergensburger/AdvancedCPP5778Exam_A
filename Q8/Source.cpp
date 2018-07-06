#include "Gym.h"
#include <iostream>
#include "Source.h"
using namespace std;

int main()
{
	Gym jctGym;

	jctGym.addTrainee(new Trainee("john doe"));

	AerobicDevice a = AerobicDevice(101, "treadmill", 200);
	PowerDevice p = PowerDevice(202, "dumbbells 5kg", "shoulders");
	AerobicPowerDevice ap = AerobicPowerDevice(303, "meshulav 200", 450, "legs");

	jctGym.addDevice(&a);
	jctGym.addDevice(&p);
	jctGym.addDevice(&ap);

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

	Trainee* p_johndoe = jctGym.getTrainee("john doe");
	p_johndoe->addExercise(&ex, "03 07 2018");
	p_johndoe->addExercise(&exp, "03 07 2018");
	p_johndoe->addExercise(&expa, "03 07 2018");

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
