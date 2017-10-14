#include "Vertice.h"

void Vertice::defineCodigo(int codigo)
{
	codigoVertice = codigo;
	verticesVizinhos = {};
}
Vertice::Vertice()
{
}
Vertice::Vertice(int codigoVertice)
{
	this -> codigoVertice = codigoVertice;
	verticesVizinhos = {};
}

