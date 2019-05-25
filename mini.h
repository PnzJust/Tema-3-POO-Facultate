#ifndef MINI_H
#define MINI_H
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
class MINI:public autoturism
{
	public:
	MINI(float x=3.5,unsigned y=4):autoturism(x,y){set_mic_litraj();}
	MINI(MINI &x){set_lungime(x.get_lungime());set_nr_persoane(x.get_nr_persoane());if(x.get_mic_litraj())set_mic_litraj();if(x.get_masina_de_oras())set_masina_de_oras(); if(x.get_masina_usor_de_folosit())set_masina_usor_de_folosit();if(x.get_van())set_van();}
	~MINI(){};
	virtual void citire(){int x,y;std::cin>>x>>y; set_lungime(x); set_nr_persoane(y);}
	virtual void afisare(){std::cout<<"Masina mini\nLungime: "<<get_lungime()<<" cu nr persoane:"<<get_nr_persoane()<<"\n";}
	friend std::istream& operator >>(std::istream &in, MINI &X){ X.citire();return in;}
	friend std::ostream& operator <<(std::ostream &out, MINI &X){ X.afisare();return out;}
	friend std::ostream& operator <<(std::ostream &out, MINI *X){ X->afisare();return out;}
	MINI& operator=(MINI& ob)
	{
		if((*this).get_lungime()!=ob.get_lungime()||(*this).get_nr_persoane()!=ob.get_nr_persoane())
			{set_lungime(ob.get_lungime());set_nr_persoane(ob.get_nr_persoane());}
		return *this;
	}
};
#endif