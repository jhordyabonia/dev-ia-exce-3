#include <iostream>
#include <thread>  
#include <cmath>
#include "IA.h"       // std::thread
using namespace std;

void print(List& lista)
{
	for(int i=0; i<lista.length();i++)
	cout<<lista.get(i).get()<<endl;
}

double f1(int x){return -x;}
double f2(int x){return (3*x)+3;}
double f3(int x){return 1*(x*x*x)+(3*x)+2;}

void test()
{
	List* listas=new List[5];
	for(int x=10;x>=0;x--)
	{
		double f_1=f1(x);
		double f_2=f2(x);
		double f_3=f3(x);
		/*
		listas[x]= List();
		listas[x].add(new Node(f_1));
		listas[x].add(new Node(f_2));
		listas[x].add(new Node(f_3));
		*/
		
		listas[0].add(new Node(f_3));
	//print(listas[x]);		
	}
	double t[3];
	int cero=0;
	
	List lista =listas[0];
	for(int a=0;a<3;a++)
	{
		//cout<<":::::::::::::::::::::::::::"<<endl;
		//for(int i=0; i<3;i++)
		//{		
			int get = a+3;
			t[a]=lista.get(get).get();				
		//}
	}
	IA exce=IA();
	/*
	List& lista_operaciones =exce.operaciones(t[0],t[1]);
	print(lista);
	cout<<":::::::::::::::::::::::"<<endl;
	print(lista_operaciones);
	*/
	cout<<"A: "<<t[0]<<" B: "<<t[1]<<" C: "<<t[2]<<endl;
	//cout<<" Cercano: "<<exce.cercano(lista_operaciones,t[2])<<" Operacion: "<<exce.verOperacion()<<endl;
	cout<<"Decicion: "<<exce.decidir(t[0],t[1],t[2])<<" Operacion: "<<exce.verOperacion()<<endl;
	//for(int a=2;a<5;a++)
	//{
	//	List& lista =operaciones(t[0][a],t[1][a]);
		//print(lista);
	//	cout<<"A: "<<t[0][a]<<" B: "<<t[1][a]<<" C: "<<t[2][a]<<" Cercano "<<cercano(lista,t[2][a])<<endl;
	
	//}
}
void test_iterativo()
{
	double a,b,c,cotejar;
	string repet;
	IA exce=IA();
	do{
			
		std::cout<<"A: ";
		cin>>a;
		cout<<"B: ";
		cin>>b;
		cout<<"C: ";
		cin>>c;
		cout<<"A: "<<a<<" B: "<<b<<" C: "<<c<<endl;
		cout<<"Decicion: "<<exce.decidir(a,b,c)<<" Operacion: "<<exce.verOperacion()<<endl;
		cout<<"Cotejar: ";
		cin>>cotejar;
		exce.cotejar(cotejar);
		cout<<"Continuar? ";
		cin>>repet;
	}while(repet=="y");
}
IA exce=IA();

void pensar()
{
	int t=0;
	double a=49,b=64,c=81,decision;
	while(true)
	{
		if(t>100&&!exce.getBloked())
		{
			exce.setBloked(true);
			decision=exce.decidir(a,b,c);
			a=b;b=c;c=decision;
			exce.setBloked(false);
			t=0;
		}
		t++;
	}
}
void test_hilo()
{
	int t;
	while(true)
	{
		if(t>100000000&&!exce.getBloked())
		{
			exce.setBloked(true);
			cout<<exce.verDecision()<<" ";
			exce.setBloked(false);
			t=0;
		}
		t++;
	}
}

int main()
{
	/*	
	List miList;
	List oList;
	for(double i=0;i<5;i++)
	{
		double in=i*2;
		miList.add(new Node(in));
	}
	for(double i=5;i>0;i--)
	{
		double in=i*5;
		oList.add(new Node(in));
	}
	List suma=List::operate('-',oList,miList);
	print(suma);
	cout<<"Size list: "<<miList.length()<<endl;
	for(double i=0; i<miList.length();i++)
	{
		double in=i*3;
		cout<<"Cercano "<<cercano(miList,i)<<endl;
	}
	
	
	
	for(double a=1;a<10;a++)
	{
		double b=a*3,c=a*2;		
		List& lista =operaciones(c,a);
		print(lista);
		cout<<"A: "<<a<<" B: "<<b<<" C: "<<c<<" Cercano "<<cercano(lista,b)<<endl;
	}
	*/
	//test();
	//test_iterativo();
	thread first (pensar);     // spawn new thread that calls foo()
	thread second (test_hilo);  // spawn new thread that calls bar(0)

	cout << "main, foo and bar now execute concurrently...\n";

	  // synchronize threads:
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes

	cout << "foo and bar completed.\n";
	
	return 0;
}
