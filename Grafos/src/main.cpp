#include <iostream>
#include "../include/ListaIndexadaPlantilla.hpp"
#include "../include/SeleccionDeGrafo.hpp"
#include "../include/Algoritmos.hpp"
using namespace Algoritmos;
using namespace std;

//===========================  testing functions
template <typename Pmatrix>// This is the easiest way to make a function with templates to pass as an argument a matrix
void printMatrix(Pmatrix& matrix, int rows, int columns){
	cout << "\n# Copiar y pegar este resultado a un archivo markdown para una mejor visualización " << endl;
	int value;
	cout << "|-";
	for(int ii = 0; ii < rows ; ii++){
		cout << "|" << ii;
	}
	cout << "|" << endl;

	cout << "|-";
	for(int ii = 0; ii < rows ; ii++){
		cout << "|-";
	}
	cout << "|" << endl;

	for(int ii = 0; ii < rows ; ii++){
		cout << "|" << ii << "|";
		for(int iii = 0; iii < columns ; iii++){
			value = matrix[ii][iii];
			if(value != -1){
				cout << value << "|";
			} else{
				cout << "-" << "|";
			}
		}
		cout  << endl;
	}
}



//=====  

int main(){ 

	Grafo* g = new Grafo();
	Grafo* gg = new Grafo();
	// g->iniciar();
	Vertice* vtmp;
	Vertice* va = g->agregarVertice("a");
	Vertice* vb = g->agregarVertice("b");
	Vertice* vc = g->agregarVertice("c");

	Vertice* vd = g->agregarVertice("d");
	Vertice* ve = g->agregarVertice("e");
	Vertice* vf = g->agregarVertice("f");

	g->agregarArista(va, vb, 8);
	g->agregarArista(va, vc, 1);
	g->agregarArista(vc, vb, 9);
	g->agregarArista(vd, vb, 8);
	g->agregarArista(vf, vb, 2);
	g->agregarArista(vc, ve, 5);
	g->agregarArista(vd, vf, 3);
	g->agregarArista(va, vf, 5);
	g->agregarArista(ve, vb, 8);

	//Floyd(g, va, mAdj, mVert);

	Vertice* vva = gg->agregarVertice("a");
	Vertice* vvb = gg->agregarVertice("b");
	Vertice* vvc = gg->agregarVertice("c");
	gg->agregarArista(va, vc, 5);
	gg->agregarArista(va, vb, 7);
	gg->agregarArista(vc, vb, 1);
	ListaIndexada<ContenedorDijkstra>* lista = new ListaIndexada<ContenedorDijkstra>();
	Dijkstra(gg, va, lista);
	Coloreo(g);
	// Hamilton(g);
	// HamiltonBERA(g);
	Vertice* vr = g->agregarVertice("r");
	g->agregarArista(vr, vb, 9);
	g->agregarArista(vr, vf, 5);
	g->agregarArista(vr, ve, 1);
	g->agregarArista(vr, vd, 4);
	g->agregarArista(vr, va, 3);
	Hamilton(g);
	HamiltonBERA(g);
	Coloreo(g);
	Vertice* vl = g->agregarVertice("l");
	g->agregarArista(vl, vb, 3);
	g->agregarArista(vl, vf, 2);
	g->agregarArista(vl, ve, 7);
	g->agregarArista(vl, vd, 4);
	g->agregarArista(vl, va, 3);
	Hamilton(g);
	HamiltonBERA(g);
	Coloreo(g);
	printMatrix(g->matrizVertices, 10, 10); //Línea exclusiva para grafo implementado por matriz
	// g->eliminarVertice("a");
  // Prim(g);
  // Kruskal(g);
	// g->eliminarVertice("e");
	printMatrix(g->matrizVertices, 10, 10); //Línea exclusiva para grafo implementado por matriz


	vtmp = g->primerVertice();
	vtmp = g->siguienteVertice(vtmp);
	vtmp = g->primerVerticeAdyacente(vtmp);
	vtmp = g->siguienteVerticeAdyacente(vtmp, vb);

	g->destruir();

	return 0;
}
