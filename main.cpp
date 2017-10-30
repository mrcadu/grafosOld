#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cstring>
#include <stdio.h>
#include "ArestaComPesos.h"
#include "GrafoComPeso.h"
#include "Grafo.h"
#include "GrafoMatriz.h"
using namespace std;

int main(){
    GrafoComPeso grafo;
    vector <int> informacoes = grafo.lerGrafo();
    grafo.escreverGrafo(informacoes[0],informacoes[1]);
}


