#include <iostream>
#include <string.h>

#include "../include/Algoritmos.hpp"
#include "../include/ColaPlantilla.hpp"
#include "../include/ListaIndexadaPlantilla.hpp"

using namespace std;

Algoritmos::Algoritmos(){
    this->arbol=new Arbol();
    this->nivelMaximo=1;
}
Algoritmos::~Algoritmos(){
}

void Algoritmos::menu(){
    int accion=1;
    cout<<"Bienvenido al programa que prueba Algoritmos!"<<endl;

    // TODO: Poner como parametros de la clase
    
    ListaIndexada<int> lista;
    Arbol::Nodo* nodo;
    while (accion != 0){
        cout<<"Seleccione el algoritmo que desea probar: "<<endl;
        // TODO: Terminar de agregar las opciones
        string opciones =
        "\n1- Encontrar el hermano izquierdo de un nodo \n2- Averiguar si el árbol tiene etiquetas repetidas\n"
        "3- Encontrar la profundidad de un nodo \n4- Encontrar la cantidad de niveles del árbol en Pre-Orden\n"
        "5- Encontrar la cantidad de niveles del árbol Por Niveles \n6- Listar las etiquetas de un nivel\n"
        "7- Listar las etiquetas del árbol en Pre-Orden \n8- Listar las etiquetas del árbol Por Niveles\n"
        "9- Buscar el nodo correspondiente con una etiqueta \n10- Eliminar subárbol a partir de un nodo\n"
        "11- Construir árbol de i-niveles y k-hijos a partir de una Lista Indexada\n"
        "OTRO- Salir"
        ;
        cout<<opciones<<endl;
        cin >> accion;
        switch(accion){
            case 1:
                // cout<<"El arbol tiene "<<this->contarPorNiveles()<<" niveles"<<endl;
            break;
            case 2:
                int nivel;
                // cout<<"Seleccione el nivel: "<<endl;
                cin>>nivel;
                // this->listaEtiquetasNivel(nivel);
            break;
            case 3:
                // this->recorridoPreOrden();
            break;
            case 4:
                // this->recorridoPorNiveles();
            break;
            case 5:
                this->cantidadNivelesPorNiveles();
            break;
            case 6:
                int nivelDeseado;
                cout << "Ingrese el nivel del que desea listar las etiquetas:"<<endl;
                cin >> nivelDeseado;
                this->listarEtiquetasNivel(nivelDeseado);
            break;
            case 7:
                this->listarPreOrden();
            break;
            case 8:
                this->listarPorNiveles();
            case 9: // buscar Etiqueta
                cout << "A cual nodo desea buscar? " << endl;     
                cin >> accion;   
                nodo = BuscarEtiqueta(accion, arbol);
                if(nodo == nullptr){
                  cout << "No existe nodo con esa etiqueta " << endl;
                } else {
                  cout << "Si existe nodo con esa etiqueta " << endl;
                }
            break;
            case 10: //  Borrar sub árbol
              cout << "Cuál nodo desea borrar?\nDigite la etiqueta del nodo " << endl;
              cin >> accion;
              nodo = BuscarEtiqueta(accion, arbol);
              if(nodo == nullptr){
                cout << "No existe nodo con esa etiqueta " << endl;
              } else {
                EliminarSubarbol(BuscarEtiqueta(accion, arbol), arbol);
                cout << "Nodo eliminado" << endl;
              }
            break;
            case 11: // Construir arbol
              cout << "Se creará una lista con los números del 1 hasta el número que digite, y estos números formarán parte del nuevo árbol" << endl;
              cout << "La lista creada debe cumplir un tamaño igual a \n(k**i-1) / (k-1)\nDonde 'k' = hijos por nodo e 'i' = nivel de profundidad del arbol " << endl;
              cin >> accion;

              for(int ii = 1; ii <= accion ; ii++){ //bg
                lista.Insertar(ii, ii);
              }

              cout << "Ingrese la cantidad de hijos por nodo " << endl;
              cin >> accion;
              arbol = HacerArbol(accion, lista);
            break;
            default:
                accion=0;
            break;
        }
    }
}

void Algoritmos::cantidadNivelesPorNiveles(){
    if(this->arbol->NumNodos()!=0){
        contarNivelesR(this->arbol->Raiz(),1);
    }
    cout << "El nivel maximo del arbol es: "<<this->nivelMaximo<<endl;
}

void Algoritmos::contarNivelesR(Arbol::Nodo* nodo,int nivelActual){
    if(nivelActual>this->nivelMaximo){
        this->nivelMaximo=nivelActual;
    }
    nodo=this->arbol->HijoMasIzquierdo(nodo);
    nivelActual=nivelActual+1;
    while (nodo!=nullptr){
        contarNivelesR(nodo,nivelActual);
        nodo=this->arbol->HermanoDerecho(nodo);
    }
}

void Algoritmos::listarEtiquietasNivel(int nivelDeseado){
    if(this->arbol->NumNodos()!=0){
        listarEtiquietasNivelR(this->arbol->Raiz(),1,nivelDeseado);
    }
}

void Algoritmos::listarEtiquietasNivelR(Arbol::Nodo* nodo,int nivelActual,int nivelDeseado){
    if(nivelActual==nivelDeseado){
        cout<<this->arbol->Etiqueta(nodo)<<" ";
    }
    nodo=this->arbol->HijoMasIzquierdo(nodo);
    nivelActual=nivelActual+1;
    while (nodo!=nullptr){
        listarEtiquietasNivelR(nodo,nivelActual,nivelDeseado);
        nodo=this->arbol->HermanoDerecho(nodo);
    }
}
void Algoritmos::listarPreOrden(){
    if (this->arbol->NumNodos()!=0){
    listarPreOrdenR(this->arbol->Raiz());
    }
}
void Algoritmos::listarPreOrdenR(Arbol::Nodo* nodo){
    cout<<this->arbol->Etiqueta(nodo)<<" ";
    Arbol::Nodo* n1= this->arbol->HijoMasIzquierdo(nodo);
    while (n1 != nullptr){
    listarPreOrdenR(n1);
    n1 = this->arbol->HermanoDerecho(n1);
    }
}

void Algoritmos::listarPorNiveles(){
    if (this->arbol->NumNodos()!=0){
        Cola<Arbol::Nodo*> cola;
        cola.Iniciar();
        cola.Encolar(this->arbol->Raiz());
        while (cola.NumElem()!=0){
            Arbol::Nodo* nodo = cola.Desencolar();
            cout<<this->arbol->Etiqueta(nodo)<<" ";
            Arbol::Nodo* n1= this->arbol->HijoMasIzquierdo(nodo);
            while (n1 != nullptr){
                cola.Encolar(n1);
                n1 = this->arbol->HermanoDerecho(n1);
            }
        }
        cola.Destruir();
    }
}

Arbol::Nodo* Algoritmos::BuscarEtiqueta(int etiqueta, Arbol* A)
{
  Arbol::Nodo* tmp;
  ListaIndexada<Arbol::Nodo*> auxiliar;
  auxiliar.Insertar(A->Raiz(), auxiliar.NumElem()+1);
  int i = 1;
  //Se hace recorrido por niveles y se usa un if para encontrar el nodo buscado
  while(i <= auxiliar.NumElem())
  {
    tmp = auxiliar.Recuperar(i);
    i++;
    if(A->Etiqueta(tmp) == etiqueta) { return tmp; } 
    tmp = A->HijoMasIzquierdo(tmp);
    while(tmp != nullptr)
    {
      auxiliar.Insertar(tmp, auxiliar.NumElem()+1);
      tmp = A->HermanoDerecho(tmp);
    }
  }
  return nullptr;
}

void  Algoritmos::EliminarSubarbol(Arbol::Nodo* nodo, Arbol* A){
  Arbol::Nodo* tmp = A->HijoMasIzquierdo(nodo); //Hijo de nodo
  Arbol::Nodo* tmpHermanoDerecho; // Hermano derecho del hijo de nodo, existe porque se necesita guardar antes de que se elimine tmp al salir de la llamada recursiva en el while loop
  while(tmp != nullptr){
    tmpHermanoDerecho = A->HermanoDerecho(tmp);
    EliminarSubarbol(tmp, A);
    tmp = tmpHermanoDerecho;
  } 

  //Si se llegó al final del subárbol, se elimina la hoja y se crea un efecto dominó hacía arriba
  if(tmp == nullptr){
    A->BorrarHoja(nodo);
  }
}

Arbol* Algoritmos::HacerArbol(int nodosPorHijo, ListaIndexada<int> lista){
  Arbol* nuevoArbol = new Arbol();
  ListaIndexada<Arbol::Nodo*> auxiliar;
  int iLista = 1; 
  int iAuxiliar = 1;
  nuevoArbol->PonerRaiz(lista.Recuperar(iLista));
  iLista++; //Se suma 1 porque ya se añadió la raíz
  Arbol::Nodo* tmp = nuevoArbol->Raiz(); 

  //Se pasa por toda la lista dada
  while(iLista < lista.NumElem() ){
    //Agregando nodos correspondientes segun "nodosPorHijo" a tmp
    for(int ii = 0; ii < nodosPorHijo ; ii++){
      nuevoArbol->AgregarHijoMasDerecho(tmp, lista.Recuperar(iLista));
      iLista++;
    }
    //===========================  Guardando los nodos agregados para agregarles mas tarde los nodos correspondientes
    Arbol::Nodo* hijoDeTmp = nuevoArbol->HijoMasIzquierdo(tmp);
    while(hijoDeTmp != nullptr){
      auxiliar.Insertar(hijoDeTmp, auxiliar.NumElem()+1);
      hijoDeTmp = nuevoArbol->HermanoDerecho(hijoDeTmp);
    }
    //=====  

    //Sacando de auxiliar los nodos guardados para seguir agregando nodos
    tmp = auxiliar.Recuperar(iAuxiliar);
    iAuxiliar++;
  }
  return nuevoArbol;
}
