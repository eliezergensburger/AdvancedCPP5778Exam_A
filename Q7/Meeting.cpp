#pragma once
#include <iostream>
#include <string>
#include "Person.cpp"
#include "Attendee.cpp"
using namespace std;

class Meeting
{
	Person initiator;
	Attendee** attendees;
	string roomName;
	int maxCapacity;
	int minParticipants;
	int n; // size of attendees
public:
	Meeting(Person initiator, string room, int max, int min)
		: initiator(initiator), roomName(room), maxCapacity(max), minParticipants(min),n(0) {}
	bool valid()
	{
		return (n >= minParticipants);
	}
	~Meeting() { if (n) delete[] attendees; }
	
	bool isRegistered(Attendee & att)
	{
		for (int i = 0; i < n; i++)
		{
			if (attendees[i] == &att)
			{
				return true;
			}
		}
		return false;
	}

	bool addAttendee(Attendee & att)
	{
		if (isRegistered(att))
		{
			return false;
		}
		Attendee** temp;
		if (n < maxCapacity)
		{
			temp = new Attendee*[n + 1];
			for (int i = 0; i < n; i++)
			{
				temp[i] = attendees[i];
			}
			att.set_nochechut('T');
			temp[n] = &att;
			
			delete[] attendees;
			attendees = temp;
			
			n++;
			if (n >= minParticipants)
			{
				for (int i = 0; i < n; i++)
				{
					(*attendees[i]).set_nochechut('A');
				}
			}
			return true;
		}
		//else
		att.set_nochechut('D');
		return false;
	}
};