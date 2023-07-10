#include <iostream>
#include "../include/productOwner.hpp"
#include "../include/backlog.hpp"
#include "../include/sprint.hpp"

int main() {

    //Criação do Product Owner, Do ProductBackLog e da Sprint
    ProductOwner P = ProductOwner("Product Owner");
    Backlog B;

    std::cout << "Teste 1 - CRIAR TAREFAS" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    Tarefa a = Tarefa(5, 10, "Teste 1", nullptr, "PARA FAZER");
    Tarefa b = Tarefa(10, 20, "Teste 2", nullptr, "PARA FAZER");
    Tarefa c = Tarefa(15, 30, "Teste 3", nullptr, "PARA FAZER");
    Tarefa d = Tarefa(20, 40, "Teste 4", nullptr, "PARA FAZER");
    Tarefa e = Tarefa(25, 50, "Teste 5", nullptr, "PARA FAZER");
    Tarefa f = Tarefa(30, 60, "Teste 6", nullptr, "PARA FAZER");
    Tarefa g = Tarefa(35, 70, "Teste 7", nullptr, "PARA FAZER");
    Tarefa h = Tarefa(40, 80, "Teste 8", nullptr, "PARA FAZER");
    std::cout << "TAREFAS CRIADAS" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    std::cout << "Teste 2 - CADASTRAR TAREFAS NO BACKLOG" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    P.cadastrarTarefaBacklog(&B, &a);
    P.cadastrarTarefaBacklog(&B, &b);
    P.cadastrarTarefaBacklog(&B, &c);
    P.cadastrarTarefaBacklog(&B, &d);
    P.cadastrarTarefaBacklog(&B, &e);
    P.cadastrarTarefaBacklog(&B, &f);
    P.cadastrarTarefaBacklog(&B, &g);
    P.cadastrarTarefaBacklog(&B, &h);
    std::cout << "TAREFAS CADASTRADAS" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "Teste 3 - CONSULTAR TAREFAS BACKLOG" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    B.consultar();

    Sprint SP;

    std::cout << "Teste 4 - CADASTRAR DURAÇÃO DA SPRINT" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    P.cadastrarDuracaoDaSprint(&SP, 21);
    std::cout << "DURAÇÃO CADASTRADA" << std::endl;
    std::cout << "DURAÇÃO DA SPRINT: " << SP.getTempoDaSprint() << "DIAS" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    std::cout << "Teste 5 - CADASTRAR TAREFAS NA SPRINT" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    P.cadastrarTarefaSprint(&SP, &B, 5);
    P.cadastrarTarefaSprint(&SP, &B, 15);
    P.cadastrarTarefaSprint(&SP, &B, 20);
    P.cadastrarTarefaSprint(&SP, &B, 35);
    P.cadastrarTarefaSprint(&SP, &B, 40);
    std::cout << "TAREFAS CADASTRADAS" << std::endl;

    std::cout << "Teste 6 - CONSULTAR TAREFAS SPRINT" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    SP.gerarRelatorio();

    std::cout << "Teste 7 - DELETAR TAREFAS NA SPRINT" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    P.deletarTarefaSprint(&SP, &c);
    P.deletarTarefaSprint(&SP, &h);
    std::cout << "TAREFAS DELETADAS" << std::endl;

    std::cout << "Teste 8 - CONSULTAR TAREFAS SPRINT" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    SP.gerarRelatorio();

    std::cout << "Teste 9 - FALHA AO DELETAR TAREFAS NA SPRINT" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    P.deletarTarefaSprint(&SP, &b);
    P.deletarTarefaSprint(&SP, &f);

    std::cout << "Teste 10 - CONSULTAR TAREFAS SPRINT" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    SP.gerarRelatorio();

  return 0;
}