#include <iostream>
#include "../include/scrumMaster.hpp"
#include "../include/productOwner.hpp"
#include "../include/backlog.hpp"

int main() {
    //Criação do Product Owner, Do ProductBackLog e da Sprint
    ProductOwner P = ProductOwner("Product Owner");
    Backlog B;
    Tarefa a = Tarefa(5, 10, "Teste 1", nullptr, "PARA FAZER");
    Tarefa b = Tarefa(10, 20, "Teste 2", nullptr, "PARA FAZER");
    Tarefa c = Tarefa(15, 30, "Teste 3", nullptr, "PARA FAZER");
    Tarefa d = Tarefa(20, 40, "Teste 4", nullptr, "PARA FAZER");
    Tarefa e = Tarefa(25, 50, "Teste 5", nullptr, "PARA FAZER");
    Tarefa f = Tarefa(30, 60, "Teste 6", nullptr, "PARA FAZER");
    Tarefa g = Tarefa(35, 70, "Teste 7", nullptr, "PARA FAZER");
    Tarefa h = Tarefa(40, 80, "Teste 8", nullptr, "PARA FAZER");


    P.cadastrarTarefaBacklog(&B, &a);
    P.cadastrarTarefaBacklog(&B, &b);
    P.cadastrarTarefaBacklog(&B, &c);
    P.cadastrarTarefaBacklog(&B, &d);
    P.cadastrarTarefaBacklog(&B, &e);
    P.cadastrarTarefaBacklog(&B, &f);
    P.cadastrarTarefaBacklog(&B, &g);
    P.cadastrarTarefaBacklog(&B, &h);
    std::cout << "Teste 1 - CONSULTAR TAREFAS BACKLOG" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    B.consultar();

    Sprint S;

    P.cadastrarDuracaoDaSprint(&S, 21);

    P.cadastrarTarefaSprint(&S, &B, 5);
    P.cadastrarTarefaSprint(&S, &B, 15);
    P.cadastrarTarefaSprint(&S, &B, 20);
    P.cadastrarTarefaSprint(&S, &B, 35);
    P.cadastrarTarefaSprint(&S, &B, 40);
    std::cout << "Teste 2 - CONSULTAR TAREFAS SPRINT" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    S.gerarRelatorio();

    //Criação dos Devs
    Dev v = Dev("Nome 1");
    Dev w = Dev("Nome 2");
    Dev x = Dev("Nome 3");
    Dev y = Dev("Nome 4");
    Dev z = Dev("Nome 5");

    //Criação da lista encadeada de devs (Por enquanto não vai servir para nada).

    v.setAnterior(nullptr);
    v.setProximo(&w);
    w.setAnterior(&v);
    w.setProximo(&x);
    x.setAnterior(&w);
    x.setProximo(&y);
    y.setAnterior(&x);
    y.setProximo(&z);
    z.setAnterior(&y);
    z.setProximo(nullptr);

    //Criação do Scrum Master
    std::string nome;
    std::cout << "Digite o nome do Scrum Master: ";
    std::getline(std::cin, nome);

    ScrumMaster SM = ScrumMaster(nome);
    
    std::cout << "Olá " << nome << ". Seja bem vindo ao atribuidor de Tarefas!" << std::endl;
    std::cout << "Deseja atribuir uma tarefa? [Y/N]" << std::endl;

    char comando;
    std::cin >> comando;
    if(comando == 'N' || comando == 'n'){
        std::cout << "Ok, tenha um bom dia!" << std::endl;
        return 0;
    }

    std::cout << "SPRINT ATIVA:" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    S.gerarRelatorio();

    //Implementar um while quando fizermos as funções para operar com a lista encadeada de devs.

    SM.atribuirTarefaAPessoa(&S, 5, &w);
    SM.atribuirTarefaAPessoa(&S, 15, &z);
    SM.atribuirTarefaAPessoa(&S, 20, &x);
    SM.atribuirTarefaAPessoa(&S, 35, &v);
    SM.atribuirTarefaAPessoa(&S, 40, &y);

    std::cout << "Teste 3 - SPRINT APÓS ATRIBUIÇÕES" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    S.gerarRelatorio();

    return 0;
}