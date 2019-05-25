#include <iostream>
#include <string.h>
#include <typeinfo>
#include <list>
#include <iterator>
#include <vector>
#include <queue>
#include "autoturism.h"
#include "mini.h"
#include "mica.h"
#include "compacta.h"
#include "monovolumele.h"

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
	autoturism a(4,5);
	MINI m1;
	MICA m2;
	COMPACTA c;
	MONOVOLUMELE m;


	return 0;
}