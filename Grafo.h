#ifndef GRAFO_H_
#define GRAFO_H_
#include "Aresta.h"
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

class Grafo{
	public:
	Grafo();
	Grafo(vector<Vertice> vetorVertices, vector<Aresta> vetorArestas);
	void inicializarGrafo(vector<Vertice> vetorVerticesInput, vector<Aresta> vetorArestasInput);
	vector<int> grau();
	vector<Vertice> vetorVertices;
	vector<Aresta> vetorArestas;
	void BFS(Vertice verticePartida);
	void DFS(Vertice verticePartida);
	vector<int> lerGrafo();
	void escreverGrafo(int numeroVertices, int numeroArestas);
};

#endif
