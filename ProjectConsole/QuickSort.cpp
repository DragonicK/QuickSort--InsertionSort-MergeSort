#include "Vetor.h"

/// <summary>
/// Realiza a troca entre dois elementos.
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void Trocar(int* a, int* b) {
    int value = *a;
    *a = *b;
    *b = value;
}

/// <summary>
/// Pega o �ltimo elemento como um piv� e coloca na sua posi��o correta no vetor ordenado.
/// Coloca todos os elementos menores que o piv� para a esquerda e todos os maiores para a direita.
/// </summary>
/// <param name="arr"></param>
/// <param name="low"></param>
/// <param name="high"></param>
/// <returns></returns>
int Particionar(Vetor* vetor, int menor, int maior) {
    int* arr = vetor->ObterVetor();
    // Adiciona o n�mero de movimenta��es (trocas).
    vetor->TotalMovimentacoes++;
    int pivo = arr[maior];
    // �ndice do menor elemento.
    int i = (menor - 1);

    for (int j = menor; j <= maior - 1; j++) {
        // Adiciona o n�mero de testes (compara��es).
        vetor->TotalTestes++;

        // Se o atual elemento � menor ou igual ao piv�.
        if (arr[j] <= pivo) {
            // Move para o pr�ximo menor elemento 
            i++;
            // Adiciona o n�mero de movimenta��es (trocas).
            vetor->TotalMovimentacoes++;
            Trocar(&arr[i], &arr[j]);       
        }
    }

    Trocar(&arr[i + 1], &arr[maior]);
    // Adiciona o n�mero de movimenta��es (trocas).
    vetor->TotalMovimentacoes++;

    return (i + 1);
}

/// <summary>
/// Implementa o algoritmo de QuickSort.
/// </summary>
/// <param name="vetor"></param>
/// <param name="posicao_inicio"></param>
/// <param name="posicao_fim"></param>
void QuickSort(Vetor* vetor, int posicao_inicio, int posicao_fim) {
    if (posicao_inicio < posicao_fim) {

        int particao = Particionar(vetor, posicao_inicio, posicao_fim);

        QuickSort(vetor, posicao_inicio, particao - 1);
        QuickSort(vetor, particao + 1, posicao_fim);
    }
}