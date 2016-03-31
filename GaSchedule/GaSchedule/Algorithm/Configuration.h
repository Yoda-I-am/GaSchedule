#include <list>
#include <hash_map>
#include <fstream>
#include <string>

#pragma once

using namespace std;
using namespace stdext;

class Professor;
class StudentsGroup;
class Course;
class Room;
class CourseClass;

// Reads configration file and stores parsed objects
class Configuration
{

private:

	// Global instance
	static Configuration instance;

public:

	// Returns reference to global instance
	inline static Configuration& GetInstance() { return instance; }

private:

	// Parsed professors
	hash_map<int, Professor*> professorsObject;

	// Parsed student groups
	hash_map<int, StudentsGroup*> studentGroupsObjects;

	// Parsed courses
	hash_map<int, Course*> courseObjects;

	// Parsed rooms
	hash_map<int, Room*> roomObjects;

	// Parsed classes
	list<CourseClass*> courseClassesObject;

	// Inidicate that configuration is not prsed yet
	bool _isEmpty;

public:

	// Initialize data
	Configuration() : _isEmpty(true) { }

	// Frees used resources
	~Configuration();

	// Parse file and store parsed object
	void ParseFile(char* fileName);

	// Returns pointer to professor with specified ID
	// If there is no professor with such ID method returns NULL
	inline Professor* GetProfessorById(int id)
	{ 
		hash_map<int, Professor*>::iterator it = professorsObject.find( id );
		return it != professorsObject.end() ? ( *it ).second : NULL;
	}

	// Returns number of parsed professors
	inline int GetNumberOfProfessors() const { return (int)professorsObject.size(); }

	// Returns pointer to student group with specified ID
	// If there is no student group with such ID method returns NULL
	inline StudentsGroup* GetStudentsGroupById(int id)
	{ 
		hash_map<int, StudentsGroup*>::iterator it = studentGroupsObjects.find( id );
		return it != studentGroupsObjects.end() ? ( *it ).second : NULL;
	}

	// Returns number of parsed student groups
	inline int GetNumberOfStudentGroups() const { return (int)studentGroupsObjects.size(); }

	// Returns pointer to course with specified ID
	// If there is no course with such ID method returns NULL
	inline Course* GetCourseById(int id)
	{ 
		hash_map<int, Course*>::iterator it = courseObjects.find( id );
		return it != courseObjects.end() ? ( *it ).second : NULL;
	}

	inline int GetNumberOfCourses() const { return (int)courseObjects.size(); }

	// Returns pointer to room with specified ID
	// If there is no room with such ID method returns NULL
	inline Room* GetRoomById(int id)
	{ 
		hash_map<int, Room*>::iterator it = roomObjects.find( id );
		return it != roomObjects.end() ? ( *it ).second : NULL;
	}

	// Returns number of parsed rooms
	inline int GetNumberOfRooms() const { return (int)roomObjects.size(); }

	// Returns reference to list of parsed classes
	inline const list<CourseClass*>& GetCourseClasses() const { return courseClassesObject; }

	// Returns number of parsed classes
	inline int GetNumberOfCourseClasses() const { return (int)courseClassesObject.size(); }

	// Returns TRUE if configuration is not parsed yet
	inline bool IsEmpty() const { return _isEmpty; }

private:

	// Reads professor's data from config file, makes object and returns pointer to it
	// Returns NULL if method cannot parse configuration data
	Professor* ParseProfessor(ifstream& file);

	// Reads professor's data from config file, makes object and returns pointer to it
	// Returns NULL if method cannot parse configuration data
	StudentsGroup* ParseStudentsGroup(ifstream& file);

	// Reads course's data from config file, makes object and returns pointer to it
	// Returns NULL if method cannot parse configuration data
	Course* ParseCourse(ifstream& file);

	// Reads rooms's data from config file, makes object and returns pointer to it
	// Returns NULL if method cannot parse configuration data
	Room* ParseRoom(ifstream& file);

	// Reads class' data from config file, makes object and returns pointer to it
	// Returns NULL if method cannot parse configuration data
	CourseClass* ParseCourseClass(ifstream& file);

	// Reads one line (key - value pair) from configuration file
	bool GetConfigBlockLine(ifstream& file, string& key, string& value);

	// Removes blank characters from beginning and end of string
	string& TrimString(string& str);

};
