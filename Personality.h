#ifndef PERSONALITY_H
#define PERSONALITY_H
#include "List.h"

class Personality
{
	private:
		List estate;
		List personality;
		List imagination;
		List proyection;
		double afectation;
		
	public:
		Personality(double&);
		~Personality();
		void setEstate(List&);
		void imagine(List *);
		void calculateProyection(List *);
		void changePersonality();
		double getAfectation(){return afectation;}
		double sentation();
		
};
#endif
