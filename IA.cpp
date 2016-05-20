#include "IA.h"
#include <iostream>

using namespace std;
IA::IA()
{
	bloked=false;
	variacion=0;
}
double IA::cercano(List& lista, double num)
{
	double abajo,arriba;
	for(int i=0; i<lista.length();i++)
	{
		int i_tmp=lista.length()-i-1;
		Node& tmp_abajo=lista.get(i);
		Node& tmp_arriba=lista.get(i_tmp);
		operacion=i;
		if(i==0)
		{
			abajo=tmp_abajo.get();
			arriba=tmp_arriba.get();
			continue;
		}
		if(tmp_abajo.get()==num
		||tmp_arriba.get()==num)
		 return num;
		
		if(tmp_abajo.get()<num && tmp_abajo.get()>abajo)
			abajo=tmp_abajo.get();
				
		if(tmp_arriba.get()>num && tmp_arriba.get()<arriba)
			arriba=tmp_arriba.get();
			
	}
	if(num-abajo<arriba-num)
	{	return abajo;	}
	else
	{ operacion=lista.length()-operacion-1;	return arriba;	}
}
double IA::opera(int& op,double& a,double& b)
{
	switch(op)
		{
		 case 0://suma
			return 1;
         case 1://resta
			return -1;
         case 2://multiplicacion
			return((a*b)-a)/b;
         case 3://division
			return ((a/b)-a)/b;
         case 4://incremento constante (razon de cambio costante)
			incremento=(2*(b-a)/b);return incremento;
         case 5://incremento variante (razon de cambio variate)
			int op_t=4;double b_t=2*(b-a)/b;
			return opera(op_t,incremento,b_t); ///en desarrollo
		}
	return 1.0;	
}
List& IA::operaciones(double& a,double &b)
{
	List* out= new List();
	
	for(int i=0;i<5;i++)
	{
		double operation = opera(i,a,b);            
        double t=a+(operation*b);
		out->add(new Node(t));
	}
	return *out;
}
void IA::cotejar(double &t)
{
	if(t-decision!=0)
	variacion=t-decision;
}

double IA::decidir(double& a, double& b, double& c)
{
	List& lista =operaciones(a,b);
	cercano(lista,c);
	//descision=b+(opera(operacion,b,c)*c)+variacion;
	decision=b+(opera(operacion,b,c)*c);
	return decision;
}

double & IA::verDecision()
{
	return decision;
}
