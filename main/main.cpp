// #include <iostream>
// #include "../include/sprint.hpp"
// //#include "include/sprint.h"

// int main() {

//   //TESTANDO BACKLOG
//   Backlog b;
//   Sprint s;
//   Tarefa x, y, z;
//   Tarefa *aux;

//   x = Tarefa(1, 23, "a", NULL, "INCIAL");
//   //x.setProximo(&y);
//   y = Tarefa(2, 13, "b", NULL, "INCIAL");
//   //y.setProximo(&z);
//   z = Tarefa(3, 33, "c", NULL, "INCIAL");
//   //z.setProximo(NULL);

//   b.addTarefa(&x);
//   b.addTarefa(&y);
//   b.addTarefa(&z);
//   b.consultar();

//   //buscar atraves do id
//   aux = b.getTarefa(2);

//   aux->imprimirTarefa();
  
//   //cout << "deletando" << endl;
//   //b.deletarTarefa(&y);
//   //b.consultar();
// }



//MENU
#include <iostream>
#include "../include/productOwner.hpp"
#include "../include/backlog.hpp"
#include "../include/sprint.hpp"
#include "../include/scrumMaster.hpp"
#include "../include/tester.hpp"
#include "../include/listaDevs.hpp"

using namespace std;

Sprint * S = new Sprint();



//vai funcionar um projeto por vez
int main(){

    /*
        Para que serve cada variavel
        Projeto: é o nome do projeto
        validacao: Serve para verificar se o projeto foi inicializado ou não
        existMembros: serve para validade se existe membros cadastrados no projeto ou não
        opcao: serve para armazenar a opcao que o usuario escolher no menu inicial (primeiro switch case)
        op1: serve para armazenar a opcao que o usuario escolher no menu do projeto (segundo switch case)
        op2: serve para armazenar a opcao que o usuario escolher no menu de cadastramento dos membros (switch case dentro do segundo switch case)
        op3: serve para armazenar a opcao que o usuario escolher no menu de "assumir" uma funcao de um membro cadastrado.
        op4: serve para armazenar a opcao que o usuario escolher no menu das funções do Product Owner
        op5: serve para armazenar a opcao que o usuario escolher no menu das funções do Scrum Master
        op6: serve para armazenar a opcao que o usuario escolher no menu das funções dos Desenvolvedores
        op7: serve para armazenar a opcao que o usuario escolher no menu das funções do tester
        op8: serve para armazenar a opcao que o usuario escolher no menu da sprint
        existePD: serve para verificar se existe um Product Owner
        existeSM: serve para verificar se existe um Scrum Master
        existeDev: serve para verificar se existe pelo menos um desenvolvedor
        existeT: serve para verificar se existe pelo menos um tester
        existeSprint: verifica se uma sprint foi iniciada ou não
        existeBacklog:verifica se o backlog foi iniciado ou não
        PD, SM, D, T: SÃO MEMBROS
        listaDevs: lista de desenvolvedores
        listaEnd: lista de endereço dos desenvolvedores, usada quando tem mais de um dev
        qntEnd: quantidade de endereços de desenvolvedores, usada quando tem mais de um dev
           */

    string projeto = "";
    char escolha, cadastroMembros;
    bool validacao = false, existeMembros = false, existePD = false, existeDev = false, existeSM = false, existeT = false, existeSprint = false, existeBacklog= false; 
    int opcao = -1, op1 = -1, op2 = -1, op3 = -1, op4 = -1, op5 = -1, op6 = -1, op7 =-1, op8 = -1;
    
    ProductOwner PD = ProductOwner();
    ScrumMaster SM = ScrumMaster();
    Dev D =  Dev();
    Tester T = Tester();
    listaDevs listaDevs;
    
    Dev * listaEnd = new Dev[100];
    int qntEnd = 0;
    
    Backlog b = Backlog();
    Tarefa * listaEndTarefas = new Tarefa[100];
    int qntEndT = 0;


    for(int i = 0;i<100;i++){
        listaEnd[i] = Dev();
        listaEndTarefas[i] = Tarefa();
    }
                                              

    //primeiro vamos inicializar o projeto
    //Menu de inicialização;

    do{
        //caso não exista projeto
        if(validacao == false){
            cout << "-------------------------------------" << endl;
            cout << "MENU INICIAL" << endl;
            cout << "-------------------------------------" << endl;
            cout << "1 - Iniciar projeto" << endl;
            cout << "0 - Encerrar processo" << endl;
            cin >> opcao;
        }
        //caso exista projeto
        else if(validacao == true){
            cout << "-------------------------------------" << endl;
            cout << "MENU INICIAL" << endl;
            cout << "-------------------------------------" << endl;
            cout << "2 - Entrar no projeto " << projeto << endl;
            cout << "0 - Encerrar processo" << endl;
            cin >> opcao;
        }

        switch (opcao)
        {
            case 0: break;

            //caso 1 é ondo inicilizamos o projeto com seu nome
            case 1:{
                //garantir que o projeto não foi inicializado
                if(validacao == false){
                    do{
                    //Garantir que o projeto tenha um nome
                    cout <<"Insira o nome do projeto:" << endl;
                    cin.ignore();
                    getline(cin, projeto);

                    //caso o nome estaja em branco vai repetir validacao vai ser falsa
                    if(projeto == "" || projeto[0] == ' '){
                        validacao = false;
                        cout << "NOME INVALIDO!" << endl;
                        cout << "Deseja sair?[s/n]";
                        cin >> escolha;

                        if(escolha == 's' || escolha == 'S'){break;}
                    }
                    //validacao vai ser verdadeira
                    else if(projeto != "" || projeto[0] != ' '){validacao = true;}
                    
                
                    }while(projeto == "" || projeto[0] == ' ');

                }
                
                //a validacao vai servir para abrir o proximo menu, ela so é true quando o nome do projeto é valido, o que significa que foi inicializado
        
                break;
            }

            //caso 2 abre o menu do projeto caso for inicializado
            case 2:{
                    if(validacao == true){
                
                        //abre o proximo menu
                            do{
                                //menu caso não tenha membros cadastrados no projeto
                                if(existeMembros == false){
                                    cout << "-------------------------------------" << endl;
                                    cout << "MENU DO PROJETO: " << projeto << endl;
                                    cout << "-------------------------------------" << endl;
                                    cout << "1 - Cadastrar membros" << endl;
                                    cout << "0 - voltar" << endl;
                                    cin >> op1;
                                }
                                else if(existeMembros == true && existeSprint == true){
                                    cout << "-------------------------------------" << endl;
                                    cout << "MENU DO PROJETO: " << projeto << endl;
                                    cout << "-------------------------------------" << endl;
                                    cout << "1 - Cadastrar novos membros" << endl;
                                    cout << "2 - Listar membros" << endl;
                                    cout << "3 - Consultar Backlog " << endl;
                                    cout << "4 - Entrar como membro" << endl; //nessa opçao o usuario entra como membro para executar as funções de cada um
                                    cout << "6 - Sprint" << endl; //duração de 1-4 semanas, deixar como padrao 4 semanas? ou deixar o usuario escolher?
                                    cout << "0 - voltar" << endl;
                                    cin >> op1;


                                }
                                
                                //menu caso exista membros cadastrados no projeto
                                else if(existeMembros == true){
                                    cout << "-------------------------------------" << endl;
                                    cout << "MENU DO PROJETO: " << projeto << endl;
                                    cout << "-------------------------------------" << endl;
                                    cout << "1 - Cadastrar novos membros" << endl;
                                    cout << "2 - Listar membros" << endl;
                                    cout << "3 - Consultar Backlog " << endl;
                                    cout << "4 - Entrar como membro" << endl; //nessa opçao o usuario entra como membro para executar as funções de cada um
                                    cout << "5 - Iniciar uma sprint" << endl; //duração de 1-4 semanas, deixar como padrao 4 semanas? ou deixar o usuario escolher?
                                    cout << "0 - voltar" << endl;
                                    cin >> op1; 

                                } 
                                

                                switch (op1)
                                {
                                case 0: break;

                                //case 1 cadastra os membros no projeto
                                case 1:
                                    
                                    do{
                                        /*
                                            Lembrando que: 
                                                So pode a ver um Product Owner, Scrum master e tester, e que para validar os membros tem que ter pelo menos um de cada tipo
                                        */

                                       //menu para cadastro de membros no projeto
                                        cout << "-------------------------------------" << endl;
                                        cout << "ESCOLHA UM TIPO DE USUARIO PARA CADASTRAR: " << projeto << endl;
                                        cout << "-------------------------------------" << endl;
                                        cout << "1 - Product Owner " << endl;
                                        cout << "2 - Scrum Master" << endl;
                                        cout << "3 - Desenvolvedor " << endl;
                                        cout << "4 - Tester " << endl;
                                        cout << "0 - voltar " << endl;
                                        cin >> op2; 

                                        switch (op2)
                                        {
                                        //volta ao menu do projeto e verifica se 
                                        case 0:{
                                            if(existeDev == true && existePD == true && existeSM == true && existeT == true){
                                                existeMembros = true;
                                                cout << "Todos os membros foram cadastrados, entrando no projeto..." << endl;
                                            } 
                                            else cout << "Nem todos os membros foram cadastrados, para ter acesso ao projeto é necessario que todos eles sejam cadastrados" << endl;

                                            break;
                                        }

                                        //cadastrar Product Owner
                                        case 1:{
                                            if(existePD == false){
                                                //Criação do Product Owner
                                                string nome;

                                                cout << "Digite o nome do Product Owner: ";
                                                cin.ignore();
                                                getline(cin, nome);

                                                PD = ProductOwner(nome);

                                                if(PD.getNome() == nome){
                                                  existePD = true;
                                                  cout << nome << " foi cadastrado(a) como Product Owner" << endl;
                                                }else{
                                                  cout << "Falha no cadastramento do Product Owner" << endl;
                                                  existePD = false;
                                                }
                                            }else{
                                                cout << "Já existe um Product Owner. Product Owner: " << PD.getNome() << endl;
                                            }

                                            break;
                                        }

                                        //cadastrar Scrum Master
                                        case 2:{
                                            if(existeSM == false){
                                                string nome;
                                                cout << "Digite o nome do Scrum Master: ";
                                                cin.ignore();
                                                getline(cin, nome);

                                                SM = ScrumMaster(nome);

                                                if(SM.getNome() == nome){
                                                  cout << nome << " foi cadastrado(a) como Scrum Master" << endl;
                                                  existeSM = true;
                                                }else{
                                                  cout << "Falha no cadastramento do Scrum Master" << endl;
                                                  existeSM = false;
                                                }
                                                
                                                }else{
                                                cout << "Já existe um Scrum Master. Scrum Master: " << SM.getNome() << endl;
                                            }

                                            break;
                                        }

                                        //cadrastar Devs
                                        case 3:{

                                                 //para caso tenha mais devs
                                                char c;
                                                string nome;

                                                cout << "Digite o nome do  Desenvolvedor: ";
                                                cin.ignore();
                                                getline(cin, nome);
                                              
                                                listaEnd[qntEnd] = Dev(nome);
                                              
                                                if(listaEnd[qntEnd].getNome() == nome){
                                                    //if(existeDev == false){
                                                        //listaDevs = new listaDevs(&listaEnd[qntEnd],&listaEnd[qntEnd]);
                                                    //}else{
                                                    //    listaDevs.addDev(&listaEnd[qntEnd]);
                                                    //}
                                                    listaDevs.addDev(&listaEnd[qntEnd]);
                                                    cout << nome << " foi cadastrado(a) como Desenvolvedor" << endl;
                                                    
                                                    qntEnd++;
                                                    existeDev = true;
                                                }else {
                                                    cout << "Falha no cadastramento do Desenvolvedor" << endl;
                                                }

                                                do{
                                                    cout << "Deseja cadastrar outro desenvolvedor?";
                                                    cin>>c;

                                                    if(c == 's'|| c == 'S'){

                                                    cout << "Digite o nome do  Desenvolvedor: ";
                                                    cin.ignore();
                                                    getline(cin, nome);

                                                    listaEnd[qntEnd] = Dev(nome);

                                                    listaDevs.addDev(&listaEnd[qntEnd]);
                                                    cout << nome << " foi cadastrado(a) como Desenvolvedor" << endl;
                                                    qntEnd++;
                        
                                                    }else{
                                                        break;
                                                    }

                                                }while(c == 's' || c == 'S');
                                              
                                                cout << "--------------------------------------" << endl;
                                                cout << "Desenvolvedores cadastrados: " << endl;
                                                cout << "--------------------------------------" << endl;
                                                listaDevs.consultar();
                                              
                                              

                                            break;
                                        }
                                            

                                        //cadastrar Tester
                                        case 4:{
                                            if(existeT == false){
                                                string nome;
                                                cout << "Digite o nome do Tester: ";
                                                cin.ignore();
                                                getline(cin, nome);

                                                T = Tester(nome);

                                                if(T.getNome() == nome){
                                                  cout << nome << " foi cadastrado(a) como Tester" << endl;
                                                  existeT = true;
                                                }else{
                                                  cout << "Falha no cadastramento do Tester" << endl;
                                                  existeT = false;
                                                }
                                                
                                            }else{
                                                cout << "Já existe um Tester. Tester: " << T.getNome() << endl;
                                            }

                                            
                                            break;
                                        } 
                                    
                                        
                                        default:
                                            break;
                                        }



                                    }while(op2 != 0);


                                    break;
                        
                                //case 2 lista os membros do projeto
                                case 2:
                                    if(existeMembros == true){
                                        cout << "--------------------------------------" << endl;
                                        cout << "LISTA DE MEMBROS DO PROJETO " << projeto << endl;
                                        cout << "--------------------------------------" << endl;
                                        cout << "Nome: " << PD.getNome() << endl;
                                        cout << "Função: Product Owner" << endl;
                                        cout << "--------------------------------------" << endl;
                                        cout << "Nome: " << SM.getNome() << endl;
                                        cout << "Função: Scrum Master "<< endl;
                                        cout << "--------------------------------------" << endl;
                                        
                                        listaDevs.consultar();

                                        cout << "Nome: " << T.getNome() << endl;
                                        cout << "Função: Tester" << endl;
                                    }
                                    else cout << "Não existe membros cadastrados" << endl;

                                    break;

                                //consultando tarefas do backlog
                                case 3:{
                                    if(existeBacklog == true){
                                        if(existeMembros == true){
                                            cout << "Listando tarefas do Backlog....." << endl;
                                            b.consultar();
                                        }
                                        else cout << "Não existe membros cadastrados" << endl;
                                        break;
                                    }else{
                                        cout << "O Backlog não foi inicializado, entre como Product Owner para cadastrar uma Tarefa no Backlog" << endl;
                                    }
                                    break;
                                }

                                case 4:{
                                    if(existeMembros == true){

                                        do{
                                            cout << "-------------------------------------" << endl;
                                            cout << "Escolhe que tipo de membro você que exercer a função:" << projeto << endl;
                                            cout << "-------------------------------------" << endl;
                                            cout << "1 - Product Owner " << endl;
                                            cout << "2 - Scrum Master" << endl;
                                            cout << "3 - Desenvolvedor " << endl;
                                            cout << "4 - Tester " << endl;
                                            cout << "0 - voltar " << endl;
                                            cin >> op3; 

                                            switch (op3)
                                            {
                                                case 0:{
                                                    cout << "Voltando ao Menu do Projeto... Aguarde... " << endl;
                                                    break;
                                                }
                                                    

                                                //como so existe um product owner não precisa escolher qual
                                                //menu de funções do Product Owner
                                                case 1:{
                                                        cout << "-------------------------------------" << endl;
                                                        cout << "Você agora é o Product Owner:" << endl;
                                                        cout << "Olá, "<< PD.getNome() << " seja bem-vindo(a) ao menu de função do Product Owner" << endl;
                                                    do{
                                                        //lista as informações do Product Owner
                                                        cout << "-------------------------------------" << endl;
                                                        cout << "Escolha o que deseja fazer:" << endl;
                                                        cout << "-------------------------------------" << endl;
                                                        cout << "1 - Consultar Backlog" << endl;
                                                        cout << "2 - Cadastrar Tarefa no Backlog" << endl;
            
                                                        cout << "0 - voltar " << endl;
                                                        cin >> op4;

                                                        switch (op4)
                                                        {
                                                            case 0:{
                                                                cout << "Voltando ao Menu de membros... Aguarde... " << endl;
                                                                break;
                                                            }

                                                            //case 1 imprime tarefas do backlog, caso o backlog não exista precisa ser inicializado e retorna
                                                            case 1:{
                                                                if(existeBacklog == true){
                                                                    //if(existeBacklog == false) existeBacklog = true;
                                                                    cout << "Consultando Backlog..." << endl;
                                                                    b.consultar();
                                                                }else{
                                                                    cout << "O backlog não foi inicializado, por favor cadastre uma tarefa..." << endl;
                                                                }
                                                            
                                                                break;
                                                            }

                                                            //case 2 cadastra tarefas no backlog, caso o backlog não exista ele precisa se inicializado
                                                            case 2:{
                                                                int id = 0;//id começa a partir de 1
                                                                int pde = 0;
                                                                string instrucao;
                                                                char c;
                                                                
                                                                cout << "Digite as informações sobre a tarefa:" << endl;

                                                                cout << "ID: " << endl;
                                                                cin >> id;
                                                                cout << "Pontos de esforço: " << endl;
                                                                cin >> pde;
                                                                cout << "Instruções: " << endl;
                                                                cin.ignore();
                                                                getline(cin, instrucao);

                                                                listaEndTarefas[qntEndT] = Tarefa(id, pde, instrucao);
                                                                cout << "Cadastrando tarefa no backlog..." << endl;

                                                                if(id == listaEndTarefas[qntEndT].getId()){
                                                                    PD.cadastrarTarefaBacklog(&b, &listaEndTarefas[qntEndT]);
                                                                    cout << "Tarefa cadastrada com sucesso..." << endl;
                                                                    
                                                                    if(existeBacklog == false) existeBacklog = true;

                                                                    qntEndT++;
                                                                    //b.organizarTarefas();

                                                                    do{
                                                                        cout << "Deseja cadastrar nova tarefa?[S/N]" << endl;
                                                                        cin >> c;
                                                                        
                                                                        if(c == 's' || c == 'S'){
                                                                            cout << "Digite as informações sobre a tarefa:" << endl;

                                                                            cout << "ID: " << endl;
                                                                            cin >> id;
                                                                            cout << "Pontos de esforço: " << endl;
                                                                            cin >> pde;
                                                                            cout << "Instruções: " << endl;
                                                                            cin.ignore();
                                                                            getline(cin, instrucao);

                                                                            listaEndTarefas[qntEndT] = Tarefa(id, pde, instrucao);
                                                                            cout << "Cadastrando tarefa no backlog..." << endl;

                                                                             if(id == listaEndTarefas[qntEndT].getId()){
                                                                                PD.cadastrarTarefaBacklog(&b, &listaEndTarefas[qntEndT]);
                                                                                cout << "Tarefa cadastrada com sucesso..." << endl;
                                                                                qntEndT++;
                                                                                //b.organizarTarefas();
                                                                            }else{
                                                                                cout << "Erro ao cadastrar tarefa..." << endl;
                                                                            }
                                                                        }else{
                                                                            break;
                                                                        }
                                                                    }while(c == 's' || c == 'S');
                                                                }
                                                                
                                                                break;
                                                            }
                                                
                                                            default:
                                                                break;
                                                        }
                                                    }while(op4!=0);
                                                    

                                                    break;
                                                }
                                                
                                                //como so existe um Scrum Master não precisa escolher qual
                                                //menu de funções do Scrum Master 
                                                case 2:{
                                                    cout << "-------------------------------------" << endl;
                                                        cout << "Você agora é o Scrum Master:" << endl;
                                                        cout << "Olá, "<< SM.getNome() << " seja bem-vindo(a) ao menu de função do Scrum Master" << endl;
                                                    do{
                                                        cout << "-------------------------------------" << endl;
                                                        cout << "Você agora é o Scrum Master:" << endl;
                                                        //lista as informações do Scrum Master
                                                        cout << "-------------------------------------" << endl;
                                                        cout << "Escolha o que deseja fazer:" << endl;
                                                        cout << "-------------------------------------" << endl;
                                                        cout << "1 - Atribuir tarefas aos desenvolvedores" << endl; //tarefas da sprint
                                                        //cout << "2 - Atribuir tarefa a um desenvolvedor especifico" << endl; //tarefas da sprint
                                                        cout << "0 - voltar " << endl;
                                                        cin >> op5;
                                                        //lembrando que um desenvolvedor executa uma tarefa por vez
                                                
                                                        switch (op5)
                                                        {

                                                        case 0:{
                                                        cout << "Voltando ao menu do projeto... Aguarde... " << endl;
                                                        break;
                                                        }

                                                        //case 1 atribui as tarefas da sprint para os desenvolvedores, caso a sprint não tenha sido inicializada tem que voltar ao menu anterior
                                                        case 1:{
                                                            
                                                            if(existeSprint == true){
                                                               
                                                                Dev * dAtual  = listaDevs.getCabeca();
                                                                //cout << "cabeca: " << dAtual->getNome() << endl;
                                                                Tarefa * tAtual;

                                                                for(int i = 0; i < listaDevs.getQuantidade(); i++){
                                                                    tAtual = S->getCabeca();
                                                                    tAtual = tAtual->getProximo();

                                                                    for(int j = 0; j < S->getQuantidade()-1; j++){
                                                                        if(tAtual->getResponsavel() == NULL && tAtual->getId() != 0 ){
                                                                            //listaEndTarefas[j].setResponsavel(atual);
                                                                            //tAtual->setResponsavel(dAtual);
                                                                            //SM.atribuirTarefaAPessoa(S, tAtual->getId(), dAtual);
                                                                            SM.atribuirTarefa(dAtual, tAtual);
                                                                            //cout << "entrei: " << dAtual->getNome() << endl;
                                                                            break;

                                                                        }else{

                                                                            tAtual = tAtual->getProximo();
                                                                        }
                                                                    }

                                                                    dAtual = dAtual->getProximo();
                                                                    
                                                                }


                                                                cout << "gerando relatorio..." << endl;
                                                                if(S != nullptr){
                                                                    cout << "-------------------------------"<< endl;
                                                                    cout << "Relatório da Sprint"<< endl;
                                                                    cout << "-------------------------------"<< endl;
                                                                    S->gerarRelatorio();  
                                                                    cout << "-------------------------------"<< endl;
                                                                    cout << "Faltam " << S->getTempoDaSprint() << " dias" << " para a Sprint acabar." << endl; 
                                                                }else{
                                                                    cout << "A Sprint não tem tarefas cadastradas!"<< endl;
                                                                }
                                                                
                                                            }
                                                            else cout << "A sprint não foi iniciada por favor, volte ao menu anterior a inicialize"<< endl;
                                                
                                                            break;
                                                        }

                                                        //case 2 atribui uma tarefa especifica a algum desenvolvedor, caso a sprint não tenha sido inicializada tem que voltar ao menu anterior
                                                        // case 2:{
                                                        //     if(existeSprint == true) cout << "Atribuindo tarefa ao desevolvedor"<< endl;
                                                        //     else cout << "A sprint não foi iniciada por favor, volte ao menu anterior a inicialize"<< endl;
                                                
                                                        //     break;
                                                        // }
                                                    
                                                
                                                        default:
                                                            break;
                                                        }
                                                    }while(op5!=0);
                                                    
                                                    break;
                                                }

                                                //como pode existir varios dev é necessario escolher um
                                                //menu de funções dos devs
                                                case 3:{
                                                        string nomeDev;
                                                        Dev * devEscolhido = new Dev();
                                                        Dev * lista = listaDevs.getCabeca();
                                                        bool acheiDev = false;


                                                        cout << "Escolha o desenvolvedor que você deseja entrar:" << endl;
                                                        listaDevs.consultar();
                                                        cout << "Escreva o nome do desenvolvedor escolhido:" << endl;
                                                        cin.ignore();
                                                        getline(cin, nomeDev);
                                                        
                                                        for(int i = 0; i<listaDevs.getQuantidade();i++){
                                                            if(lista != NULL){
                                                                if(lista->getNome() == nomeDev){
                                                                    devEscolhido = lista;
                                                                    acheiDev = true;
                                                                
                                                                    break;
                                                                }else{
                                                                    lista = lista->getProximo();
                                                                }
                                                            }else{
                                                                cout << "Desenvolvedor não encontrado" << endl;
                                                            }
                                                            
                                                        }


                                                    if(acheiDev == true){
                                                        cout << "-------------------------------------" << endl;
                                                        cout << "Você agora é um desenvolvedor:" << endl;
                                                        cout << "Olá, "<< devEscolhido->getNome() << " seja bem-vindo(a) ao menu de função do Scrum Master" << endl;
                                                        do{  
                                                            //lista os desenvolvedores se houver mais de um
                                                            //escolhe o desenvolvedor
                                                            cout << "-------------------------------------" << endl;
                                                            cout << "Você agora é um Desenvolvedor:" << endl;
                                                            //lista as informações do Dev

                                                            //caso so tenha um desenvolvedor vai direto para o menu

                                                            //esse menu vai entrar dps de escolher o desenvolvedor
                                                    
                                                            cout << "-------------------------------------" << endl;
                                                            cout << "Escolha o que quer fazer:" << endl;
                                                            cout << "-------------------------------------" << endl;
                                                            cout << "1 - Realizar tarefa" << endl; 
                                                            //cout << "2 - Realizar uma tarefa expecífica" << endl; 
                                                            cout << "0 - voltar " << endl;
                                                            cin >> op6;

                                                            switch (op6)
                                                            {
                                                    
                                                            case 0:{
                                                                cout << "Voltando ao menu do projeto... Aguarde..." << endl;
                                                                break;
                                                            }
                                                        
                                                            //case 1, muda status de todas as tarefas do desenvolvedor
                                                            case 1:{
                                                                //bool existeTarefaProDev = false;
                                                                char c;
                                                                int escolha;
                                                                
                                                                Tarefa * tarefaAtual = S->getCabeca();
                                                                tarefaAtual = tarefaAtual->getProximo();


                                                                 if(existeSprint == true){
                                                                    

                                                                     for(int i=0;i<S->getQuantidade()-1;i++){
                                                                        if(tarefaAtual != NULL){
                                                                            if(tarefaAtual->getResponsavel() == devEscolhido && tarefaAtual->getStatus()!="CONCLUIDA" && tarefaAtual->getStatus()!="TESTAR"){
                                                                                //existeTarefaProDev = true;
                                                                                cout << "VOCE DESEJA MUDAR O STATUS DA SEGUINTE TAREFA?" << endl;
                                                                                tarefaAtual->imprimirTarefa();
                                                                                cout << "[S/N]:" << endl;
                                                                                cin >> c;

                                                                                if(c == 's' || c == 'S'){
                                                                                    cout << "ESCOLHA O STATUS NOVO:" << endl;
                                                                                    cout << "1 - MEIO FEITA" << endl;
                                                                                    cout << "2 - TESTAR" << endl;
                                                                                    cin >> escolha;

                                                                                    if(escolha == 1){
                                                                                        if(tarefaAtual->getStatus() != "TESTAR"){
                                                                                            tarefaAtual->setStatus("MEIO FEITA");
                                                                                        }
    
                                                                                    }else if(escolha == 2){
                                                                                        tarefaAtual->setStatus("TESTAR");
                                                                                    }else{
                                                                                        cout << "Escolha uma opção válida!" << endl;
                                                                                        break;
                                                                                    }
                                                                                }

                                                                                
                                                                            }
                                                                            tarefaAtual = tarefaAtual->getProximo();
                                                                        }else{
                                                                            cout << "Não existe tarefa para você!" << endl;
                                                                        }
                                                                    }

                                                                        cout << "gerando relatorio..." << endl;
                                                                        if(S != nullptr){
                                                                            cout << "-------------------------------"<< endl;
                                                                            cout << "Relatório da Sprint"<< endl;
                                                                            cout << "-------------------------------"<< endl;
                                                                            S->gerarRelatorio();  
                                                                            cout << "-------------------------------"<< endl;
                                                                            cout << "Faltam " << S->getTempoDaSprint() << " dias" << " para a Sprint acabar." << endl; 
                                                                        }else{
                                                                            cout << "A Sprint não tem tarefas cadastradas!"<< endl;
                                                                        }
                                                                    

                                                        
                                                                    break;
                                                                }else{
                                                                    cout << "A sprint não foi iniciada por favor, volte ao menu anterior a inicialize"<< endl;
                                                                }
                                                                break;
                                                            }
                                                        
                                                    
                                                            //case 2, muda status de uma tarefa especifica do desenvolvedor
                                                            // case 2:{
                                                            //     if(existeSprint == true){
                                                            //         //listar tarefas do desenvolvedor
                                                            //         //escolher a tarefa e mudar status
                                                            //         cout << "realizando tarefa" << endl;
                                                            //         break;
                                                            //     }else{
                                                            //         cout << "A sprint não foi iniciada por favor, volte ao menu anterior a inicialize"<< endl;
                                                            //     }
                                                            //     break;
                                                            // }
                                                        
                                                    
                                                            default:
                                                                break;
                                                            }
                                                        }while(op6 != 0);

                                                    }else{
                                                        cout << "Escolha um desenvolvedor válido!" << endl;
                                                    }

                                                    
                                                    
                                                    break;
                                                }

                                                //como so existe um Tester não precisa escolher qual
                                                //menu de funções do Tester
                                                case 4:{
                                                        cout << "-------------------------------------" << endl;
                                                        cout << "Você agora é um desenvolvedor:" << endl;
                                                        cout << "Olá, "<< T.getNome() << " seja bem-vindo(a) ao menu de função do Scrum Master" << endl;
                                                    do{
                                                        cout << "-------------------------------------" << endl;
                                                        cout << "Você agora é o Tester:" << endl;
                                                        //lista as informações do Tester
                                                        cout << "-------------------------------------" << endl;
                                                        cout << "Escolha o que quer fazer:" << endl;
                                                        cout << "-------------------------------------" << endl;
                                                        cout << "1 - Validar todas as tarefas" << endl; //tarefas da sprint que estão pra ser testadas
                                                        //cout << "2 - Validar tarefas de um desenvolvedor" << endl; //tarefas da sprint
                                                        cout << "0 - voltar " << endl;
                                                        cin >> op7;
                                                    
                                                        switch (op7)
                                                        {
                                                    
                                                        //case 1 valida todas as tarefas com status "TESTE", ou valida ou retorna elas
                                                        case 1:{
                                                            if(existeSprint == true){
                                                                char c;
                                                                Tarefa * tarefaParaSerValidada = S->getCabeca();
                                                                tarefaParaSerValidada = tarefaParaSerValidada->getProximo();

                                                                for(int i = 0; i<S->getQuantidade(); i++){
                                                                    if(tarefaParaSerValidada != NULL){
                                                                        if(tarefaParaSerValidada->getStatus() == "TESTAR"){
                                                                            // tarefaParaSerValidada->imprimirTarefa();
                                                                            // cout << "VALIDAR OU RETORNAR TAREFA (V = VALIDAR, R = RETORNAR)" << endl;
                                                                       
                                                                            // cout << "[V/R]:" << endl;
                                                                            // cin >> c;

                                                                            // if(c == 'v' || c == 'V'){
                                                                            //     tarefaParaSerValidada->setStatus("CONCLUIDA");
                                                                            //     cout << "Validando tarefa..." << endl;
                                                                            // }else if(c == 'r' || c == 'R'){
                                                                            //     tarefaParaSerValidada->setStatus("REVISAR");
                                                                            //     cout << "Declinando tarefa..." << endl;
                                                                            // }else{
                                                                            //     cout << "Escreva uma opção válida!" << endl;
                                                                            // }
                                                                            T.validarTarefas(tarefaParaSerValidada);
                                                                        }
                                                                         tarefaParaSerValidada = tarefaParaSerValidada->getProximo();
                                                                    }else{
                                                                        cout << "Não existem tarefas para ser validadas!" << endl;
                                                                    }

                                                                }

                                                                cout << "gerando relatorio..." << endl;
                                                                if(S != nullptr){
                                                                    cout << "-------------------------------"<< endl;
                                                                    cout << "Relatório da Sprint"<< endl;
                                                                    cout << "-------------------------------"<< endl;
                                                                    S->gerarRelatorio();  
                                                                    cout << "-------------------------------"<< endl;
                                                                    cout << "Faltam " << S->getTempoDaSprint() << " dias" << " para a Sprint acabar." << endl; 
                                                                }else{
                                                                    cout << "A Sprint não tem tarefas cadastradas!"<< endl;
                                                                }
                                                            

                                                                break;
                                                            }else{
                                                                cout << "A sprint não foi iniciada por favor, volte ao menu anterior a inicialize"<< endl;
                                                            }
                                                            break;
                                                        }
                                                       
                                                        // case 2:{
                                                        //     //lista os devs se tiver mais de um, escolhe, e lista as tarefas desse dev
                                                        //     //se tive so um, lista as tarefas desse dev
                                                        //     //verifica se tem uma tarefa com status Teste, se tiver valida, se não tiver printa que não há tarefas para teste
                                                        //     if(existeSprint == true){
                                                        //         cout << "Validando tarefas de um Dev" << endl;
                                                        //         break;
                                                        //     }else{
                                                        //         cout << "A sprint não foi iniciada por favor, volte ao menu anterior a inicialize"<< endl;
                                                        //     }

                                                        //     break;
                                                        // }
                                                    
                                                        default:
                                                            break;
                                                        }
                                                    }while(op7!=0);
                                                    

                                                    break;
                                                }
                                            
                                                default:
                                                    break;
                                            }

                                        }while(op3 != 0);


                                    }else{
                                        cout << "Não existe membros cadastrados" << endl;
                                    }

                                    break;
                                }
                                
                                //case 5, inicializa uma sprint, lembrando que so pode a ver uma sprint por vez. A sprint so pode existir se o backlog foi inicializado
                                case 5:{
                                    
                                    if(existeMembros == true){
                                        if(existeBacklog == true){
                                            if(existeSprint == false){
                                            
                                            int id = 0;
                                            char c;
                                            bool existeId = false;
                                            Tarefa * aux;

                                            cout << "iniciando uma sprint..." << endl;
                                            //Sprint * S = new Sprint();

                                            cout << "Escolha as tarefas do Backlog que deseja adicionar na Sprint:" << endl;
                                            b.consultar();
                                            
                                            cout << "Id da tarefa escolhida: " << endl;
                                            cin >> id;
                                            
                                            aux = b.getTarefa(id);

                                            if(aux != nullptr){
                                                //PD.cadastrarTarefaSprint(S, &b, id);
                                                S->addTarefa(&b, id);
                                                S->setQuantidade(S->getQuantidade()+1);

                                                cout << "Tarefa adicionada com sucesso" << endl;
                                                existeSprint = true;

                                                do{
                                                    cout << "Deseja adicionar outra tarefa?[S/N]" << endl;
                                                    cin >> c;

                                                    if(c == 's' || c == 'S'){
                                                        cout << "Id da tarefa escolhida: " << endl;
                                                        cin >> id;

                                                        //PD.cadastrarTarefaSprint(S, &b, id);
                                                        
                                                        S->addTarefa(&b, id);
                                                        S->setQuantidade(S->getQuantidade()+1);
                                                        cout << "Tarefa adicionada com sucesso" << endl;
                                                    }

                                                    

                                                }while(c == 's' || c == 'S');

                                                int tempo;
                                                cout << "Escreva o tempo que irá durar a Sprint: " << endl;
                                                cin >> tempo;
                                                S->setTempoDaSprint(tempo);

                                            }else{
                                                cout << "Não existe essa tarefa no Backlog! escreva um id válido." << endl;
                                            }
                                    
                                            break;

                                            }else{
                                                cout << "Já existe uma sprit em andamento" << endl;
                                            }
                                        }else{
                                            cout << "O backlog não foi inicializado" << endl;
                                        }
                                        
                                    }else{
                                        cout << "Não existe membros cadastrados" << endl;
                                    }
                                    
                                    break;
                                }

                                /*IDEIA: fazer um vetor para armazenar o relatorio final de todas as sprint*/
                                //abre o menu da sprint
                                case 6:{

                                    do{
                                        if(existeSprint == true){
                                            //uma sprint por vez, duração padrao: 4 semanas, o tempo vai passar em dias, ou seja 28 dias como padrão
                                            cout << "-------------------------------------" << endl;
                                            cout << "Menu da sprint:" << endl;
                                            cout << "-------------------------------------" << endl;
                                            cout << "1 - Passar tempo" << endl; //gera um relatorio a cada tempo passado e diz quanto tempo falta pra acabar, quando acaba muda existeSprint para false
                                            cout << "2 - Finalizar sprint" << endl; //finaliza de uma vez e gera um relatorio, muda existeSprint para false
                                            cout << "3 - Relatorio da sprint" << endl;//gera um relatorio do estado "atual" da sprint
                                            cout << "0 - voltar " << endl;
                                            cin >> op8;

                                            switch (op8)
                                            {

                                            //case 1, pede para o usuario os dias passados e retorna um relatorio 
                                            case 1:{
                                                //recebe os n dias do usuario
                                                //passa esses dias
                                                //gera um relatorio a cada tempo passado e diz quanto tempo falta pra acabar, quando acaba muda existeSprint para false
                                                if(existeSprint == true && S != nullptr){
                                                    //cout << "ENTROU" << endl;
                                                     int tempo, dias;

                                                     //Sprint aux;

                                                     //aux = *S;

                                                    tempo = S->getTempoDaSprint();

                                                    if(tempo > 0){
                                                        cout << "Faltam " << tempo << " para a o fim da Sprint."<< endl;
                                                        cout << "Digite quantos dias deseja passar: "<< endl;
                                                        cin >> dias;

                                                        if(tempo - dias < 0){
                                                            cout << "Por favor escreva dias validos!"<< endl;
                                                        }else{
                                                            S->setTempoDaSprint(tempo-dias);
                                                            cout << dias << " dias passados!"<< endl;
                                                            cout << "Agora faltam " << S->getTempoDaSprint() << " para a o fim da Sprint."<< endl;

                                                            if(S != nullptr){
                                                                cout << "-------------------------------"<< endl;
                                                                cout << "Relatório da Sprint"<< endl;
                                                                cout << "-------------------------------"<< endl;
                                                                cout << "Faltam " << S->getTempoDaSprint() << "dias" << " para a Sprint acabar." << endl;
                                                                S->gerarRelatorio();        
                                                            }else{
                                                                cout << "A Sprint não tem tarefas cadastradas!"<< endl;
                                                            }
                                                        }
                                                    }
                                                }else{
                                                    cout << "A Sprint não foi iniciada!"<< endl;
                                                }
                                                break;
                                            }

                                            //case 2, finaliza a sprint de uma vez e gera um relatorio final
                                            case 2:{
                                                if(existeSprint == true){
                                                    cout << "finalizando sprint..." << endl;
                                                    S->setTempoDaSprint(0);

                                                    cout << "Sprint finalizada! Gerando Relatório Final..." << endl;
                                                    if(S != nullptr){
                                                        cout << "-------------------------------"<< endl;
                                                        cout << "Relatório da Sprint"<< endl;
                                                        cout << "-------------------------------"<< endl;
                                                        cout << "Faltam " << S->getTempoDaSprint() << " dias" << " para a Sprint acabar." << endl;
                                                        S->gerarRelatorio();        
                                                    }else{
                                                        cout << "A Sprint não tem tarefas cadastradas!"<< endl;
                                                    }

                                                    char c; 

                                                    cout << "Deseja fechar a Sprint? se sim não será possível acessar novamente o relatório" << endl;
                                                    cin >> c;

                                                    if(c == 's' || c == 'S'){
                                                        cout << "Fechando Sprint..."<< endl;
                                                        S = new Sprint();

                                                        S->setQuantidade(0);

                                                        op8 = 0;
                                                        existeSprint = false;
                                                    }else{
                                                        break;
                                                    }

                                                }else{
                                                    cout << "A Sprint não foi iniciada!"<< endl;
                                                    
                                                }

                                                //gera um relatorio final, muda existeSprint para false
                                                break;
                                            }
                                        
                                            //case 3, gera um relatorio do estado "atual da sprint"
                                            case 3:{
                                                if(existeSprint == true){
                                                    cout << "gerando relatorio..." << endl;
                                                    if(S != nullptr){
                                                        cout << "-------------------------------"<< endl;
                                                        cout << "Relatório da Sprint"<< endl;
                                                        cout << "-------------------------------"<< endl;
                                                        S->gerarRelatorio();  
                                                        cout << "-------------------------------"<< endl;
                                                        cout << "Faltam " << S->getTempoDaSprint() << " dias" << " para a Sprint acabar." << endl;
                                                              
                                                    }else{
                                                        cout << "A Sprint não tem tarefas cadastradas!"<< endl;
                                                    }
                                                }
                                                break;
                                            }

                                            default:
                                                break;
                                            }

                                        }else{
                                            cout << "A sprint não foi iniciada por favor inicialize"<< endl;
                                        }
                                    }while(op8!=0);
                                    
                                    break;

                                }

                                default:
                                    break;
                                }


                            }while(op1 != 0);
                    } else {
                        cout << "O projeto não foi inicializado" << endl;
                    }

                    break;
                }

                default:
                    break;
            }


    }while(opcao != 0);
    

    return 0;
}