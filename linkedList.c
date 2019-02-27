#include <stdio.h>
#include <stdlib.h>
 /*Definimos estructura*/
typedef struct _Node {
        int data;
        struct _Node *next;
        } Node;
/*Declaramos prototipo de las funciones*/

void menu();
/*Funciones guardar información fila*/
Node * allocateMemory(int );
Node * pushFirst(Node *, int);
Node * pushLast(Node *, int);
Node * pushPosition(Node *, int, int);
Node * pushItem(Node *, int, int);
/*Funciones eliminar elemento fila*/
Node * popFirst(Node *);
Node * popLast(Node *);
Node * popPosition(Node *, int);
Node * popItem(Node *, int);
/*Funciones cambios en la lista*/
Node * changePosition(Node *, int);
Node * changeItem(Node *, int);
/*Función mostrar lista*/
void show(Node *);
/*Funcion tamaño lista*/
int theSize(Node *);
/*Funcion buscar elemento*/
int searchItem(Node *, int);


/*Inicia programa principal*/
int main(){
  menu();
  system("PAUSE");
  return 0;
}

/*Aquí empieza la sección de funciones*/

void menu(){
  int opt=0, data=0, position=0, item=0;
  Node *lista = NULL;
  do{
    printf("1. Ingresar dato\n2. Eliminar dato\n3. Cambiar dato\n4. Mostrar lista\n5. Mostrar tamano\nIngresa opcion deseada: ");
    fflush(stdin);
    scanf("%i", &opt);
    switch (opt){
        case 1:
          printf("1. Ingresar dato al principio\n2. Ingresar dato al final\n3. Ingresar dato por posicion\n4. Ingresar dato enfrente de un dato\nIngresa la opcion: ");
          scanf("%i", &opt);
          switch (opt){
              case 1:
                printf("Ingresa el dato: ");
                scanf("%i", &data);
                lista = pushFirst(lista, data);
              break;
          }
        break;
        case 5:
          show(lista);
        break;
    }
  } while (opt != -1);

}

Node *allocateMemory(int _data){
	Node *newNode;
	newNode = (Node *) malloc (sizeof(Node));
	newNode->data = _data;
	newNode->next = NULL;
	return newNode;
}

Node * pushFirst(Node *_lista, int _data){
  Node *newNode;
  newNode = allocateMemory(_data);
  if(_lista)
    newNode->next = _lista;
  return newNode;
}

void show(Node *_lista){
  if (_lista == NULL)
    printf("Tu lista esta vacia :^)");
  while(!_lista){
    printf("%i\t", _lista->data);
    _lista = _lista->next;
  }
  
}

