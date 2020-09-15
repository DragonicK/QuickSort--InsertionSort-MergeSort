#include "Vetor.h"

/// <summary>
/// Mescla dois subvetores de um vetor.
/// </summary>
/// <param name="vetor"></param>
/// <param name="esquerdo"></param>
/// <param name="meio"></param>
/// <param name="direito"></param>
void Mesclar(Vetor *vetor, int esquerdo, int meio, int direito) {    
    int* arr = vetor->ObterVetor();
    // Índice do primeiro subvetor.
    int primeiro;
    // Índice do segundo subvetor.
    int segundo;
    // Índice do vetor mesclado.
    int mesclado;

    int tamanho_left = meio - esquerdo + 1;
    int tamanho_right = direito - meio;

    // Cria os vetores temporários.
    int* left = new int[tamanho_left];
    int* right = new int[tamanho_right];

    // Copia os valores temporários.
    for (int i = 0; i < tamanho_left; i++) {
        left[i] = arr[esquerdo + i];
    }

    for (int i = 0; i < tamanho_right; i++) {
        right[i] = arr[meio + 1 + i];
    }

    // Adiciona o número de movimentações (valores movidos).
    vetor->TotalMovimentacoes += tamanho_right + tamanho_left;

    // Índice do primeiro subvetor.
    primeiro = 0;
    // Índice do segundo subvetor.
    segundo = 0;  
    // Índice inicial do vetor mesclado.
    mesclado = esquerdo; 

    // Mescla os vetores temporários de volta para o vetor principal.
    while (primeiro < tamanho_left && segundo < tamanho_right) {
        // Adiciona o número de testes (comparações).
        vetor->TotalTestes++;

        if (left[primeiro] <= right[segundo]) {
            arr[mesclado] = left[primeiro];
            primeiro++;

            // Adiciona o número de movimentações (valores movidos).
            vetor->TotalMovimentacoes++;
        }
        else {
            arr[mesclado] = right[segundo];
            segundo++;

            // Adiciona o número de movimentações (valores movidos).
            vetor->TotalMovimentacoes++;
        }

        mesclado++;
    }
 
    // Copia os elementos restantes do vetor left se houver.
    while (primeiro < tamanho_left) {
        arr[mesclado] = left[primeiro];
        primeiro++;
        mesclado++;

        // Adiciona o número de testes (comparações).
        vetor->TotalTestes++;
        // Adiciona o número de movimentações (valores movidos).
        vetor->TotalMovimentacoes++;
    }

    // Copia os elementos restantes do vetor right se houver.
    while (segundo < tamanho_right) {
        arr[mesclado] = right[segundo];
        segundo++;
        mesclado++;

        // Adiciona o número de testes (comparações).
        vetor->TotalTestes++;
        // Adiciona o número de movimentações (valores movidos).
        vetor->TotalMovimentacoes++;
    }

    delete[] left;
    delete[] right;
}

/// <summary>
/// Implementa o algoritmo MergeSort.
/// </summary>
/// <param name="vetor"></param>
/// <param name="esquerdo"></param>
/// <param name="direito"></param>
void MergeSort(Vetor* vetor, int esquerdo, int direito) {
    if (esquerdo < direito) {
        int meio = esquerdo + (direito - esquerdo) / 2;

        // Organiza a primeira metade.
        MergeSort(vetor, esquerdo, meio);
        // Organiza a segunda metade.
        MergeSort(vetor, meio + 1, direito);

        Mesclar(vetor, esquerdo, meio, direito);
    }
}