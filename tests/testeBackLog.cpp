#include <iostream>
#include "../include/backlog.hpp"

int main() {
    //TESTANDO BACKLOG
    Backlog b;
    Tarefa x, y, z;
    Tarefa *aux;

    x = Tarefa(1, 23, "a", nullptr, "INCIAL");
    y = Tarefa(2, 13, "b", nullptr, "PARA FAZER");
    z = Tarefa(3, 33, "c", nullptr, "EM ANDAMENTO");

    std::cout << "Teste 1 - INSERIR TAREFAS" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    b.addTarefa(&x);
    b.addTarefa(&y);
    b.addTarefa(&z);
    b.consultar();

    std::cout << "Teste 2 - BUSCAR ATRAVÉS DO ID" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    aux = b.getTarefa(2);
    aux->imprimirTarefa();
    
    std::cout << "Teste 3 - DELETAR TAREFAS" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    b.deletarTarefa(&y);
    b.consultar();

    std::cout << "Teste 4 - ORGDENAR TAREFAS" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    b.organizarTarefas();

    return 0;
}