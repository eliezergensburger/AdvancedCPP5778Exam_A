#pragma once
//#include <string>
#include "Person.cpp"

class Attendee : public Person
{
	char nochechut; // A D T
public:
	Attendee(string  myname) : Person(myname), nochechut('?') {}
	void set_nochechut(char w) { nochechut = w; }
	char get_nochechut() const { return nochechut; }
};