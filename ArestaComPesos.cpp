
#include "ArestaComPesos.h"

ArestaComPesos::ArestaComPesos()
{

}
ArestaComPesos::ArestaComPesos(Vertice verticeOrigem,Vertice verticeDestino, int peso)
{
	this -> verticeOrigem = verticeOrigem;
	this -> verticeDestino = verticeDestino;
	this -> peso = peso;
}

