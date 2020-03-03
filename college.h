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
		//default constructor
		College(){head = NULL; fullname = "N/A";}
		//big three
		//default destructor
		~College();
		//copy constructor
		College(const College& other);
		//assignment operator
		void operator =(const College& other);
		
		//the rest
		//adds a course object given in argument to the linked list, inserting it 
		//according to an alphabetical order imposed by the list
		void add(course c);
		//passes all courses in list to an ostream that is given by argument
		void display(std::ostream& outs);
		//removes a course specified by course name in argument
		//by searching through the list and comparing course names
		//then linking the previous and next courses together
		void remove(std::string targ);
		//sets fullname by string given in argument
		void set_name(std::string name);
		//returns total number of hours from all courses in list
		int hours();
		//calculates and returns gpa
		double gpa();
		//populates the college object with courses obtained from istream such as a file. student name should be given at top.
		void load(std::istream& ins);
		//saves the name of student and contents of the list to an ostream given by argument
		void save(std::ostream& outs);
	private:
		node* head;
		std::string fullname;
};

#endif
