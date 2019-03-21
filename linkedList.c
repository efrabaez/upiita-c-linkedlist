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
Node * changePosition(Node *, int, int);
Node * changeItem(Node *, int, int);
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
  Node *list = NULL;
  do{
    printf("\n1. Ingresar dato\n2. Eliminar dato\n3. Cambiar dato\n4. Mostrar lista\n5. Mostrar tamano\nIngresa opcion deseada: ");
    fflush(stdin);
    scanf("%i", &opt);
    switch (opt){
        case 1:
          printf("\n1. Ingresar dato al principio\n2. Ingresar dato al final\n3. Ingresar dato por posicion\n4. Ingresar dato enfrente de un dato\nIngresa la opcion: ");
          scanf("%i", &opt);
          switch (opt){
              case 1:
                printf("Ingresa el dato: ");
                scanf("%i", &data);
                list = pushFirst(list, data);
              break;
              case 2:
                printf("Ingresa el dato: ");
                scanf("%i", &data);
                list = pushLast(list, data);                
              break;
              case 3:
                printf("Ingresa el dato: ");
                scanf("%i", &data);
                printf("Ingresa la posicion (Empezando desde 0): ");
                scanf("%i", &position);
                list = pushPosition(list, data, position); 
              break;
              case 4:
                printf("Ingresa el dato: ");
                scanf("%i", &data);
                printf("Ingresa antes de que dato se insertara: ");
                scanf("%i", &item);
                list = pushItem(list, data, item); 
              break;
          }
        break;
        case 2:
          printf("\n1. Eliminar primer elemento\n2. Eliminar elemento final\n3. Eliminar elemento por posicion\n4. Eliminar elemento por dato\nIngresa la opcion: ");
          scanf("%i", &opt);
          switch (opt){
              case 1:
                list = popFirst(list);
              break;
              case 2:
                list = popLast(list);
              break;
              case 3:
                printf("Ingresa la posicion (Empezando desde 0): ");
                scanf("%i", &position);
                list = popPosition(list, position);
              break;
              case 4:
                printf("Ingresa antes de que dato se va a eliminar: ");
                scanf("%i", &item);
                list = popItem(list, item);
              break;
          }          
        break;
        case 3:
          printf("\n1. Cambiar informacion por posicion\n2. Cambiar informacion por dato\nIngresa la opcion: ");
          scanf("%i", &opt);
          switch (opt){
              case 1:
                printf("Ingresa el nuevo dato: ");
                scanf("%i", &data);
                printf("Ingresa la posicion del cambio: ");
                scanf("%i", &position);
                list = changePosition(list, data, position);
              break;
              case 2:
                printf("Ingresa el nuevo dato: ");
                scanf("%i", &data);
                printf("Ingresa el dato a reemplazar: ");
                scanf("%i", &item);
                list = changeItem(list, data, item);                
              break;
          }             
        break;
        case 4:
          show(list);
        break;
        case 5:
          printf("El tamano es: %i", theSize(list));
        break;
    }
  }while (opt != -1); 
}


/*Aquí comienzan las funciones del programa*/

/*Inicio bloque insertar datos*/
Node *allocateMemory(int _data){
	Node *newNode = NULL;
	newNode = (Node *) malloc (sizeof(Node));
	newNode->data = _data;
	newNode->next = NULL;
	return newNode;
}

Node * pushFirst(Node *_list, int _data){
  Node *newNode = NULL;
  newNode = allocateMemory(_data);
  if(_list)
    newNode->next = _list;
  return newNode;
}

Node * pushLast(Node *_list, int _data){
  Node *newNode = NULL, *listAux = NULL;
  newNode = allocateMemory(_data);
  if (!_list){
    _list = newNode;
  }
  else{
    listAux = _list;
    while(listAux->next){
      listAux=listAux->next;
    }
    listAux->next = newNode;
  }
  return _list;
}

Node * pushPosition(Node *_list, int _data, int _position){
  Node * newNode = NULL, *listAux = NULL;
  int listSize = 0, i = 0;
  listSize = theSize(_list);
  if (listSize){
    if (_position <= 0){
      _list = pushFirst(_list, _data);
    }else if (_position >= listSize){
      _list =  pushLast(_list, _data);
    }else{
      listAux = _list;
      newNode = allocateMemory(_data);
      for(i=1; i < _position; i++){
        printf("%i", i);
        listAux = listAux->next;
      }
      newNode->next = listAux->next;
      listAux->next = newNode;
    }  
  }else{
    _list =  pushFirst(_list, _data);
  }
  return _list;
}

Node * pushItem(Node *_list, int _data, int _item){
  int position = 0;
  position = searchItem(_list, _item);
  _list = pushPosition(_list, _data, position);
  return _list;
}

/*Inicio bloque borrar datos*/
Node * popFirst(Node *_list){
  Node *listAux = NULL;
  if (_list) {
    listAux=_list;
    _list=_list->next;
    free(listAux);
  }
  return _list;
}

Node * popLast(Node *_list){
  Node *listAux = NULL, *listDelete = NULL;
  if (_list){
    if (!_list->next){
      return popFirst(_list);
    }else{
      listAux = _list;
      while(listAux->next->next){
        listAux = listAux->next;
      }
      listDelete = listAux->next;
      listAux->next = NULL;
      free(listDelete);
    }
  }
  return _list;
}

Node * popPosition(Node *_list, int _position){
  Node *listAux = NULL, *listDelete = NULL;
  int listSize = 0, i = 0;
  listSize = theSize(_list);
  if (listSize) {
    if (_position <= listSize) {
      listAux = _list;
      for(i = 1; i < _position; i++){
        listAux = listAux->next;
      }
      listDelete = listAux->next;
      listAux->next = listDelete->next;
      free(listDelete);
    }else{
      printf("Posicion inexistente");
    }
  }else{
    printf("La lista no tiene elementos");
  }
  return _list;
}

Node * popItem(Node *_list, int _item){
  int position = 0;
  position = searchItem(_list, _item);
  _list = popPosition(_list, position);
  return _list;
}

/*Inicio bloque cambios*/
Node * changePosition(Node *_list, int _data, int _position){
  Node *listAux = NULL;
  int listSize = 0, i=0;
  listSize = theSize(_list);
  if (listSize) {
    if (_position <= listSize) {
      listAux = _list;
      for(i = 1; i <= _position; i++){
        listAux = listAux->next;
      }
      listAux->data = _data;
    }else{
      printf("Posicion inexistente");
    }
  }else{
    printf("La lista no tiene elementos");
  }
  return _list;  
}

Node * changeItem(Node *_list, int _data, int _item){
  int position = 0;
  position = searchItem(_list, _item);
  _list = changePosition(_list, _data, position);
  return _list;
}

/*Inicio bloque mostrar, tamaño y buscar*/
void show(Node *_list){
  if (!_list){
    printf("Vacia");
  }
  while(_list){
    printf("%i\t", _list->data);
    _list = _list->next;
  } 
}

int theSize(Node *_list){
  int listSize = 0;
  while(_list){
    listSize++;
    _list=_list->next;
  }
  return listSize;
}

int searchItem(Node * _list, int _data){
  int position = 0;
  while(_list){
    if (_list->data == _data) {
      break;
    }
    _list = _list->next;
    position++;
  }
  return position;
}
