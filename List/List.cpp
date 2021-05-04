#include "List.h"

List::Node* List::find(const size_t idx)
{
	Node* node = first;

	for (size_t i = 0; i < idx; i++)
	{
		node = node->next;
	}

	return node;
}

void List::push(const Point& point, const size_t idx)
{
	if (idx == 0)
	{
		Node* tail = first;
		first = new Node(point);
		first->next = tail;
	}
	else
	{
		Node* prev = find(idx - 1);
		Node* tail = prev->next;
		prev->next = new Node(point);
		prev->next->next = tail;
	}
	size++;
}

void List::push(const List& list, const size_t idx)
{
	List copy(list);
	Node* it = copy.first;
	if (idx == 0)
	{
		Node* tail = first;
		Node* last = nullptr;
		if (it)
		{
			first = new Node(it->point);
			last = first;
			it = it->next;
		}
		while (it)
		{
			last->next = new Node(it->point);
			last = last->next;
			it = it->next;
		}
		last->next = tail;
	}
	else
	{
		Node* prev = find(idx - 1);
		Node* tail = prev->next;
		while (it)
		{
			prev->next = new Node(it->point);
			prev = prev->next;
			it = it->next;
		}
		prev->next = tail;
	}
	size += list.size;
}

void List::pop(const size_t idx)
{
	if (idx == 0)
	{
		Node* tail = first->next;
		delete first;
		first = tail;
	}
	else
	{
		Node* prev = find(idx - 1);
		Node* tail = prev->next->next;
		delete prev->next;
		prev->next = tail;
	}
	size--;
}

List::List() : size(0), first(nullptr) {}

List::List(const List& list) : size(list.size), first(nullptr)
{
	Node* it = list.first;
	Node* last = first;
	if (it)
	{
		first = new Node(it->point);
		last = first;
		it = it->next;
	}
	while (it)
	{
		last->next = new Node(it->point);
		last = last->next;
		it = it->next;
	}
}

List::~List()
{
	while (first != NULL) 
		pop_front();
}

List::Error List::pop_front()
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else
	{
		pop(0);
	}

	return error;
}

size_t List::getSize()
{
	return size;
}

List List::operator+(const List& list)
{
	List copy(*this);
	copy.push(list, copy.size);
	return copy;
}

List& List::operator+=(const List& list)
{
	push(list, size);
	return *this;
}

List& List::operator=(const List& list)
{
	List copy(list);
	this->~List();
	push(copy, 0);
	return *this;
}

List List::operator--(int)
{
	List copy(*this);
	pop_back();
	return copy;
}

List::List(std::vector<Point>& vec)
{
	for(const Point& x: vec)
		this->push_back(x);
}

List List::operator*(unsigned int number)
{
	List l1;
	for (unsigned int i = 0; i < number; i++)
		l1 += *this;

	return l1;
}

Point& List::operator[](unsigned int number)
{
	if (number > size)
	{
		throw "OUT OF BOUNDS!";
	}
	else if (size == 0)
	{
		throw "EMPTY LIST!";
	}
	else
	{
		Node* n = find(number);

		return n->point;
	}
}

List List::operator++(int)
{
	size_t length = this->size;
	for (size_t i = length; i > 0; i--)
		this->pop(i - 1);

	return *this;
}

List List::multiply(int multiply)
{
	List list = *this;
	for (int i = 0; i < multiply; i++)
		list += *this;

	return list;
}

List::Error List::pop_back()
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error =  List::Error::LIST_EMPTY;
	}
	else
	{
		pop(size - 1);
	}
	return error;
}


List::Error List::push_back(const Point& point)
{
	List::Error error = List::Error::SUCCESS;
	
	push(point, size);

	return error;
}

Point& List::find(Point& point, const std::size_t num)
{
	if (num > size)
	{
		throw "OUT OF BOUNDS!";
	}
	else if (size == 0)
	{
		throw "EMPTY LIST!";
	}
	else
	{
		Point p;
		p = find(num)->point;
		return p;
	}

}

List::Error List::insert(const Point& point, const std::size_t num)
{
	List::Error error = List::Error::SUCCESS;

	if (num > size)
	{
		error = List::Error::OUT_OF_BOUNDS;
	}
	else
	{
		push(point, num);
	}

	return error;
}

std::ostream& operator<<(std::ostream& os, List& list)
{
	auto temp = list.first;
	while (temp)
	{
		os << temp->point.x << " " << temp->point.y << " " << temp->point.z << "\n";
		temp = temp->next;
	}
	return os;
}
