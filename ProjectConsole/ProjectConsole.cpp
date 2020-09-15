#include <iostream>
#include <cstdlib>
#include "Vetor.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"

using namespace std;

void Clear() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void DefinirNumerosAleatorios(Vetor* vetor) {
    int tamanho = vetor->ObterTamanho();
    int* valores = vetor->ObterVetor();

    for (int i = 0; i < tamanho; i++) {
        valores[i] = rand();
    }  
}

void ExibirVetor(Vetor* vetor) {
    int tamanho = vetor->ObterTamanho();
    int* valores = vetor->ObterVetor();

    for (int i = 0; i < tamanho; i++) {
        cout << valores[i] << endl;
    }
}

void ExibirAnalise(Vetor* vetor) {
    cout << "Numero Total de Testes: " << vetor->TotalTestes << endl;
    cout << "Numero Total de Movimentacoes: " << vetor->TotalMovimentacoes << endl;
    cout << "Numero Total Operacoes: " << (vetor->TotalMovimentacoes + vetor->TotalTestes) << endl;
}

int main() {
    char letra = 's';
    int tamanho;
    Vetor quicksort;
    Vetor mergesort;
    Vetor insertsort;

    while (letra == 's') {
        // Desaloca a memoria prévia (se houver).
        quicksort.Deletar();
        mergesort.Deletar();
        insertsort.Deletar();

        Clear();

        cout << "Insira o tamanho do vetor entre 1 e 1000: ";
        cin >> tamanho;

        if (tamanho < 0) {
            tamanho = 1;
        }
        else if (tamanho > 1000) {
            tamanho = 1000;
        }

        Clear();

        cout << "Tamanho do Vetor:" << tamanho << endl;

        if (quicksort.Criar(tamanho)) {
            // Define o valor padrão.
            quicksort.LimparVetorComZeros();

            DefinirNumerosAleatorios(&quicksort);

            // Faz com que todos os vetores tenham o mesmo valor aleatório para a precisão da análise.
            insertsort = quicksort.Clonar();
            mergesort = quicksort.Clonar();

            cout << endl << "Organizando elementos usando MergeSort:" << endl;
            MergeSort(&mergesort, 0, mergesort.ObterTamanho() - 1);
            ExibirAnalise(&mergesort);

            cout << endl << "Organizando elementos usando QuickSort:" << endl;
            QuickSort(&quicksort, 0, quicksort.ObterTamanho() - 1);
            ExibirAnalise(&quicksort);

            cout << endl << "Organizando elementos usando InsertSort:" << endl;
            InsertionSort(&insertsort, insertsort.ObterTamanho());
            ExibirAnalise(&insertsort);
        }
        else {
            cout << "Tamanho invalido ou ocorreu um erro ao alocar memoria." << endl;
        }

        cout << endl << endl << "Deseja continuar? s/n: ";
        cin >> letra;
    }

    // Deleta os ponteiros.
    quicksort.Deletar();
    mergesort.Deletar();
    insertsort.Deletar();

    return 0;
}