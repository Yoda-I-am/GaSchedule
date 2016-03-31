

#include "stdafx.h"
#include "StudentsGroup.h"

// Initializes student group data
StudentsGroup::StudentsGroup(int id, const string& name, int numberOfStudents) : _id(id),
																				 _name(name),
																				 numberOfStudents(numberOfStudents)
{
}

// Bind group to class
void StudentsGroup::AddClass(CourseClass* courseClass)
{
	courseClassesObject.push_back( courseClass );
}
