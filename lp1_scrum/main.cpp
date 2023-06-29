#include <iostream>
#include "include/backlog.h"

int main() {

  //TESTANDO BACKLOG
  Backlog b;
  Tarefa x, y, z;

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
  
  cout << "deletando" << endl;
  b.deletarTarefa(&y);
  b.consultar();
}