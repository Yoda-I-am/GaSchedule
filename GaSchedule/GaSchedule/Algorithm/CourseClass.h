#include <list>
#include "Professor.h"
#include "StudentsGroup.h"
#include "Course.h"

#pragma once

using namespace std;

// Stores data about single class
class CourseClass
{

private:

	// Profesor who teaches
	Professor* professor;

	// Course to which class belongs
	Course* coursec;

	// Student groups who attend class
	list<StudentsGroup*> group6;

	// Number of seats (students) required in room
	int noOFSeats;

	// Initicates wheather class requires computers
	bool isLabRequired;

	// Duration of class in hours
	int duration;
	
public:

	// Initializes class object
	CourseClass(Professor* professor, Course* course, const list<StudentsGroup*>& groups,
		bool requiresLab, int duration);

	// Frees used memory
	~CourseClass();

	// Returns TRUE if another class has one or overlapping student groups.
	bool GroupsOverlap(const CourseClass& c ) const;

	// Returns TRUE if another class has same professor.
	inline bool ProfessorOverlaps(const CourseClass& c ) const { return *professor == *c.professor; }

	// Return pointer to professor who teaches
	inline const Professor& GetProfessor() const { return *professor; }

	// Return pointer to course to which class belongs
	inline const Course& GetCourse() const { return *coursec; }

	// Returns reference to list of student groups who attend class
	inline const list<StudentsGroup*>& GetGroups() const { return group6; }

	// Returns number of seats (students) required in room
	inline int GetNumberOfSeats() const { return noOFSeats; }

	// Returns TRUE if class requires computers in room.
	inline bool IsLabRequired() const { return isLabRequired; }

	// Returns duration of class in hours
	inline int GetDuration() const { return duration; }

};
