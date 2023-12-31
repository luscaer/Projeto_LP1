#include "tarefa.hpp"

class Backlog {
private:
  Tarefa *cabeca;
  Tarefa *cauda;
  int quantidade;

public:
  // construtores e destrutores
  Backlog();
  Backlog(Tarefa *cabeca, Tarefa *cauda, int quantidade);
  ~Backlog();

  // funções
  void setCabeca(Tarefa *h);
  Tarefa *getCabeca();
  void setCauda(Tarefa *t);
  Tarefa *getCauda();
  void setQuantidade(int quantidade);
  int getQuantidade();
  void addTarefa(Tarefa *t);
  void deletarTarefa(Tarefa *t);
  void consultar(); // mostrar tarefas do backlog
  Tarefa * getTarefa(int id);
};