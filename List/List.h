#pragma once
#include <vector>
#include <iostream>
#include "Point.h"

class List
{
	size_t size;
	struct Node
	{
		Point point;
		Node* next;
		Node(const Point& p) : point(p.x, p.y, p.z), next(nullptr) {}
	};
	Node* first;

	Node* find(const size_t); //search pointer on indicated list element
	void push(const Point&, const size_t); //insert element in indicated place in list
	void push(const List&, const size_t);
	void pop(const size_t); //removing indicated element of list
	/////////////////////////
	List multiply(int multiply); //multiply list

public:
	List();
	List(const List&);
	~List(); //stop memory leak, remove list object

	//enum which describe error code
	enum class Error 
	{
		SUCCESS,
		LIST_EMPTY,
		OUT_OF_BOUNDS
	};
	Error pop_front();	//remove first element
	size_t getSize();	//get number of elements
	List operator+(const List&); //concatenate two linked lists 
	List& operator+=(const List&); //concatenate two linked lists 
	List& operator=(const List&); //copy elements from one list to another (deep copy)
	List operator--(int); //remove last list element
	/////////////////////////
	List(std::vector<Point>&); //inicialize list with vector of points
	List operator*(unsigned int number); //multiply linked list
	Point& operator[](unsigned int number); //get reference of point searching after arguments
	List operator++(int); //remove all list
	friend std::ostream& operator<<(std::ostream& os, List& list); //show list
	/////////////////////////
	List::Error pop_back(); //remove last element
	List::Error push_back(const Point&); //insert element on the end of list
	Point& find(Point&, const std::size_t); //looking for element after number of element and return it with reference
	List::Error insert(const Point&, const std::size_t); //insert element in appropriate place in list
};

std::ostream& operator<<(std::ostream& os, List& list);

