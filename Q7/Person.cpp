#pragma once
#include <string>
using namespace std;

class Person
{
	static int idGenerator;
protected:
	int id;
	string name;
public:
	Person(string name)
	{
		this->name = name;
		this->id = idGenerator++;
	}
	Person() {}
	//getters & setters
	void set_Name(string name) { this->name = name; }
	string get_Name() const{ return name; }

};
