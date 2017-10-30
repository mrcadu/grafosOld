#include "Vertice.h"

void Vertice::defineCodigo(int codigo)
{
	codigoVertice = codigo;
	verticesVizinhos = {};
        numeroAtualIterador = 0;
}
Vertice::Vertice()
{
}
Vertice::Vertice(int codigoVertice)
{
	this -> codigoVertice = codigoVertice;
	verticesVizinhos = {};
        numeroAtualIterador = 0;
}

