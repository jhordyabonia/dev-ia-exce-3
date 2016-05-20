#ifndef LIST_H
#define LIST_H
#include "Node.h"
class List
{
	private:
		double size;
		Node * head;
		void setSize();
	public:
		List(Node*);
		List();
		~List();
		Node& operator[](int&);
		Node& get(int&);
		void add(Node*);
		static List& operate(const char&,List&,List&);
		static List& comparate(List&,List&);
		double length(){return size;}
		
};
#endif
