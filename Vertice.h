#ifndef VERTICE_H_
#define VERTICE_H_
#include <map>
#include <vector>
#include <list>
using namespace std;

class Vertice{
	public:
	Vertice();
	Vertice(int codigoVertice);
        vector<Vertice> verticesVizinhos;
	void defineCodigo(int codigo);
	int codigoVertice;
	bool marcado;
	int nivelBusca;
	map<int,int> mapaDistancia;
};


#endif