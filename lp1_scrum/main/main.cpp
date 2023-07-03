#include <iostream>
#include "include/sprint.h"
//#include "include/sprint.h"

int main() {

  //TESTANDO BACKLOG
  Backlog b;
  Sprint s;
  Tarefa x, y, z;
  Tarefa *aux;

  x = Tarefa(1, 23, "a", NULL, "INCIAL");
  //x.setProximo(&y);
  y = Tarefa(2, 13, "b", NULL, "INCIAL");
  //y.setProximo(&z);
  z = Tarefa(3, 33, "c", NULL, "INCIAL");
  //z.setProximo(NULL);

  b.addTarefa(&x);
  b.addTarefa(&y);
  b.addTarefa(&z);
  b.consultar();

  //buscar atraves do id
  aux = b.getTarefa(2);

  aux->imprimirTarefa();
  
  //cout << "deletando" << endl;
  //b.deletarTarefa(&y);
  //b.consultar();
}