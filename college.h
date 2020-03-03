// college.h
//Emma Rice
//3/1/2020

#include "Node.h"
#include "course.h"
#include <iostream>
#include <fstream>
#include <string>
#ifndef COLLEGE_H
#define COLLEGE_H
class College
{
	public:
		College(){head = NULL;}
		//big three
		~College();
		College(const College& other);
		void operator =(const College& other);
		//the rest
		void add(course c);
		void display(std::ostream& outs);
		void remove(std::string targ);
		void set_name(std::string name);
		int hours();
		double gpa();
		void load(std::istream& ins);
		void save(std::ostream& outs);
	private:
		node* head;
		std::string fullname;
};

#endif