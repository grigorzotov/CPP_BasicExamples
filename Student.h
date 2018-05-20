#ifndef _STUDENT_H
#define _STUDENT_H

const int NAME_MAX_LEN = 31;

class Student{
private:
	static int population;

	int _fn;
	char *_ptrName;
	char _name[NAME_MAX_LEN];

public:
	Student();
	Student(int,const char*);
	Student(const Student&);
	Student& operator=(const Student&);
	~Student();

	int getFn() const;
	const char* getName() const;

	void setFn(int);
	void setName(const char*);

	static int getPopulation(){
		return population;
	}
};


#endif //_STUDENT_H