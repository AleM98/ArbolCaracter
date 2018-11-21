#include <iostream>
#include <cstdlib>
#include<stdio.h>

using namespace std;

struct nodo{
     char nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ABoBi;

void enOrden(ABoBi);
void verArbol(ABoBi, char);

int main()
{
	system("COLOR 3F");
    ABoBi arbol = NULL;   // ARBOL CREADO

    int n;  // EL NUMERO DE NODOS QUE DESEA AGREGAR AL ARBOL
    char x[2]; // ELEMENTO A INSERTAR EN CADA NODO

    cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";

    cout << " INGRESE EL NUMERO DE NODOS A INGRESAR EN EL ARBOL:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " NUMERO DEL NODO " << i+1 << ": ";
        cin.getline(x, 2, '\n');
        insertar( arbol, x);
    }

    cout << "\n Mostrando ABB \n\n";
    verArbol( arbol, 0);

    cout << "\n Recorridos del ABB";

    cout << "\n\n PRE-ORDEN  :  ";   preOrden(arbol);
	cout << "\n\n IN-ORDEN   :  ";   enOrden(arbol);
    cout << "\n\n POST-ORDEN :  ";   postOrden(arbol);
    

    cout << endl << endl;

    system("pause");
    return 0;
}

void enOrden(ABoBi arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

void verArbol(ABoBi arbol, char n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);
     
     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}
