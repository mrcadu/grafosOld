#ifndef ARESTACOMPESOS_H_
#define ARESTACOMPESOS_H_
#include "Aresta.h"

class ArestaComPesos : public Aresta
{
	public:
    	ArestaComPesos();
    	ArestaComPesos(Vertice verticeOrigem, Vertice verticeDestino,int peso);
    	int peso;

};

#endif
