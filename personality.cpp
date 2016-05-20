#include "Personality.h"
Personality::Personality(double& universe)
{
 for(double i=0;i<universe;i++)
  { 
	 double t=1;
     personality.add(new Node(t));
     estate.add(new Node(t));
     proyection.add(new Node(t));
     imagination.add(new Node(t));
  }	
}

void Personality::setEstate(List& data)
{
	 if(estate.length()==0)
        {estate=data;}
        
        List tmp = List();
        for(double i=0;i<data.length();i++)
        {
            tmp.add(new Node(afectation));
        }
        
        //calcular estado,deacuerdo con la entrada (data), la personalidad y el estado anterior
        data=List::operate('-', data, estate);
        estate=List::operate('+', tmp, data);
        int i=0;
        List mergue=List(&estate.get(i));
        //mergue.add(personalidad);
        //estado=IA.promedio(mergue);
        
        personality=List::operate('-', tmp, personality);
        personality=List::operate('+', estate, personality);
}
