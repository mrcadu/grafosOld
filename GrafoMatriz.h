#ifndef GRAFOMATRIZ_H_
#define GRAFOMATRIZ_H_
#include "Aresta.h"

typedef struct
	{
	int vertexNum:1;
	} int1bit;

using namespace std;
class GrafoMatriz{
	public:
		GrafoMatriz();
		GrafoMatriz(vector <Vertice>,vector<Aresta>);
		vector<Vertice> vetorVertices;
		vector<vector<int1bit> > matrizArestas;
};

#endif
