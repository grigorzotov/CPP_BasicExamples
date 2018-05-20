#include "Student.h"
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;


int Student::population = 0;

Student::Student() : _fn(0), _ptrName(NULL){
	population++;

	strcpy_s(_name, "testName");
	
	_ptrName = new char[NAME_MAX_LEN];
	assert(_ptrName);
	strcpy(_ptrName, "testNamePointer");
}

Student::Student(int fn,const char* namePtr){
	population++;

	this->_fn = fn;

	assert(namePtr);
	setName(namePtr);

	this->_ptrName = new char[strlen(namePtr) + 1];
	strcpy(_ptrName, "testNamePointer");
}

Student::Student(const Student& other){
	population++;

	_ptrName = new char[strlen(other._ptrName) + 1];
	strcpy(this->_ptrName, other._ptrName);
	strcpy(this->_name, other._name); 
}

Student& Student::operator=(const Student& other){
	if (this != &other){
		delete[] _ptrName;
		_ptrName = new char[strlen(other._ptrName) + 1];
		strcpy(this->_ptrName, other._ptrName);

		strcpy(_name, other._name);
		this->_fn = other._fn;
	}
	return *this;
}

Student::~Student(){
	delete[] _ptrName;
	_ptrName = NULL;
}

int
Student::getFn() const
{
	return _fn;
}

const char*
Student::getName() const
{
	return _name;
}

void
Student::setFn(int fn)
{
	_fn = fn;
}

void
Student::setName(const char* name)
{
	assert(name);
	assert(strlen(name) < NAME_MAX_LEN);

	strcpy(_name, name);
}

//For pointer
/*
void Student::setName(const char* name){
	assert(name);
	delete[] _ptrName;
	_ptrName = new char[strlen(name) + 1];
	strcpy(_ptrName, name); 
}
*/