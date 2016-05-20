#ifndef NODE_H
#define NODE_H

class Node
{
	private:
		Node *follow;
		double data;
	public:
		Node(double&,Node* =0);
		~Node();
		double get();
		Node * next();
		void changeNext(Node *);
		void changeData(Node *);
		
};
#endif
