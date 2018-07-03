#include <iostream>
#include <string>
#include "Person.cpp"
#include "Attendee.cpp"
#include "Meeting.cpp"
using namespace std;

int Person::idGenerator = 1000;

int main()
{
	Person initiator("shlomo");
	Attendee one("one");
	Attendee two("two");
	Attendee three("three");
	Attendee four("four");

	Meeting meeting(initiator,"auditorium",3,3);

	meeting.addAttendee(one);
	cout << "nochechut one " << one.get_nochechut() << endl;

	meeting.addAttendee(two);
	cout << "after two" << ((meeting.valid()) ? "mitkayem" : "lo mitkayem") << endl;
	cout << "nochechut two " << two.get_nochechut() << endl;

	meeting.addAttendee(three);
	cout << "after three" <<((meeting.valid()) ? "mitkayem" : "lo mitkayem") << endl;
	cout << "nochechut three " << three.get_nochechut() << endl;

	meeting.addAttendee(four);
	cout << "mochechut for all:" << endl;
	cout << one.get_nochechut()<<endl;
	cout << two.get_nochechut() << endl;
	cout << three.get_nochechut() << endl;
	cout << four.get_nochechut() << endl;
	system("pause");
	return 0;
}