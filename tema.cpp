#include <iostream>
#include <string.h>
#include <typeinfo>
#include <list>
#include <iterator>


class autoturism{
	float lungime;
	unsigned nr_persoane_transportate;
	bool mic_litraj=0;
	bool masina_de_oras=0;
	bool masina_usor_de_folosit=0;
	bool van=0;
	public:
	autoturism(float x=3.5,unsigned y=4) {lungime=x, nr_persoane_transportate=y;};
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

class MINI:public autoturism
{
	public:
	MINI(float x=3.5,unsigned y=4):autoturism(x,y){set_mic_litraj();}
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

class MICA:public autoturism
{
	public:
	MICA(float x=3.85,unsigned y=4):autoturism(x,y){set_masina_de_oras();}
	~MICA(){};
	void citire(){int x,y;std::cin>>x>>y; set_lungime(x); set_nr_persoane(y);}
	void afisare(){std::cout<<"Masina mica\nLungime: "<<get_lungime()<<" cu nr persoane:"<<get_nr_persoane()<<"\n";}
	friend std::istream& operator >>(std::istream &in, MICA &X){ X.citire();return in;}
	friend std::ostream& operator <<(std::ostream &out, MICA &X){ X.afisare();return out;}
	friend std::ostream& operator <<(std::ostream &out, MICA *X){ X->afisare();return out;}
	MICA& operator=(MICA& ob)
	{
		if((*this).get_lungime()!=ob.get_lungime()||(*this).get_nr_persoane()!=ob.get_nr_persoane())
			{set_lungime(ob.get_lungime());set_nr_persoane(ob.get_nr_persoane());}
		return *this;
	}
};

class COMPACTA:public autoturism
{
	public:
	COMPACTA(float x=4.2,unsigned y=4):autoturism(x,y){set_masina_usor_de_folosit();}
	~COMPACTA(){};
	void citire(){int x,y;std::cin>>x>>y; set_lungime(x); set_nr_persoane(y);}
	void afisare(){std::cout<<"Masina compacta\nLungime: "<<get_lungime()<<" cu nr persoane:"<<get_nr_persoane()<<"\n";}
	friend std::istream& operator >>(std::istream &in, COMPACTA &X){ X.citire();return in;}
	friend std::ostream& operator <<(std::ostream &out, COMPACTA &X){ X.afisare();return out;}
	friend std::ostream& operator <<(std::ostream &out, COMPACTA *X){ X->afisare();return out;}
	COMPACTA& operator=(COMPACTA& ob)
	{
		if((*this).get_lungime()!=ob.get_lungime()||(*this).get_nr_persoane()!=ob.get_nr_persoane())
			{set_lungime(ob.get_lungime());set_nr_persoane(ob.get_nr_persoane());}
		return *this;
	}
};

class MONOVOLUMELE:public autoturism
{
	public:
	MONOVOLUMELE(float x=4,unsigned y=5):autoturism(x,y){set_van();}
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


template <class T>
class vanzare{
	static unsigned nr_total_masini;
	static unsigned nr_masini_vandute;
	std::list<T*> masini_vandute; 
	std::list<T*> masini_ramase; 
public:
	vanzare(){}
	friend void operator -=(vanzare &X, MINI &ob)
	{
		X.nr_total_masini--; X.nr_masini_vandute++;
		T *p=&ob;
		X.masini_vandute.push_back(p);
		typename std::list<T*>::iterator it;
		for(it=X.masini_ramase.begin();it!=X.masini_vandute.end();it++)
			if(*it==ob)
				{X.masini_ramase.erase(it);break;}
	}
	friend void operator -=(vanzare &X, MICA &ob)
	{
		X.nr_total_masini--; X.nr_masini_vandute++;
		T *p=&ob;
		X.masini_vandute.push_back(p);
		typename std::list<T*>::iterator it;
		for(it=X.masini_ramase.begin();it!=X.masini_vandute.end();it++)
			if(*it==ob)
				{X.masini_ramase.erase(it);break;}
	}
	friend void operator -=(vanzare &X, COMPACTA &ob)
	{
		X.nr_total_masini--; X.nr_masini_vandute++;
		T *p=&ob;
		X.masini_vandute.push_back(p);
		typename std::list<T*>::iterator it;
		for(it=X.masini_ramase.begin();it!=X.masini_vandute.end();it++)
			if(*it==ob)
				{X.masini_ramase.erase(it);break;}
	}
	friend void operator -=(vanzare &X, MONOVOLUMELE &ob)
	{
		X.nr_total_masini--; X.nr_masini_vandute++;
		T *p=&ob;
		X.masini_vandute.push_back(p);
		typename std::list<T*>::iterator it;
		for(it=X.masini_ramase.begin();it!=X.masini_vandute.end();it++)
			if(*it==ob)
				{X.masini_ramase.erase(it);break;}
	}
	~vanzare(){}

};
template <class T>
unsigned vanzare<T>::nr_total_masini=100;
template <class T>
unsigned vanzare<T>::nr_masini_vandute=0;



int main()
{



	return 0;
}
