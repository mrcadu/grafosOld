#include "Grafo.h"

	Grafo::Grafo()
	{
	}
	Grafo::Grafo(vector<Vertice> vetorVerticesInput, vector<Aresta> vetorArestasInput)
	{
		vetorVertices = vetorVerticesInput;
		vetorArestas = vetorArestasInput;
		for (int i =0;i <= vetorArestas.size() - 1;i++)
		{
			vetorVertices[vetorArestas[i].verticeDestino.codigoVertice - 1].verticesVizinhos.push_back(vetorVertices[vetorArestas[i].verticeOrigem.codigoVertice - 1]);
			vetorVertices[vetorArestas[i].verticeOrigem.codigoVertice - 1].verticesVizinhos.push_back(vetorVertices[vetorArestas[i].verticeDestino.codigoVertice - 1]);
		}
	}
	void Grafo::inicializarGrafo(vector<Vertice> vetorVerticesInput, vector<Aresta> vetorArestasInput)
	{
		vetorVertices = vetorVerticesInput;
		vetorArestas = vetorArestasInput;
		for (int i =0;i <= vetorArestas.size() - 1; i++)
		{
		vetorVertices[vetorArestas[i].verticeDestino.codigoVertice - 1].verticesVizinhos.push_back(vetorVertices[vetorArestas[i].verticeOrigem.codigoVertice - 1]);
		vetorVertices[vetorArestas[i].verticeOrigem.codigoVertice - 1].verticesVizinhos.push_back(vetorVertices[vetorArestas[i].verticeDestino.codigoVertice - 1]);
		}
	}

	vector<int> Grafo::grau()
	{
		vector<int> vetorGrau = {0,10000000,0};
		for(int i=0;i < vetorVertices.size() ;i++){
			if (vetorVertices[i].verticesVizinhos.size() > vetorGrau[0]){
				vetorGrau[0] = vetorVertices[i].verticesVizinhos.size();
			}
			if (vetorVertices[i].verticesVizinhos.size() < vetorGrau[1]){
				vetorGrau[1] = vetorVertices[i].verticesVizinhos.size();
			}
			vetorGrau[2] += vetorVertices[i].verticesVizinhos.size();
		}
		return vetorGrau;
	}
	void Grafo::BFS(Vertice verticePartida){
			queue<int> filaVertices;
			for (int i = 0;i < vetorVertices.size();i++){
				vetorVertices[i].marcado = false;
				vetorVertices[i].nivelBusca = 0;
			}
			vetorVertices[verticePartida.codigoVertice - 1].marcado = true;
			filaVertices.push(vetorVertices[verticePartida.codigoVertice - 1].codigoVertice);
			int j = 1;
			while(!filaVertices.empty()){
				for (int i=0;i < vetorVertices[filaVertices.front() - 1].verticesVizinhos.size(); i++){
					if (vetorVertices[vetorVertices[filaVertices.front() - 1].verticesVizinhos[i].codigoVertice - 1].marcado == false){
						vetorVertices[vetorVertices[filaVertices.front() - 1].verticesVizinhos[i].codigoVertice - 1].marcado = true;
						vetorVertices[vetorVertices[filaVertices.front() - 1].verticesVizinhos[i].codigoVertice - 1].nivelBusca = j;
						filaVertices.push(vetorVertices[filaVertices.front() - 1].verticesVizinhos[i].codigoVertice);
					}
				}
				filaVertices.pop();
				j++;
			}

	}
	void Grafo::DFS(Vertice verticePartida)
	{
		for(int i = 0;i< vetorVertices.size(); i++ )
		{
			vetorVertices[i].marcado = false;
		}
		stack<int> filaCodigosVertice;
		filaCodigosVertice.push(vetorVertices[verticePartida.codigoVertice - 1].codigoVertice);
		while(!filaCodigosVertice.empty())
		{
			int verticeAtual = vetorVertices[filaCodigosVertice.top() - 1].codigoVertice;
			filaCodigosVertice.pop();
			if(vetorVertices[verticeAtual - 1].marcado == false)
			{
				vetorVertices[verticeAtual - 1].marcado = true;
				for(int i = 0; i < vetorVertices[verticeAtual - 1].verticesVizinhos.size(); i ++ )
				{
					filaCodigosVertice.push(vetorVertices[verticeAtual - 1].verticesVizinhos[i].codigoVertice);
				}
			}
		}
	}
	vector<int> Grafo::lerGrafo()
	{
	string arestaAtual;
	string numeroVertices;
	ifstream arquivoEntrada;
	int numeroArestas = 0;
	vector<int> vetorInformacoes = {0,0};
	arquivoEntrada.open("input.txt");
	if(arquivoEntrada){
		getline(arquivoEntrada, numeroVertices);
		vector<Vertice> vetorVertices (stoi(numeroVertices));
		vector<Aresta> vetorArestas;
		for(int i = 0;i < stoi(numeroVertices);i++)
		{
			vetorVertices[i].defineCodigo(i+1);
		}
		while(getline(arquivoEntrada,arestaAtual))
		{
			int prNumero,seNumero;
			prNumero = stoi(arestaAtual.substr(0));
		 	seNumero = stoi(arestaAtual.substr(2));
		 	Aresta aresta(vetorVertices[prNumero - 1],vetorVertices[seNumero - 1]);
		 	vetorArestas.push_back(aresta);
		 	numeroArestas += 1;
		}

		arquivoEntrada.close();
		inicializarGrafo(vetorVertices,vetorArestas);
		vetorInformacoes[0] = numeroArestas;
		vetorInformacoes[1] = stoi(numeroVertices);
		return vetorInformacoes;
		}
	}
	void Grafo::escreverGrafo(int numeroVertices,int numeroArestas)
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
		    arquivoSaida << "grau Médio:" << grauMedio/vetorVertices.size() << endl;
		    arquivoSaida << "grau Min:" << grauMinimo << endl;
		    arquivoSaida << "grauNivelBusca Max:" << grauMaximo << endl;
		//    for(int i = 0 ; i <= grafo.vetorVertices.size() - 1 ; i++ ){
		//    	distribuicaoEmpirica[grafo.vetorVertices[i].verticesVizinhos.size() - 1] += 1;
		//    }
		//    for(int j = 0; j <= distribuicaoEmpirica.size() -1 ; j++  ){
		//    	arquivoSaida << j + 1 << "- " << distribuicaoEmpirica[j] << endl;
		//    }
		    arquivoSaida.close();
		  }
	}



