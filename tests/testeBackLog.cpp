#include <iostream>
#include "../include/backlog.hpp"

int main() {
    //TESTANDO BACKLOG
    Backlog b;
    Tarefa *aux;

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                     Teste 1 - INSERIR TAREFAS                  |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    char comando;
    std::cout << "            Deseja inserir uma tarefa no BackLog? [Y/N]           " << std::endl;
    std::cin >> comando;

    while(comando == 'Y' || comando == 'y'){
        int id, PontosDeEsforco;
        std::string instrucoes, status;

        std::cout << "Digite a ID da tarefa: ";
        std::cin >> id;
        std::cout << "Digite os pontos de prioridade da tarefa: ";
        std::cin >> PontosDeEsforco;
        std::cin.ignore();
        std::cout << "Digite as instruções da tarefa: ";
        std::getline(std::cin, instrucoes);
        std::cout << "Digite o Status da tarefa: ";
        std::getline(std::cin, status);

        Tarefa * t = new Tarefa(id, PontosDeEsforco, instrucoes, nullptr, status);
        b.addTarefa(t);
        std::cout << "------------------------------------------------------------------" << std::endl;

        std::cout << "         Deseja inserir mais uma tarefa no BackLog? [Y/N]         " << std::endl;
        std::cin >> comando;
    }
    std::cout << "\033[2J"; // Sequência de escape para limpar a tela
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                         TAREFAS INSERIDAS                      |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    b.consultar();

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                Teste 2 - BUSCAR TAREFA PELO ID                 |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    int ID;
    std::cout << "             Qual tarefa deseja buscar? (INFORME O ID)            " << std::endl;
    std::cin >> ID;
    aux = b.getTarefa(ID);
    std::cout << "\033[2J"; // Sequência de escape para limpar a tela
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                  TAREFA ENCONTRADA COM SUCESSO                 |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    aux->imprimirTarefa();

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                     Teste 3 - DELETAR TAREFAS                  |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "             Qual tarefa deseja deletar? (INFORME O ID)           " << std::endl;
    std::cin >> ID;
    aux = b.getTarefa(ID);
    b.deletarTarefa(aux);
    std::cout << "\033[2J"; // Sequência de escape para limpar a tela
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                    TAREFA DELETADA COM SUCESSO                  |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                           BACKLOG ATUAL                         |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    b.consultar();
    
    /*Não deu certo
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                     Teste 4 - ORDENAR TAREFAS                   |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    b.insertionSort();
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                  TAREFAS ORDENADAS COM SUCESSO                  |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    b.consultar();
    */

    return 0;
}