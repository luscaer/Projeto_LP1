#ifndef BACKLOG_HPP
#define BACKLOG_HPP

#include "tarefa.hpp"

class Backlog {
private:
  Tarefa *cabeca;
  Tarefa *cauda;
  int quantidade;

public:
  // construtores e destrutores
  Backlog();
  ~Backlog();

  // funções
  void setCabeca(Tarefa *h);
  Tarefa *getCabeca();
  void setCauda(Tarefa *t);
  Tarefa *getCauda();
  void setQuantidade(int quantidade);
  int getQuantidade();
  bool addTarefa(Tarefa *t);
  bool deletarTarefa(Tarefa *t);
  void consultar(); // mostrar tarefas do backlog
  Tarefa * getTarefa(int id);
};

#endif