#include <iostream>
#include "../include/backlog.hpp"

int main() {

  //TESTANDO BACKLOG
  Backlog b;
  Tarefa x, y, z;
  Tarefa *aux;

  x = Tarefa(1, 23, "a", NULL, "INCIAL");
  //x.setProximo(&y);
  y = Tarefa(2, 13, "b", NULL, "PARA FAZER");
  //y.setProximo(&z);
  z = Tarefa(3, 33, "c", NULL, "EM ANDAMENTO");
  //z.setProximo(NULL);

  b.addTarefa(&x);
  b.addTarefa(&y);
  b.addTarefa(&z);
  b.consultar();

  //buscar atraves do id
  aux = b.getTarefa(2);
  aux->imprimirTarefa();
  
  //Deletar tarefa
  b.deletarTarefa(&y);
  b.consultar();

  return 0;
}