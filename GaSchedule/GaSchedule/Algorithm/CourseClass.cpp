

#include "stdafx.h"
#include "CourseClass.h"

// Initializes class object
CourseClass::CourseClass(Professor* professor, Course* course, const list<StudentsGroup*>& groups,
						 bool requiresLab, int duration) : 
						 professor(professor),
						 coursec(course),
						 noOFSeats(0),
						 isLabRequired(requiresLab),
						 duration(duration)
{
	// bind professor to class
	professor->AddCourseClass( this );

	// bind student groups to class
	for( list<StudentsGroup*>::const_iterator it = groups.begin(); it != groups.end(); it++ )
	{
		( *it )->AddClass( this );
		group6.push_back( *it );
		noOFSeats += ( *it )->GetNumberOfStudents();
	}
}

// Frees used memory
CourseClass::~CourseClass() { }

// Returns TRUE if another class has one or overlapping student groups.
bool CourseClass::GroupsOverlap(const CourseClass& c ) const
{
	for( list<StudentsGroup*>::const_iterator it1 = group6.begin(); it1 != group6.end(); it1++ )
	{
		for( list<StudentsGroup*>::const_iterator it2 = c.group6.begin(); it2 != c.group6.end(); it2++ )
		{
			if( *it1 == *it2 )
				return true;
		}
	}

	return false;
}