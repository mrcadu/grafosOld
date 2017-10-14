

#ifndef GRAFOCOMPESO_H_
#define GRAFOCOMPESO_H_

#include "Vertice.h"
#include "ArestaComPesos.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <list>

class GrafoComPeso {
public:
	GrafoComPeso();
	GrafoComPeso(vector<Vertice> vetorVertices ,vector<ArestaComPesos> vetorArestas);
	void inicializarGrafo(vector<Vertice> vetorVertices ,vector<ArestaComPesos> vetorArestas);
	vector<int> lerGrafo();
	vector<int> grau();
	void escreverGrafo(int numeroVertices,int numeroArestas);
	vector<Vertice> vetorVertices;
	vector<ArestaComPesos> vetorArestas;
	map<int,int> dijkstraDistancia(Vertice verticePartida);
	int dijkstraDistancia(Vertice verticePartida,Vertice verticeDestino);
	map<int,vector<int>> dijkstraCaminho(Vertice verticePartida);
	vector<int> dijkstraCaminho(Vertice verticePartida,Vertice verticeDestino);
};
#endif
