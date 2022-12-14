#ifndef ALGORITMOS_GRAFO
#define ALGORITMOS_GRAFO
#include "ListaIndexadaPlantilla.hpp"
#include "SeleccionDeGrafo.hpp"
#include "relacion1A1.hpp"
#include <map>
#include <vector>
#include <queue>
#include <iostream>

struct ContenedorDijkstra{
  ContenedorDijkstra(Vertice* v, int pesoAcumulado) 
    : vertice(v), pesoAcumulado(pesoAcumulado) {}
  ContenedorDijkstra(){}

  Vertice* getVertice() {return vertice;}
  Vertice* vertice;  //Vértice de llegada
  int pesoAcumulado; //Peso total para llegar hasta al vértice de llegada
};


namespace Algoritmos{
  /**
   * @brief Algoritmo que dado un vÃ©rtice de inicio, se le calcula el peso total para ir a todos los vÃ©rtices, junto al vÃ©rtice anterior que se usa para llegar a ese vÃ©rtice destino, se logra por medio de una lista pasada como parÃ¡metro para modificarla y guardar el resultado, en Ã©sta lista se encuentran "contenedores Dijsktra" los cuales contienen el "peso total" y "vÃ©rtice anterior"
   * @remark Requiere: Grafo vÃ¡lido con al menos un elemento, lista pasada como parÃ¡metro NO inicializada
   * @remark Efecto: Modificar una lista pasada como parÃ¡metro donde se encuentra el resultado de aplicar Dijsktra con el vÃ©rtice dado
   * @remark Modifica: La lista pasada com
   * 
   * @param g Grafo
   * @param v  Vértice de partida
   * @param lista Lista resultante del algoritmo
   */
  void Dijkstra(Grafo* g, Vertice* v, ListaIndexada<ContenedorDijkstra>* lista);
  /**
   * @brief Algoritmo que hace bÃºsqueda exhaustiva pura para resolver el problema de "Coloreo", Usa variables globales y 2 Conjuntos de Conjuntos  
   * La soluciÃ³n se encuentra en la variable global "colorDeVÃ©rtice", el cual es un arreglo donde cada Ã­ndice representa un vÃ©rtice(por medio de la variable global "relaciÃ³n1a1") y el valor en el arreglo representa el color del que estÃ¡ pintado,  retorna el menor nÃºmero de colores para pintar el grafo  
   * 
   * IMPORTANTE: Existe un "#define NN" en "Algoritmos.cpp" el cual debe ser modificado de acuerdo al nÃºmero de vÃ©rtices en en grafo  
   * @remark Requiere: Grafo con al menos un vÃ©rtice y al menos una solución
   * @remark Efecto: Resuelve el problema de coloreo en un grafo dado  
   * @remark Modifica: Variables globales
   * 
   * @param g  Grafo
   * @return int Número mínimo de colores para pintar el grafo
   */
  int Coloreo(Grafo* g);

  /**
   * @brief Algoritmo de bÃºsqueda Exhaustiva Pura para resolver el problema de los circuitos Hamilton en un grafo no dirigido, la soluciÃ³n se encuentra en la variable global "recorrido" el cual es un arreglo donde los Ã­ndices indican el orden en el que se recorren los vÃ©rtices, y los valores son los vÃ©rtices de acuerdo a la relaciÃ³n1a1  
   * @remark Requiere: Grafo con al menos un vÃ©rtice y al menos una solución
   * @remark Efecto: Retornar el peso total del circuito Hamilton de menor costo  
   * @remark Modifica: Nada
   * 
   * IMPORTANTE: Existe un "#define NN" en "Algoritmos.cpp" el cual debe ser modificado de acuerdo al nÃºmero de vÃ©rtices en en grafo  
   * 
   * @param g Grafo
   * @return int  Costó del Circuito Hamilton de  menor costo
   */
  int Hamilton(Grafo* g);

  //   for(int ii = 0; ii < numVertices ; ii++){
  //     for(int iii = 0; iii < numVertices ; iii++){
  //       if(ii == iii) iii++;
        
  //       mAdj[ii][iii] = g->peso(tmp, tmpAd);
  //       tmpAd = g->siguienteVerticeAdyacente(tmp, tmpAd);
  //     }
  //     tmp = g->siguienteVertice(tmp);
  //   }
  // }

  std::vector<std::pair<Vertice*, Vertice*>> Prim(Grafo* g); // nada mas retorno la lista indexada, no me la tienen que
  // dar como argumento.
  std::vector<std::pair<Vertice*, Vertice*>> Kruskal(Grafo* g);
  /**
   * @brief Algoritmo de bÃºsqueda Exhaustiva Pura con RamificaciÃ³n y Acotamiento para resolver el problema de los circuitos Hamilton en un grafo no dirigido, la soluciÃ³n se encuentra en la variable global "recorrido" el cual es un arreglo donde los Ã­ndices indican el orden en el que se recorren los vÃ©rtices, y los valores son los vÃ©rtices de acuerdo a la relaciÃ³n1a1 
   * Se hace un Ã¡rbol n-ario para la RamificaciÃ³n y el Acotamiento 
   * @remark Requiere: Grafo con al menos un vÃ©rtice  y al menos una solución
   * @remark Efecto: Retornar el peso total del circuito Hamilton de menor costo 
   * @remark Modifica: Nada
   * 
   * IMPORTANTE: Existe un "#define NN" en "Algoritmos.cpp" el cual debe ser modificado de acuerdo al nÃºmero de vÃ©rtices en en grafo  
   * 
   * @param g Grafo
   * @return int  Costó del Circuito Hamilton de  menor costo
   */
  int HamiltonBERA(Grafo* g);
/*
   * @brief Implementacion del algoritmo de Floyd.
   * EFECTO: Encuentra el camino mas corto entre todo par de vertices.
   * REQUIERE: Grafo inicializado, no vacio, matriz de pesos, matriz de vertices y relacion1a1
   * ademas, requiere que ningun peso del grafo sea mayor a 99998.
   * MODIFICA: matriz de pesos, matriz de vertices y relacion1a1.
   * @param g grafo a utilizar.
   * @param matrizPesos puntero a puntero de int(matriz de int) que contiene
   * los pesos de las aristas, termina conteniendo el valor de las distancias
   * entre aristas.
   * @param matrizVertices puntero a puntero a puntero de Vertices(matriz de punteros
   * a Vertices) contiene los vertices intermedios por los que se pasa para llegar de un 
   * vertice al otro.
   * @param relacion1a1 Relacion1a1 entre los vertices y el indice que los representa en 
   * las matrices
  */
  void Floyd(Grafo* g,int**& matrizPesos,Vertice***& matrizVertices,Relacion1A1* relacion1a1);
  /**
   * @brief Implementacion del algoritmo de Dijkstra n veces.
   * EFECTO: Encuentra el camino mas corto entre todo par de vertices.
   * REQUIERE: grafo inicializado no vacio. +Req de Dijkstra
   * MODIFICA: Arreglo de listas
   * @param g grafo a utilizar.
   * @param arregloListas puntero a ListaIndexada<ContenedorDijkstra>
   * (arreglo de listas) termina conteniendo las listas con los caminos 
   * mas cortos entre todos los vertices.
  */
  void NDijkstra(Grafo* g,ListaIndexada<ContenedorDijkstra>* arregloListas);
}
#endif /* ALGORITMOS_GRAFO */
