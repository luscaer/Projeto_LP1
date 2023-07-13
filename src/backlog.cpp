#include "../include/backlog.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Backlog::Backlog(){
  this->cauda = new Tarefa("CAUDA - NÃO DEVE SER ACESSADO");
  this->cabeca = new Tarefa("CABEÇA - NÃO DEVE SER ACESSADO");

  this->cabeca->setProximo(cauda);
  this->cabeca->setAnterior(nullptr);

  this->cauda->setProximo(nullptr);
  this->cauda->setAnterior(cabeca);

  this->quantidade = 0;
}

Backlog::~Backlog(){
  Tarefa* aux = this->cabeca;

  while(aux != nullptr)
  {
    Tarefa* proximo = aux->getProximo();
    delete aux;
    aux = proximo;
  }
}

Tarefa* Backlog::getCabeca(){
  return this->cabeca;
}

Tarefa* Backlog::getCauda(){
  return this->cauda;  
}

void Backlog::setQuantidade(int quantidade){
  this->quantidade = quantidade;
}

int Backlog::getQuantidade(){
  return this->quantidade;          
}

bool Backlog::addTarefa(Tarefa * t){
  Tarefa * aux = new Tarefa();
  //Lista vazia, inserir após a cabeça.
  if(this->quantidade == 0){
    aux = t;

    aux->setProximo(this->cabeca->getProximo());
    aux->setAnterior(this->cabeca);
    this->cabeca->setProximo(aux);
    this->cauda->setAnterior(aux);

    this->quantidade++;

    //organizarTarefas();
    return true;
  }
  //Vai adicionar sempre na posição após a cabeça, para depois usar algum método de ordenação.
  else{
     Tarefa * proximo = new Tarefa();
    // Tarefa * aux;
    // Tarefa * lista;
     proximo = t;

    // if(proximo->getPontosDeEsforco() > cabeca->getPontosDeEsforco()){
    //   aux = cabeca->getProximo();
    //   cabeca->setAnterior(proximo);
    //   cabeca->setProximo(proximo->getProximo());
    //   proximo->setProximo(cabeca);
    //   proximo->setAnterior(NULL);

    //   cabeca = proximo;
    //   proximo = aux;

    //   this->quantidade++;
    // }else{
    //     lista = cabeca->getProximo();
    //   do{
    //     aux = lista->getProximo();
    //     if(proximo->getPontosDeEsforco() > lista->getPontosDeEsforco() && aux->getPontosDeEsforco() < proximo->getPontosDeEsforco() && lista->getId() != 0){
    //       aux = lista->getProximo();
    //       lista->setAnterior(proximo);
    //       lista->setProximo(proximo->getProximo());
    //       proximo->setProximo(lista);
    //       proximo->setAnterior(lista->getAnterior());

    //       aux = lista;
    //       lista = proximo;
    //       proximo = aux;

    //       this->quantidade++;
    //     }else{
    //       lista = lista->getProximo();
    //     }
    //     //lista = cabeca->getProximo();
  
    //   }while (aux != NULL);
      
      
    // }


    proximo->setAnterior(cabeca);

    aux = this->cabeca->getProximo();
    proximo->setProximo(aux);
    aux->setAnterior(proximo);
    
    this->cabeca->setProximo(proximo);
    this->quantidade++;

    //organizarTarefas();
    return true;
  }

  //organizarTarefas();

  return false;
}

bool Backlog::deletarTarefa(Tarefa * t){
  Tarefa * atual = this->cabeca->getProximo();
  Tarefa * proximo = new Tarefa();
  Tarefa * anterior = new Tarefa();
    
  while(atual != this->cauda){
    if(atual == t){
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
void Backlog::consultar(){
  if (this->quantidade == 0) {
    std::cout << "Backlog vazio." << std::endl;
    return;
  }

  int aux = this->quantidade;

  Tarefa * atual = this->cabeca->getProximo();

  while (aux > 0) {
    aux--;
    if(atual != this->cauda){
      atual->imprimirTarefa();
    }
    atual = atual->getProximo();
  }
}

//pega uma tarefa atraves do id
Tarefa * Backlog::getTarefa(int id){
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

// //orgnizar tarefas em ordem decrescente de acordo com os Pontos de esforço

// bool Backlog::compararPorPontosDeEsforco(Tarefa* t1, Tarefa* t2) {
//     return t1->getPontosDeEsforco() > t2->getPontosDeEsforco();
// }

// void Backlog::organizarTarefas() {
//         Tarefa * tarefaAtuali = this->cabeca->getProximo();
//         Tarefa * tarefaAtualj = this->cabeca->getProximo();
//         Tarefa * aux;
//         Tarefa * anterio;
//         Tarefa * proximo;


//         for(int i = 0; i< this->getQuantidade();i++){
//           if(tarefaAtuali != NULL){
//             Tarefa * tarefaAtualj = this->cabeca->getProximo();
//             for(int j = i+1;j<this->getQuantidade();j++){
//               if(tarefaAtualj != NULL){
//                 if(tarefaAtuali->getPontosDeEsforco() > tarefaAtualj->getPontosDeEsforco()){
//                   tarefaAtualj = tarefaAtualj->getProximo();
//                 }else{
//                   aux = tarefaAtualj->getProximo();

//                   if(tarefaAtuali->getPontosDeEsforco() > aux->getPontosDeEsforco()){
//                     aux = tarefaAtuali;

//                     anterio = tarefaAtuali->getAnterior();
//                     proximo = tarefaAtualj->getProximo();
                    
//                     tarefaAtuali = tarefaAtualj;
//                     tarefaAtualj = tarefaAtuali;

//                     tarefaAtuali->setProximo(tarefaAtualj);
//                     tarefaAtuali->setAnterior(anterio);

//                     tarefaAtualj->setAnterior(tarefaAtuali);
//                     tarefaAtualj->setProximo(proximo);
//                   }else{
//                     tarefaAtualj = tarefaAtualj->getProximo();
//                   }
//                 }
//               }
//             }
//           }else{
//             break;
//           }
//           tarefaAtuali = tarefaAtuali->getProximo();
//         }

//     }
