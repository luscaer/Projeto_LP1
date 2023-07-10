#ifndef LISTADEVS_HPP
#define LISTADEVS_HPP

#include "dev.hpp"

class listaDevs {
private:
  Dev *cabeca;
  Dev *cauda;
  int quantidade;

public:
  // construtores e destrutores
    listaDevs();
    ~listaDevs();

  // funções
  Dev *getCabeca();
  Dev *getCauda();
  void setQuantidade(int quantidade);
  int getQuantidade();
  bool addDev(Dev *d);
  bool deletarTarefa(Dev *d);
  void consultar();
  //Dev * getTarefa(int id);
 
};

#endif