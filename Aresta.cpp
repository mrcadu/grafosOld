#include "Aresta.h"

void Aresta::defineVertices(Vertice verticeOrigem, Vertice verticeDestino)
{
	this -> verticeOrigem = verticeOrigem;
	this -> verticeDestino = verticeDestino;
}
Aresta::Aresta()
{
}
Aresta::Aresta(Vertice verticeOrigem, Vertice verticeDestino)
{
	this -> verticeOrigem = verticeOrigem;
	this -> verticeDestino = verticeDestino;
}

