#include "GrafoComPeso.h"

GrafoComPeso::GrafoComPeso()
{

}

GrafoComPeso::GrafoComPeso(vector<Vertice> vetorVertices,vector<ArestaComPesos> vetorArestas)
{
	this -> vetorVertices = vetorVertices;
	this -> vetorArestas = vetorArestas;
	for (int i =0;i <= vetorArestas.size() - 1;i++)
	{
		vetorVertices[vetorArestas[i].verticeDestino.codigoVertice - 1].verticesVizinhos.push_back(vetorVertices[vetorArestas[i].verticeOrigem.codigoVertice - 1]);
		vetorVertices[vetorArestas[i].verticeOrigem.codigoVertice - 1].verticesVizinhos.push_back(vetorVertices[vetorArestas[i].verticeDestino.codigoVertice - 1]);
	}
	for(int j = 0;j < vetorArestas.size(); j++)
	{
		Vertice *verticeOrigem  = &vetorVertices[vetorArestas[j].verticeOrigem.codigoVertice - 1];
		Vertice *verticeDestino  = &vetorVertices[vetorArestas[j].verticeDestino.codigoVertice - 1];
		verticeOrigem->mapaDistancia[verticeDestino->codigoVertice] = vetorArestas[j].peso;
		verticeDestino->mapaDistancia[verticeOrigem->codigoVertice] = vetorArestas[j].peso;

	}
}
void GrafoComPeso::inicializarGrafo(vector<Vertice> vetorVertices, vector<ArestaComPesos> vetorArestas)
{
	
        this -> vetorVertices = vetorVertices;
        this -> vetorArestas = vetorArestas;
	inicializarVetoresVerticesVizinhos();
        for(int i = 0;i < vetorArestas.size(); i++)
	{
            Vertice *verticeOrigem  = &vetorVertices[vetorArestas[i].verticeOrigem.codigoVertice - 1];
            Vertice *verticeDestino  = &vetorVertices[vetorArestas[i].verticeDestino.codigoVertice - 1];
            verticeDestino->verticesVizinhos[getLastIteratorNumber(verticeDestino->verticesVizinhos)] = *verticeOrigem;
            verticeOrigem->verticesVizinhos[getLastIteratorNumber(verticeOrigem->verticesVizinhos)] = *verticeDestino;
            verticeOrigem->mapaDistancia[verticeDestino->codigoVertice] = vetorArestas[i].peso;
            verticeDestino->mapaDistancia[verticeOrigem->codigoVertice] = vetorArestas[i].peso;
	}
}
int GrafoComPeso::getLastIteratorNumber(vector<Vertice> vetorVerticesIterator)
{
    for(int i = 0; i < vetorVerticesIterator.capacity();i++)
    {
        if(vetorVerticesIterator.back().codigoVertice == vetorVerticesIterator[i].codigoVertice)
        {
            return i+1;
        }
    }
}
void GrafoComPeso::inicializarVetoresVerticesVizinhos()
{
    for(int i = 1; i < mapaNumeroVerticesVizinhos.size(); i++)
    {
        vetorVertices[i].verticesVizinhos.resize(mapaNumeroVerticesVizinhos[i + 1]);
    }
}
vector<int> GrafoComPeso::lerGrafo()
{
        vector<ArestaComPesos> vetorArestasComPesos;
        int numeroVertices;
        int numeroArestas = 0;
        int verticeOrigem;
        int verticeDestino;
        int peso;
        FILE *input;
        input = fopen("input.txt","r");
        fscanf(input,"%d\n",&numeroVertices);
        vector<Vertice> vetorVertices(numeroVertices);
        for(int i = 0;i < numeroVertices;i++)
        {
            vetorVertices[i].defineCodigo(i+1);
        }
        while(fscanf(input,"%d %d %d \n",&verticeOrigem,&verticeDestino,&peso) != EOF)
        {
            ArestaComPesos arestaAtual(vetorVertices[verticeOrigem - 1],vetorVertices[verticeDestino - 1],peso);
            vetorArestas.push_back(arestaAtual);
            mapaNumeroVerticesVizinhos[verticeOrigem] += 1;
            numeroArestas += 1;
        }
        vector<int> informacoes = {numeroVertices,numeroArestas};
        inicializarGrafo(vetorVertices,vetorArestas);
        fclose(input);
        return informacoes;
}
vector<int> GrafoComPeso::grau()
{
	vector<int> vetorGrau = {0,-1,0};
	for(int i=0;i < vetorVertices.size() ;i++)
        {
		if (vetorVertices[i].verticesVizinhos.size() > vetorGrau[0])
		{
			vetorGrau[0] = vetorVertices[i].verticesVizinhos.size();
		}
		if (vetorVertices[i].verticesVizinhos.size() < vetorGrau[1])
		{
			vetorGrau[1] = vetorVertices[i].verticesVizinhos.size();
		}
		vetorGrau[2] += vetorVertices[i].verticesVizinhos.size();
	}
	return vetorGrau;
}
void GrafoComPeso::escreverGrafo(int numeroVertices,int numeroArestas)
{
	  ofstream arquivoSaida;
	  grau();
	  if(arquivoSaida){
	    int grauMedio = grau()[2];
	    int grauMinimo = grau()[1];
	    int grauMaximo = grau()[0];
	    vector<int> distribuicaoEmpirica (grauMaximo,0) ;
	    arquivoSaida.open("saida.txt");
	    arquivoSaida << "numero de vertices:" << numeroVertices  << endl;
	    arquivoSaida << "numero de arestas:" << numeroArestas << endl;
	    arquivoSaida << "grau Médio:" << grauMedio/7 << endl;
	    arquivoSaida << "grau Min:" << grauMinimo << endl;
	    arquivoSaida << "grau Max:" << grauMaximo << endl;
	//    for(int i = 0 ; i <= grafo.vetorVertices.size() - 1 ; i++ ){
	//    	distribuicaoEmpirica[grafo.vetorVertices[i].verticesVizinhos.size() - 1] += 1;
	//    }
	//    for(int j = 0; j <= distribuicaoEmpirica.size() -1 ; j++  ){
	//    	arquivoSaida << j + 1 << "- " << distribuicaoEmpirica[j] << endl;
	//    }
	    arquivoSaida.close();
	  }
}
map<int,int> GrafoComPeso::dijkstraDistancia(Vertice verticePartida)
{
	map <int,int> distancia;
	vector<Vertice> verticesRestantes = vetorVertices;
	Vertice *verticeAtual;
	int indiceVertice;
	for(int i = 0;i < vetorVertices.size();i++)
	{
		distancia[vetorVertices[i].codigoVertice] = 1000;
	}
	vector<Vertice> solucao;
	distancia[verticePartida.codigoVertice] = 0;
	while(vetorVertices.size() != solucao.size())
	{
		verticeAtual = &verticesRestantes[0];
		for(int i=0;i < verticesRestantes.size();i++)
		{
			if(distancia[verticesRestantes[i].codigoVertice] <= distancia[verticeAtual->codigoVertice])
			{
				verticeAtual = &verticesRestantes[i];
				indiceVertice = i;
			}
		}
		solucao.push_back(*verticeAtual);
		for (int j = 0;j < verticeAtual->verticesVizinhos.size();j++)
			{
				if(distancia[verticeAtual->verticesVizinhos[j].codigoVertice] > distancia[verticeAtual->codigoVertice] + verticeAtual->mapaDistancia[verticeAtual->verticesVizinhos[j].codigoVertice])
				{
					distancia[verticeAtual->verticesVizinhos[j].codigoVertice] = distancia[verticeAtual->codigoVertice] + verticeAtual->mapaDistancia[verticeAtual->verticesVizinhos[j].codigoVertice];
				}
			}
		verticesRestantes.erase(verticesRestantes.begin() + indiceVertice);
		}
	return distancia;
}
int GrafoComPeso::dijkstraDistancia(Vertice verticePartida,Vertice verticeDestino)
{
	map <int,int> distancia;
		vector<Vertice> verticesRestantes = vetorVertices;
		Vertice *verticeAtual;
		int indiceVertice;
		for(int i = 0;i < vetorVertices.size();i++)
		{
			distancia[vetorVertices[i].codigoVertice] = 1000;
		}
		vector<Vertice> solucao;
		distancia[verticePartida.codigoVertice] = 0;
		while((vetorVertices.size() != solucao.size()) )
		{
			verticeAtual = &verticesRestantes[0];
			for(int i=0;i < verticesRestantes.size();i++)
			{
				if(distancia[verticesRestantes[i].codigoVertice] <= distancia[verticeAtual->codigoVertice])
				{
					verticeAtual = &verticesRestantes[i];
					indiceVertice = i;
				}
			}
			solucao.push_back(*verticeAtual);
			for (int j = 0;j < verticeAtual->verticesVizinhos.size();j++)
				{
					if(distancia[verticeAtual->verticesVizinhos[j].codigoVertice] > distancia[verticeAtual->codigoVertice] + verticeAtual->mapaDistancia[verticeAtual->verticesVizinhos[j].codigoVertice])
					{
						distancia[verticeAtual->verticesVizinhos[j].codigoVertice] = distancia[verticeAtual->codigoVertice] + verticeAtual->mapaDistancia[verticeAtual->verticesVizinhos[j].codigoVertice];
					}
				}
			if(verticesRestantes[indiceVertice].codigoVertice == verticeDestino.codigoVertice)
			{
				return distancia[verticesRestantes[indiceVertice].codigoVertice];
			}
			verticesRestantes.erase(verticesRestantes.begin() + indiceVertice);
			}
}
map<int,vector<int>> GrafoComPeso::dijkstraCaminho(Vertice verticePartida)
{
	map<int,vector<int>> caminho;
	map <int,int> distancia;
	vector<Vertice> verticesRestantes = vetorVertices;
	Vertice *verticeAtual;
	int indiceVertice;
	for(int i = 0;i < vetorVertices.size();i++)
	{
		distancia[vetorVertices[i].codigoVertice] = 1000;
	}
	vector<Vertice> solucao;
	distancia[verticePartida.codigoVertice] = 0;
	while(vetorVertices.size() != solucao.size())
	{
		verticeAtual = &verticesRestantes[0];
		for(int i=0;i < verticesRestantes.size();i++)
		{
			if(distancia[verticesRestantes[i].codigoVertice] <= distancia[verticeAtual->codigoVertice])
			{
				verticeAtual = &verticesRestantes[i];
				indiceVertice = i;
			}
		}
		solucao.push_back(*verticeAtual);
		for (int j = 0;j < verticeAtual->verticesVizinhos.size();j++)
			{
				if(distancia[verticeAtual->verticesVizinhos[j].codigoVertice] > distancia[verticeAtual->codigoVertice] + verticeAtual->mapaDistancia[verticeAtual->verticesVizinhos[j].codigoVertice])
				{
					distancia[verticeAtual->verticesVizinhos[j].codigoVertice] = distancia[verticeAtual->codigoVertice] + verticeAtual->mapaDistancia[verticeAtual->verticesVizinhos[j].codigoVertice];
				}
			}
		verticesRestantes.erase(verticesRestantes.begin() + indiceVertice);
	}
	for(int i = 0;i < solucao.size();i++)
	{
		for(int j = 0;j <= i ;j++)
		{
			caminho[solucao[i].codigoVertice].push_back(solucao[j].codigoVertice);
		}
	}
	return caminho;
}
vector<int> GrafoComPeso::dijkstraCaminho(Vertice verticePartida,Vertice verticeDestino)
{
	vector<int> caminhoUnitario = dijkstraCaminho(verticePartida)[verticeDestino.codigoVertice];
	return caminhoUnitario;
}


