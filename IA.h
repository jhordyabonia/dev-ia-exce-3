#ifndef PERSONALITY_H
#define PERSONALITY_H
//#include <thread>  
#include "List.h"

class IA
{
	private:
		bool bloked;
		int operacion;
		double decision;
		double variacion;
		double incremento; //incremental constante.
		
	public:
		IA();
		int& verOperacion(){return operacion;};	
		double & verDecision();
		double & verIncremento(){return incremento;};
		double cercano(List&, double num);
		double opera(int&,double&,double&);
		List& operaciones(double& ,double &);
		double decidir(double&, double&, double&);
		void cotejar(double&);
		void setBloked(bool b){bloked=b;};
		bool getBloked(){ return bloked;}
		
};
#endif
