#include <iostream>
#include "../../ExtensoesGerais/ExtensoesGerais.h"

ContaCorrenteComLimite::ContaCorrenteComLimite(int numConta, double saldo, Pessoa *p, double limite)
: Conta(numConta, saldo, p), limite(limite) {}

ContaCorrenteComLimite::~ContaCorrenteComLimite(){
    delete nomeCorrentista;
}

void ContaCorrenteComLimite::imprimirTransacoes() const {
    if (this->listTransacoes.size() > 30){
        int contador = 0;
        for (auto &list : listTransacoes){
            if (contador == 29){
                break;
            } else {
                list.imprimirTransacao();
            }
            contador++;
        }
    } else {
        for (auto &list : listTransacoes){
            list.imprimirTransacao();
        }
    }
}

void ContaCorrenteComLimite::operator>>(double saldo){
    if (saldo == 0){
        throw ContaExcecao("Valor para retirada invalido");
    }
    if (saldo > this->saldo){
        throw ContaExcecao("Valor da conta insuficiente para o saldo.");
    }
    if (saldo > this->limite){
        throw ContaExcecao("Valor de retirada superior ao limite da conta.");
    }
    this->saldo -= saldo;
    listTransacoes.push_back(Transacoes(horarioAtual(), saldo, "Saque"));
}

void ContaCorrenteComLimite::extrato() const {
    std::cout << "---------- CONTA LIMITE ----------\n";
    std::cout << "Numero da conta: " << getNumConta();
    std::cout << "\nNome: " << getNome();
    std::cout << "\nSaldo: " << getSaldo();
    std::cout << "\nLimite: " << getLimite() << '\n';
    if (!this->listTransacoes.empty()){
        std::cout << "Transaçoes: " << '\n';
        imprimirTransacoes();
    }
    std::cout << "--------------------------------------\n";
}

void ContaCorrenteComLimite::transferenciaEntreConta(Conta &conta, double saldo){
    if (&conta == this){
        throw ContaExcecao("Nao se deve fazer transferencia para a mesma conta");
    }
    if (saldo > this->saldo){
        throw ContaExcecao("Valor a ser transferido e maior que o valor existente na conta.");
    }
    if (saldo > this->limite){
        throw ContaExcecao("Valor a ser transferido e superior ao limite da conta.");
    }
    this->saldo -= saldo;
    conta << saldo;
    listTransacoes.push_back(Transacoes(horarioAtual(), saldo, "Transferencia"));
}