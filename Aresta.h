#ifndef ARESTA_H_
#define ARESTA_H_
#include "Vertice.h"

class Aresta
{
  public:
    Aresta();
    Aresta(Vertice verticeOrigem,Vertice verticeDestino);
    void defineVertices(Vertice verticeOrigem, Vertice verticeDestino);
    Vertice verticeOrigem;
    Vertice verticeDestino;
};

#endif