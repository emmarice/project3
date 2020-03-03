//college.cc
//Emma Rice
//3/1/2020
#include "college.h"
#include "course.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>


void College::add(course c)
{
	if (head==NULL)
	{
		head = new node(c);
	}
	else //ADD ALPHABETICAL ORDER STUFF
	{
		node * cursor = head;
		node * prev = head;
		while(cursor->link()!=NULL && cursor->data() > c)
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
			prev->set_link(new node(c)); //make sure this works!
			prev = prev->link();
			prev->set_link(cursor);

		}
	}
}

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

void College::set_name(std::string name)
{
	fullname = name;
}

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

void College::load(std::istream& ins)
{
	//load the student’s name (which will be the first thing 
	//in the file) and list of courses when it starts up
	head = new node;
	node* cursor = head;
	node* prev;
	course c;
	while(ins.peek()=='\n')ins.ignore();
    getline(ins,fullname);
    while(!ins.eof())
    {
    	ins >> c;
    	cursor->set_data(c);
    	cursor->set_link(new node);
    	prev = cursor;
    	cursor = cursor->link();
    }
    prev->set_link(NULL);
}

void College::save(std::ostream& outs)
{
	//save the altered list to the same file when it is exiting
	outs << fullname << endl;
	node* cursor = head;
	while(cursor!=NULL)
    {
    	outs << cursor->data();
    	cursor = cursor->link();
    }
}

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
College::College(const College& other)
{
	fullname = other.fullname;
	node* cursor = head;
	if(other.head == NULL)
	{
		head = NULL;
		return;
	}
	else
	{
		while(other.head!=NULL)
	    {
	    	cursor->set_data(other.head->data());
	    	other.head->set_link(other.head->link());
	    	if(other.head== NULL)
	    	{
	    		cursor->set_link(NULL);
	    		return;
	    	}
	    	cursor->set_link(new node);
	    	cursor = cursor->link();
	    }//while
	}//else
}
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
	if(other.head == NULL)
	{
		head = NULL;
		return;
	}
	else
	{
		head = new node;
		node* cursor = head;
		while(other.head!=NULL)
	    {
	    	cursor->set_data(other.head->data());
	    	other.head->set_link(other.head->link());
	    	if(other.head== NULL)
	    	{
	    		cursor->set_link(NULL);
	    		return;
	    	}
	    	cursor->set_link(new node);
	    	cursor = cursor->link();
	    }//while
	}//else
}
