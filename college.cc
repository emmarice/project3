//	college.cc
//	Emma Rice
//	3/1/2020
//	Implementation of college class

#include "college.h"
#include "course.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>

//adds a course object given in argument to the linked list, inserting it 
//according to an alphabetical order imposed by the list
void College::add(course c)
{
	if (head==NULL)
	{
		head = new node(c);
	}
	else
	{
		node * cursor = head;
		node * prev = head;
		while(cursor->link()!=NULL && cursor->data() < c)
		{
			prev = cursor;
			cursor = cursor->link();
		}
		if (cursor->link()==NULL)
		{
			cursor->set_link(new node(c));
		}
		else 
		{
			prev->set_link(new node(c));
			prev = prev->link();
			prev->set_link(cursor);

		}
	}
}

//passes all courses in list to an ostream that is given by argument
void College::display(std::ostream& outs)
{
	//display all courses to stream
	if(head == NULL){outs << "No courses listed.\n"; return;}
	node * cursor = head;
	while(cursor != NULL)
	{
		outs << cursor->data();
		cursor = cursor->link();
	}
}

//removes a course specified by course name in argument
//by searching through the list and comparing course names
//then linking the previous and next courses together
void College::remove(std::string targ)
{
	if(head == NULL)
	{
		return;
	}
	if(head->data().get_course_number() == targ)
	{
		head = head->link();
		return;
	}
	node* prev = head;
	node* cursor = head->link();
	while (cursor!=NULL)
    {
    	if(cursor->data().get_course_number() == targ)
      	{
		    prev->set_link(cursor->link());
		    delete cursor;
		    return;
      	}
		else
		{
		    prev = cursor;
		    cursor = cursor->link();
		}
	}
}

//sets name of student
void College::set_name(std::string name)
{
	fullname = name;
}

//returns total hours taken
int College::hours()
{
	//return the total hours taken
	node * cursor = head;
	int hrs = 0;
	while(cursor != NULL)
	{
		hrs+= cursor->data().get_hours();
		cursor = cursor->link();
	}
	return hrs;
}

//calculates and returns gpa
double College::gpa()
{
	node * cursor = head;
	int totalhrs = 0;
	double points = 0;
	while(cursor != NULL)
	{
		points += cursor->data().get_number_grade()*cursor->data().get_hours();
		totalhrs+= cursor->data().get_hours();
		cursor = cursor->link();
	}
	return (points/totalhrs);
}

//populated the college object with courses obtained from istream such as a file. student name should be given at top.
void College::load(std::istream& ins)
{
	//load the student’s name (which will be the first thing 
	//in the file) and list of courses when it starts up
	head = new node;
	node* cursor = head;
	course c;
	while(ins.peek()=='\n')ins.ignore();
    getline(ins,fullname);
    ins >> c;
    cursor->set_data(c);
    ins >> c;
    while(!ins.eof())
    {
    	cursor->set_link(new node);
    	cursor = cursor->link();
    	cursor->set_data(c);
    	ins >> c;
    }
    cursor->set_link(NULL);
}

//saves the name of student and contents of the list to an ostream
void College::save(std::ostream& outs)
{
	outs << fullname << std::endl;
	node* cursor = head;
	while(cursor!=NULL)
    {
    	outs << cursor->data();
    	cursor = cursor->link();
    }
}

//default destructor
College::~College()
{
	node* cursor = head->link();
	while(cursor != NULL)
	{
		delete head;
		head = cursor;
		cursor = cursor->link();
	}
	delete head;
}

//copy constructor
College::College(const College& other)
{
	fullname = other.fullname;
	head = new node;
	node* cursor = head;
	node* otherh = other.head;
	if(otherh == NULL)
	{
		cursor->set_data(otherh->data());
		cursor->set_link(NULL);
		return;
	}
	else
	{
		cursor->set_data(otherh->data());
	    otherh = otherh->link();
		while(otherh!=NULL)
	    {
	    	cursor->set_link(new node);
	    	cursor = cursor->link();
	    	cursor->set_data(otherh->data());
			otherh=otherh->link();
	    }//while
	    cursor->set_link(NULL);
	}//else
}

//assignment operator
void College::operator =(const College& other)
{
	if(this == &other)
	{
		return;
	}
	node* cursor = head->link();
	while(cursor != NULL)
	{
		delete head;
		head = cursor;
		cursor = cursor->link();
	}
	delete head;

	fullname = other.fullname;
	node* otherh = other.head;
	if(otherh == NULL)
	{
		cursor->set_data(otherh->data());
		cursor->set_link(NULL);
		return;
	}
	else
	{
		cursor->set_data(otherh->data());
	    otherh = otherh->link();
		while(otherh!=NULL)
	    {
	    	cursor->set_link(new node);
	    	cursor = cursor->link();
	    	cursor->set_data(otherh->data());
			otherh=otherh->link();
	    }//while
	    cursor->set_link(NULL);
	}//else
}
