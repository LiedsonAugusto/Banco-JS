#include "../../ExtensoesGerais/ExtensoesGerais.h"
#include <iostream>

Transacoes::Transacoes(const tm &data, double valorTransacao, string descricao)
    : data(data), valorTransacao(valorTransacao), descricao(descricao) {}

void Transacoes::imprimirTransacao() const {
  std::cout << "Data: " << getData().tm_mday << "/" << getData().tm_mon + 1 << "/" << getData().tm_year + 1900 << " | "
            << "Valor da transação: " << getValorTransacao() << " | "
            << "Descrição: " << getDescricao() << '\n';
}