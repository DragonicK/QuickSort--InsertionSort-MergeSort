#include "Vetor.h"

void InsertionSort(Vetor* vetor, int n) {
    int tamanho = vetor->ObterTamanho();
    int* arr = vetor->ObterVetor();

    int chave;
    int anterior;

    for (int i = 1; i < tamanho; i++) {
        // Adiciona o número de movimentações (valores movidos).
        vetor->TotalMovimentacoes++;
        chave = arr[i];
        anterior = i - 1;

        // Se o valor anterior for maior que o próximo.
        // Move o valor anterior para um valor a sua frente.
        while (anterior >= 0 && arr[anterior] > chave) {
            arr[anterior + 1] = arr[anterior];
            anterior--;

            // Adiciona o número de movimentações (valores movidos).
            vetor->TotalMovimentacoes++;
            // Adiciona o número de testes (comparações).
            vetor->TotalTestes++;
        }

        // Coloca o valor do próximo no espaço anterior.
        arr[anterior + 1] = chave;
        // Adiciona o número de movimentações (valores movidos).
        vetor->TotalMovimentacoes++;
    }
}