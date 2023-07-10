#include "../include/listaDevs.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

listaDevs::listaDevs(){
  this->cauda = new Dev("CAUDA - NÃO DEVE SER ACESSADO");
  this->cabeca = new Dev("CABEÇA - NÃO DEVE SER ACESSADO");

  this->cabeca->setProximo(cauda);
  this->cabeca->setAnterior(nullptr);

  this->cauda->setProximo(nullptr);
  this->cauda->setAnterior(cabeca);

  this->quantidade = 0;
}

listaDevs::~listaDevs(){
  Dev* aux = this->cabeca;

  while(aux != nullptr)
  {
    Dev* proximo = aux->getProximo();
    delete aux;
    aux = proximo;
  }
}

Dev* listaDevs::getCabeca(){
  return this->cabeca;
}

Dev* listaDevs::getCauda(){
  return this->cauda;  
}

void listaDevs::setQuantidade(int quantidade){
  this->quantidade = quantidade;
}

int listaDevs::getQuantidade(){
  return this->quantidade;          
}

bool listaDevs::addDev(Dev *d){
  Dev * aux = new Dev();
  //Lista vazia, inserir após a cabeça.
  if(this->quantidade == 0){
    aux = d;

    aux->setProximo(this->cabeca->getProximo());
    aux->setAnterior(this->cabeca);
    this->cabeca->setProximo(aux);
    this->cauda->setAnterior(aux);

    this->quantidade++;
    return true;
  }
  //Vai adicionar sempre na posição após a cabeça, para depois usar algum método de ordenação.
  else{
    Dev * proximo = new Dev();
    proximo = d;
    proximo->setAnterior(cabeca);

    aux = this->cabeca->getProximo();
    proximo->setProximo(aux);
    aux->setAnterior(proximo);
    
    this->cabeca->setProximo(proximo);
    this->quantidade++;
    return true;
  }

  return false;
}

bool listaDevs::deletarTarefa(Dev * d){
  Dev* atual = this->cabeca->getProximo();
  Dev * proximo = new Dev();
  Dev * anterior = new Dev();
    
  while(atual != this->cauda){
    if(atual == d){
      proximo = atual->getProximo();
      anterior = atual->getAnterior();

      proximo->setAnterior(atual->getAnterior());
      anterior->setProximo(atual->getProximo());

      /*O problema da função está aqui:
      delete atual;
      */

      this->quantidade--;
      return true;
    }

    atual = atual->getProximo();
  }

  std::cout << "Não foi possível deletar!" << std::endl;
  return false;
}

//mostrar tarefas do backlog
void listaDevs::consultar(){
  if (this->quantidade == 0) {
    std::cout << "Backlog vazio." << std::endl;
    return;
  }

  Dev * atual = this->cabeca->getProximo();

  while (atual != this->cauda) {
    atual->imprimirDev();
    atual = atual->getProximo();
  }
}

//pega uma tarefa atraves do id
/*Dev * listaDevs::getTarefa(int id){
  Tarefa * atual = this->cabeca->getProximo();

  if(atual != this->cauda){
    for(int i=0;i<this->quantidade;i++){
      if(atual->getId()==id){
        return atual;
      }
      else{
        atual = atual->getProximo();
      }
    }
  }

  return nullptr;
}

/*orgnizar tarefas em ordem decrescente de acordo com os Pontos de esforço

bool Backlog::compararPorPontosDeEsforco(Tarefa* t1, Tarefa* t2) {
    return t1->getPontosDeEsforco() > t2->getPontosDeEsforco();
}

void Backlog::organizarTarefas() {
        if (this->cabeca->getProximo() == this->cauda) {
            // Não há tarefas no backlog
            return;
        }

        // Converte as tarefas para um vetor para facilitar a ordenação
        std::vector<Tarefa*> tarefas;
        Tarefa* atual = cabeca;
        while (atual != nullptr) {
            tarefas.push_back(atual);
            atual = atual->getProximo();
        }

        // Ordena as tarefas com base em PontosDeEsforco em ordem decrescente
        std::sort(tarefas.begin(), tarefas.end(), compararPorPontosDeEsforco);

        // Atualiza os ponteiros na lista encadeada
        cabeca = tarefas[0];
        cauda = tarefas[0];
        quantidade = 1;
        for (int i = 1; i < tarefas.size(); i++) {
            cabeca->setAnterior(tarefas[i]);
            tarefas[i]->setProximo(cabeca);
            cabeca = tarefas[i];
            quantidade++;
        }

        // Define o ponteiro da cauda como nullptr
        cauda->setProximo(nullptr);
    }
*/