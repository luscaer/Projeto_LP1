METODOLOGIA SCRUM

RESUMO DO QUE É E O QUE TEM:

Usuários:
    Product Owner: Responsável por definir os objetivos do projeto e priorizar as tarefas. (diz quais são as tarefas).

    Scrum Master: Facilita o processo, remove obstáculos e promove a adoção das práticas do Scrum. (atribui as tarefas aos usuário).

    Equipe de Desenvolvimento: Responsável por realizar o trabalho e entregar as funcionalidades. (realiza as tarefas).

    OBS: No nosso projeto terá um usuário responsável de testar as tarefas concluídas pelos desenvolvedores podendo válidas ou não (volta ao desenvolvedor para ser corrigida).



Backlog:
    É uma lista de todas as funcionalidades, melhorias e correções a serem feitas no projeto, priorizadas pelo Product Owner.(listas das tarefas que pode ser alteradas de acordo com o andamento
    do projeto).

4 Status de tarefa:
    TAREFAS A FAZER
    TAREFAS EM ANDAMENTO
    TAREFAS EM FASE DE TESTE
    TAREFAS CONCLUÍDAS

Sprints:
    Após definir as tarefas e quem vai realizá-las, essas tarefas são colocadas em uma sprint (duração 2 semanas).

    Após passar ‘n’ dias do início da sprint gerar um relatório sobre tarefas concluídas e tarefas pendentes.
    
    As tarefas pendentes podem ser passadas para a próxima sprint (uma sprint por vez).


As estruturas de TADs (Tipos Abstratos de Dados) 

	Listas encadeadas: 	
        listas duplamente encadeadas ordenada (classe: backlog)
        lista duplamente encadeada (classe: sprint)

 Estrutura:

CLASSE: Usuário/Pessoa
    Atributos:
        ponteiro pro prox
        Nome
        função
    funções:
        gets e sets		
    
    Tipos de usuários (herda de usuário)
    SUBCLASSE : Product Owner
        Atributos:
            herda de usuário
        funções:
            funções herdadas
            cadastrar tarefas no backlog

    SUBCLASSE: Scrum Master
        Atributos:
            herda de usuário
        funções:
            funções herdadas
            atribuir tarefa aos desenvolvedores

    SUBCLASSE: Equipe de Desenvolvimento/Desenvolvedor
        Atributos:
            herda de usuários.
        funções:
            herda de usuários.
            Realiza tarefas (muda status de tarefa).

    SUBCLASSE: Responsável por teste
        Atributos:
            herda de usuários
        funções:
            herda de usuários
            valida tarefas em teste (muda status de tarefa, válida ou volta)


CLASSE: Backlog
    Atributos:
        (lista duplamente encadeada ordenada de tarefa-> ordenar por pontos de esforço)
        head
        tail
        quantidade (quantidade de tarefas no backlog)
    funções
        gets e sets
        add
        deletar
        consultar

CLASSE: tarefa (ponteiro)
    Atributos:
        ponteiro(endereço)
        id (padrão: #+número)
        pontos de esforço (define a prioridade, ordenação decrescente)
        status (não iniciada, em andamento, teste, concluída)
        intruçoes   
        responsável (endereço/ponteiro)
    funções
        gets e sets


CLASSE: Sprint (2 semanas)
    Atributos:
        (lista duplamente encadeada de tarefa)
        head
        tail
        tempo passado(dias)
        quantidade (quantidade de tarefas na sprint)
    funções:
        gets e sets
        gerar relatório pôs ‘n’ tempo passado
        gerar relatório por desenvolvedor/pessoa (aqui implementa algoritmo de ordenação).
				