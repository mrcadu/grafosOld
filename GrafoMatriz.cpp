#include "GrafoMatriz.h"

GrafoMatriz::GrafoMatriz()
{
}
GrafoMatriz::GrafoMatriz(vector<Vertice> vetorVertices,vector<Aresta> vetorArestas)
{
    this -> vetorVertices = vetorVertices;
    for(int i = 0; i <= vetorArestas.size() - 1;i++)
    {
		  int1bit marcado;
		  marcado.vertexNum = 1;
      vector<vector<int1bit> > matrizArestas ( vetorVertices.size() ,vector<int1bit>(vetorVertices.size())) ;
	    matrizArestas[vetorArestas[i].verticeOrigem.codigoVertice - 1 ][vetorArestas[i].verticeDestino.codigoVertice - 1] = marcado;
      matrizArestas[vetorArestas[i].verticeDestino.codigoVertice - 1][vetorArestas[i].verticeOrigem.codigoVertice -1] = marcado;

	  }

}
