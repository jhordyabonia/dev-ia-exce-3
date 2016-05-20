#include "List.h"

List:: List(Node* in)
{
	head=in;
	setSize();
	
}
void List::setSize()
{	
	Node* current=head;
	size=0;
	while(current!=0)
	{
			size++;
			current=current->next();
	}
}

List:: List()
{
	size=0;
	head=0;
}

Node& List::get(int& position)
{
	if(position<=0)
	return *head;
	
	Node* current=head;
	for(int i=0;i<position&&current!=0;i++)
	{
		current=current->next();
	}
	return *current;
}

Node& List::operator[](int& position)
{
	if(position<=0)
	return *head;
	
	Node* current=head;
	for(int i=0;i<position&&current!=0;i++)
	{
		current=current->next();
	}
	return *current;
}
void List::add(Node* in)
{
	in->changeNext(head);
	head=in;
	size++;
}
List & List::comparate(List & a,List & b)
{	
    double out=(a.length()-b.length())*100; 
    double suma_a=0, suma_b=0,suma_diferencia=0;        
    return List::operate('-',a,b);;
    //return decision;
    /*
    for(double i:diferencia)
    { suma_diferencia+=i;}
    for(double i:a)
    { suma_a+=i;}
    for(double i:b)
    { suma_b+=i;}
    double mayor_suma=suma_a;
    if(suma_a<suma_b)
    {mayor_suma=suma_b;}
        
     out=(suma_diferencia*100/mayor_suma);        
       
     return out;
     * */
 }
List & List::operate(const char& o,List &a, List& b)
{	
        while(a.length()<b.length())
        {
            a.add(0);
        }
        while(a.length()>b.length())
        {
            b.add(0);
        }
        
        List *out=new List();
        double operation = 1;
        int i;
        for(i=0; i<a.length();i++)
        {
            double a_tmp=a.get(i).get();
            double b_tmp=b.get(i).get();
                    
            if(o=='-')
            {operation= -1;}
            else if(o=='*')
            {operation=((a_tmp*b_tmp)-a_tmp)/b_tmp;}
            else if(o=='/')
            {operation=((a_tmp/b_tmp)-a_tmp)/b_tmp;}
            
            double t=a_tmp+(operation*b_tmp);
            out->add(new Node(t));
        }
        
        for(i; i<b.length();i++)
        {
            double b_tmp=b.get(i).get();            
            out->add(new Node(b_tmp));
        }
        
        
        return *out;
}


List::~List()
{
	/*while(size>=0);
	{
		size-=1;
		Node* current=this->get(size);
		if(current!=0)
			delete current;
	}*/
	if(head!=0)
		delete head;
	head=0;
}
