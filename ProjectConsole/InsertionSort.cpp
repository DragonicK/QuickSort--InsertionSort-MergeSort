#include "Vetor.h"

void InsertionSort(Vetor* vetor, int n) {
    int tamanho = vetor->ObterTamanho();
    int* arr = vetor->ObterVetor();

    int chave;
    int anterior;

    for (int i = 1; i < tamanho; i++) {
        // Adiciona o n�mero de movimenta��es (valores movidos).
        vetor->TotalMovimentacoes++;
        chave = arr[i];
        anterior = i - 1;

        // Se o valor anterior for maior que o pr�ximo.
        // Move o valor anterior para um valor a sua frente.
        while (anterior >= 0 && arr[anterior] > chave) {
            arr[anterior + 1] = arr[anterior];
            anterior--;

            // Adiciona o n�mero de movimenta��es (valores movidos).
            vetor->TotalMovimentacoes++;
            // Adiciona o n�mero de testes (compara��es).
            vetor->TotalTestes++;
        }

        // Coloca o valor do pr�ximo no espa�o anterior.
        arr[anterior + 1] = chave;
        // Adiciona o n�mero de movimenta��es (valores movidos).
        vetor->TotalMovimentacoes++;
    }
}