#include "../include/sprint.hpp"
#include <iostream>

Sprint::Sprint(){
  this->cauda = new Tarefa("CAUDA - NÃO DEVE SER ACESSADO");
  this->cabeca = new Tarefa("CABEÇA - NÃO DEVE SER ACESSADO");

  this->cabeca->setProximo(cauda);
  this->cabeca->setAnterior(nullptr);

  this->cauda->setProximo(nullptr);
  this->cauda->setAnterior(cabeca);

  this->tempoDaSprint = 0; //Tempo máximo para sprint.
  this->quantidade = 0; //Qauntidade de tarefas na sprint
}

Sprint::~Sprint(){}

void Sprint::setTempoDaSprint(int tempo){
  this->tempoDaSprint = tempo;
}
int Sprint::getTempoDaSprint(){
  return tempoDaSprint;
}
void Sprint::setQuantidade(int quantidade){
  this->quantidade = quantidade;
}
int Sprint::getQuantidade(){
  return this->quantidade;
}

bool Sprint::addTarefa(Backlog * b, int id){
  Tarefa * aux = new Tarefa();
  //Lista vazia, inserir após a cabeça.
  if(this->quantidade == 0){
    aux = b->getTarefa(id);

    aux->setProximo(this->cabeca->getProximo());
    aux->setAnterior(this->cabeca);
    this->cabeca->setProximo(aux);
    this->cauda->setAnterior(aux);

    this->quantidade++;
    return true;
  }
  //Vai adicionar sempre na posição após a cabeça, para depois usar algum método de ordenação.
  else{
    Tarefa * proximo = b->getTarefa(id);
    proximo->setAnterior(cabeca);

    aux = this->cabeca->getProximo();
    proximo->setProximo(aux);
    aux->setAnterior(proximo);
    
    this->cabeca->setProximo(proximo);
    this->quantidade++;
    return true;
  }
}

bool Sprint::deletarTarefa(Tarefa * t){
  Tarefa * atual = this->cabeca->getProximo();
  Tarefa * proximo = new Tarefa();
  Tarefa * anterior = new Tarefa();
    
  while(atual != this->cauda){
    if(atual == t){
      proximo = atual->getProximo();
      anterior = atual->getAnterior();

      proximo->setAnterior(atual->getAnterior());
      anterior->setProximo(atual->getProximo());

      /*Quando tento usar delete atual o programa para de executar e exibe a mensagem:
      free(): invalid pointer
      Aborted
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

Tarefa * Sprint::getTarefa(int id){
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

//Gerar relatório.
void Sprint::gerarRelatorio(){
  if (this->quantidade == 0) {
    std::cout << "Sprint vazia." << std::endl;
    return;
  }

  Tarefa * atual = this->cabeca->getProximo();

  while (atual != this->cauda) {
    atual->imprimirTarefa();
    atual = atual->getProximo();
  }
}

//Gerar relatório por desenvolvedor/pessoa (aqui implementa algoritmo de ordenação). (Ordem alfabética?)
void Sprint::gerarRelatorioDeDev(Pessoa * p){
  
}

//Operações para Devs.
void Sprint::realizarTarefas(Pessoa * Responsavel, string instrucoes){
    Tarefa * atual = this->cabeca->getProximo();

    while(atual != this->cauda){
        if(atual->getResponsavel() == Responsavel){
            atual->setInstrucoes(instrucoes);
        }
        atual = atual->getProximo();
    }
}

void Sprint::RealizarTarefaEspecifica(Pessoa * Responsavel, string instrucoes, Tarefa * tarefa){
    Tarefa * atual = this->cabeca->getProximo();

    while(atual != this->cauda){
        if(atual->getResponsavel() == Responsavel){
            if(atual == tarefa){
                atual->setInstrucoes(instrucoes);
            }
        }
        atual = atual->getProximo();
    }
}

//bool Sprint::ordenarAlfabetico() {}
//bool Sprint::ordenarPorPrioridade() {}