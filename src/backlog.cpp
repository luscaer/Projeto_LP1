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
        return true;
    }
    //Vai adicionar sempre na posição após a cabeça, para depois usar algum método de ordenação.
    else{
        Tarefa * proximo = new Tarefa();
        proximo = t;
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

bool Backlog::deletarTarefa(Tarefa * t){
    Tarefa * atual = new Tarefa();
    Tarefa * proximo = new Tarefa();
    Tarefa * anterior = new Tarefa();

    atual = this->cabeca->getProximo();
      
    while(atual != this->cauda){
        if(atual == t){
            proximo = atual->getProximo();
            anterior = atual->getAnterior();

            proximo->setAnterior(anterior);
            anterior->setProximo(proximo);

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

//mostrar tarefas do backlog
void Backlog::consultar(){
    if (this->quantidade == 0) {
        std::cout << "Backlog vazio." << std::endl;
        return;
    }

    Tarefa * atual = this->cabeca->getProximo();

    while (atual != this->cauda) {
        atual->imprimirTarefa();
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

/*Orgnizar tarefas em ordem decrescente de acordo com os Pontos de esforço

bool Backlog::compararPorPontosDeEsforco(Tarefa* t1, Tarefa* t2) {
    return t1->getPontosDeEsforco() > t2->getPontosDeEsforco();
}

void Backlog::organizarTarefas() {
        if (this->cabeca->getProximo() == this->cauda) {
            // Não há tarefas no backlog
            std::cout << "Não há tarefas no backlog" << std::endl;
            return;
        }

        // Converte as tarefas para um vetor para facilitar a ordenação
        std::vector<Tarefa*> tarefas;
        Tarefa* atual = this->cabeca;
        while (atual != this->cauda) {
            tarefas.push_back(atual);
            atual = atual->getProximo();
        }

        // Ordena as tarefas com base em PontosDeEsforco em ordem decrescente
        std::sort(tarefas.begin(), tarefas.end(), compararPorPontosDeEsforco);

        //Deleta os ponteiros desordenados da lista encadeada
        Tarefa * atual = new Tarefa();
        Tarefa * proximo = new Tarefa();
        Tarefa * anterior = new Tarefa();

        atual = this->cabeca->getProximo();

        while(atual != this->cauda){
            proximo = atual->getProximo();
            anterior = atual->getAnterior();

            proximo->setAnterior(anterior);
            anterior->setProximo(proximo);

            //O problema da função está aqui:
            delete atual;

            this->quantidade--;
            atual = proximo;
        }

        // Atualiza os ponteiros na lista encadeada
        this->cabeca->setProximo(tarefas[0]);
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