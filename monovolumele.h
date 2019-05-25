#ifndef MONOVOLUMELE_H
#define MONOVOLUMELE_H
#include <iostream>
#include <string.h>
#include <typeinfo>
#include <list>
#include <iterator>
#include <vector>
#include <queue>
#ifndef AUTOTURISM_H
#include "autoturism.h"
#endif
class MONOVOLUMELE:public autoturism
{
	public:
	MONOVOLUMELE(float x=4,unsigned y=5):autoturism(x,y){set_van();}
	MONOVOLUMELE(MONOVOLUMELE &x){set_lungime(x.get_lungime());set_nr_persoane(x.get_nr_persoane());if(x.get_mic_litraj())set_mic_litraj();if(x.get_masina_de_oras())set_masina_de_oras(); if(x.get_masina_usor_de_folosit())set_masina_usor_de_folosit();if(x.get_van())set_van();}
	~MONOVOLUMELE(){};
	void citire(){int x,y;std::cin>>x>>y; set_lungime(x); set_nr_persoane(y);}
	void afisare(){std::cout<<"Masina monovolum\nLungime: "<<get_lungime()<<" cu nr persoane:"<<get_nr_persoane()<<"\n";}
	friend std::istream& operator >>(std::istream &in, MONOVOLUMELE &X){ X.citire();return in;}
	friend std::ostream& operator <<(std::ostream &out, MONOVOLUMELE &X){ X.afisare();return out;}
	friend std::ostream& operator <<(std::ostream &out, MONOVOLUMELE *X){ X->afisare();return out;}
	MONOVOLUMELE& operator=(MONOVOLUMELE& ob)
	{
		if((*this).get_lungime()!=ob.get_lungime()||(*this).get_nr_persoane()!=ob.get_nr_persoane())
			{set_lungime(ob.get_lungime());set_nr_persoane(ob.get_nr_persoane());}
		return *this;
	}
};

#endif