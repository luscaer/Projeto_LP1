#define VECTOR_SIZE 100

//busca binaria recursiva
int recursive_binary_search(int vector[VECTOR_SIZE], int begin, int end, int item)
{
    /* Índice representando o meio do sub-vetor begin->end */
    int i = (begin + end) / 2;

    if (begin > end) {  /* Ponto de parada. Item não está no vetor */
        return -1;
    }

    if (vector[i] == item) {  /* Item encontrado */
        return i;
    }

    if (vector[i] < item) {  /* Item está no sub-vetor à direita */
        return recursive_binary_search(vector, i + 1, end, item);


    } else {  /* vector[i] > item. Item está no sub-vetor à esquerda */
        return recursive_binary_search(vector, begin, i - 1, item);
    }
}    

//busca binaria iterativa

int iterative_binary_search(int vector[VECTOR_SIZE], int item)
{
    int begin = 0;
    int end = VECTOR_SIZE - 1;

    while (begin <= end) {  /* Condição de parada */

        int i = (begin + end) / 2;  /* Calcula o meio do sub-vetor */

        if (vector[i] == item) {  /* Item encontrado */
            return i;
        }

        if (vector[i] < item) {  /* Item está no sub-vetor à direita */
            begin = i + 1;
        } else {  /* vector[i] > item. Item está no sub-vetor à esquerda */
            end = i;
        }
    }

    return -1;
}