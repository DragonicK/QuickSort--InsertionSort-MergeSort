#pragma once
#include <iostream>

struct Vetor {
private:
	int* vetor;
	int tamanho;

public:
	int TotalTestes;
	int TotalMovimentacoes;

	Vetor() {
		vetor = NULL;
		tamanho = 0;
		TotalMovimentacoes = 0;
		TotalTestes = 0;
	}

	/// <summary>
	/// Limpa o vetor com o valor padrão.
	/// </summary>
	void LimparVetorComZeros() {
		const int vazio = -1;

		if (tamanho > vazio) {
			memset(vetor, 0, tamanho * sizeof(int));
		}
	}

	/// <summary>
	/// Deleta a referência do ponteiro.
	/// </summary>
	void Deletar() {
		TotalMovimentacoes = 0;
		TotalTestes = 0;

		tamanho = 0;
		delete[] vetor;
		vetor = 0;
	}

	/// <summary>
	/// Inicializa o vetor com o tamanho definido.
	/// </summary>
	/// <param name="tamanho"></param>
	/// <returns></returns>
	bool Criar(int tamanho) {
		const int vazio = 0;

		// Se já estiver criado.
		Deletar();

		if (tamanho <= vazio) {
			return false;
		}

		this->tamanho = tamanho;
		vetor = new int[tamanho];

		if (vetor == NULL) {
			return false;
		}

		return true;
	}

	/// <summary>
	/// Retorna o tamanho do vetor.
	/// </summary>
	/// <returns></returns>
	int ObterTamanho() {
		return tamanho;
	}
	
	/// <summary>
	/// Obtém o ponteiro para o vetor.
	/// </summary>
	/// <returns></returns>
	int* ObterVetor() {
		return vetor;
	}

	/// <summary>
	/// Clona os valores da estrutura.
	/// </summary>
	/// <returns></returns>
	Vetor Clonar() {
		Vetor copia;

		copia.TotalTestes = TotalTestes;
		copia.TotalMovimentacoes = TotalMovimentacoes;

		if (copia.Criar(tamanho)) {
			int* p = copia.ObterVetor();
			memcpy(p, vetor, tamanho * sizeof(int));		
		}

		return copia;
	}
};