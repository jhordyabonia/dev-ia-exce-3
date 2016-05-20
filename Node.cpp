#include "Node.h"
Node::Node(double& data,Node* next)
{
		this->follow=next;
		this->data=data;
}
		
Node::~Node()
{
	if(follow!=0)
		delete follow;
		
	if(data!=0)
		//delete dato;
		data = 0;
}

double Node::get()
{
	return data;
}

Node * Node::next()
{
	return follow;
}

void Node::changeNext(Node * next)
{
	this->follow = next;		
}

void Node::changeData(Node * next)
{
	this->follow = next;		
}
