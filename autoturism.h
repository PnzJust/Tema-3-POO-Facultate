#ifndef AUTOTURISM_H
#define AUTOTURISM_H
#include <iostream>
#include <string.h>
#include <typeinfo>
#include <list>
#include <iterator>
#include <vector>
#include <queue>
class autoturism{
	float lungime;
	unsigned nr_persoane_transportate;
	bool mic_litraj=0;
	bool masina_de_oras=0;
	bool masina_usor_de_folosit=0;
	bool van=0;
	public:
	autoturism(float x=3.5,unsigned y=4) {lungime=x, nr_persoane_transportate=y;};
	autoturism(autoturism &x){lungime=x.lungime; nr_persoane_transportate=x.nr_persoane_transportate;mic_litraj=x.mic_litraj; masina_de_oras=x.masina_de_oras; masina_usor_de_folosit=x.masina_usor_de_folosit; van=x.van;}
	float get_lungime(){return lungime;}
	unsigned get_nr_persoane(){return nr_persoane_transportate;}
	void set_lungime(float x){lungime=x;}
	void set_nr_persoane(unsigned x){nr_persoane_transportate=x;}
	void set_mic_litraj(){mic_litraj=1;}
	void set_masina_de_oras(){masina_de_oras=1;}
	void set_masina_usor_de_folosit(){masina_usor_de_folosit=1;}
	void set_van(){van=1;}
	bool get_mic_litraj(){return mic_litraj;}
	bool get_masina_de_oras(){return masina_de_oras;}
	bool get_masina_usor_de_folosit(){return masina_usor_de_folosit;}
	bool get_van(){return van;}
	void citire(){int x,y;std::cin>>x>>y; set_lungime(x); set_nr_persoane(y);}
	void afisare(){std::cout<<"Lungime: "<<get_lungime()<<" cu nr persoane:"<<get_nr_persoane()<<"\n";}
	friend std::istream& operator >>(std::istream &in, autoturism &X){ X.citire();return in;}
	friend std::ostream& operator <<(std::ostream &out, autoturism &X){ X.afisare();return out;}
	friend std::ostream& operator <<(std::ostream &out, autoturism *X){ X->afisare();return out;}
	autoturism& operator=(autoturism& ob)
	{
		if((*this).lungime!=ob.lungime||(*this).nr_persoane_transportate!=ob.nr_persoane_transportate){lungime=ob.get_lungime();nr_persoane_transportate=ob.get_nr_persoane();}
		return *this;
	}
	~autoturism();
};
#endif