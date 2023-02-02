#include <iostream>
#include "../ExtensoesGerais/ExtensoesGerais.h"
#include "Banco.h"

#include <cstdlib>
#include <ctime>
#include<bits/stdc++.h>

Banco::Banco(const string &nomePessoa, const string &cnpj, const string &razaoSocial, const string &nomeFantasia, const string &nomeBanco):
PessoaJuridica(nomePessoa, cnpj, razaoSocial, nomeFantasia), nomeBanco(nomeBanco) {}

Banco::~Banco(){
    for(auto &list : contas){
        delete list;
    }

    for(auto &list2 : correntistas){
        delete list2;
    }
}

void Banco::cadastraPessoa(int escolha){
    string nome, razaoSocial, nomeFantasia, cnpj, cpf;
    std::getchar();
    switch(escolha){
        //Juridica
        case 1:
            std::cout << "\nNome: ";
            std::getline(std::cin, nome);
            std::cout << "\nRazao Social: ";
            std::getline(std::cin, razaoSocial);
            std::cout << "\nNome Fantasia: ";
            std::getline(std::cin, nomeFantasia);
            std::cout << "\nCNPJ: ";
            std::getline(std::cin, cnpj);
            if(validarNomePessoa(cnpj)){
                throw BancoExcecao("\nJa existe conta com esse CNPJ.");
            }
            correntistas.push_back(new PessoaJuridica(nome, cnpj, razaoSocial, nomeFantasia));
            break;
        //Fisica
        case 2:
            std::cout << "\nNome: ";
            std::getline(std::cin, nome);
            std::cout << "\nCPF: ";
            std::getline(std::cin, cpf);
            if(validarNomePessoa(cpf)){
                throw BancoExcecao("\nJa existe conta com esse CPF.");
            }
            correntistas.push_back(new PessoaFisica(nome, cpf));
            break;
    }
}

bool Banco::validarNumConta(int numConta)const{
    for(auto &list : contas){
        if (list->getNumConta() == numConta){
            return true;
        }
    }
    return false;
}

bool Banco::validarNomePessoa(const string &cpfOuCnpj)const{
    for (auto &list : correntistas){
        if (list->getCpfOuCnpj() == cpfOuCnpj){
            return true;
        }
    }
    return false;
}

void Banco::cadastrarConta(int escolha, const string &cpfOuCnpj){
    
    string data;
    int numConta;
    double saldo;
    if (!validarNomePessoa(cpfOuCnpj)){
        throw BancoExcecao("\nPessoa nao cadastrada, cadastre primeiro para criar a conta");
    }

    std::list<Pessoa *>::iterator ite2;
    for(auto &list : correntistas){
        if(list->getCpfOuCnpj() == cpfOuCnpj){
            ite2 = std::find (correntistas.begin(), correntistas.end(), list);
        }

    }

    unsigned seed = time(nullptr);
    srand(seed);
    numConta = rand()%10000;
    while(validarNumConta(numConta)){
        numConta = rand()%10000;
    }

    switch (escolha){
        //comum
        case 1:
            std::cout << "\nDigite o valor do saldo: ";
            std::cin >> saldo;
            if(saldo < 0){
                throw BancoExcecao("\nSaldo negativo e inexistente");
            }
            contas.push_back(new ContaCorrenteComum(numConta, saldo, *ite2));
            break;
        //poupança
        case 2:
            std::cout << "\nDigite o valor do saldo: ";
            std::cin >> saldo;
            if(saldo < 0){
                throw BancoExcecao("\nSaldo negativo e inexistente");
            }
            contas.push_back(new ContaPoupanca(numConta, saldo, *ite2, horarioAtual()));
            break;
        //limite
        case 3:
            std::cout << "\nDigite o valor do saldo: ";
            std::cin >> saldo;
            if(saldo < 0){
                throw BancoExcecao("\nSaldo negativo e inexistente");
            }
            contas.push_back(new ContaCorrenteComLimite(numConta, saldo, *ite2, 1000));
            std::cout << "\n * LIMITE DA CONTA : R$1000.0 * \n";
            break;
    }
    std::cout << "\n* NUMERO DA CONTA * - " << numConta << '\n';
}

void Banco::removePessoa(const string &cpfoucnpj) {
    if (!validarNomePessoa(cpfoucnpj)){
        throw BancoExcecao("\nPessoa nao cadastrada");
    }
    for (auto &list : contas){
        if (list->getCpfOuCnpjCorrentista() == cpfoucnpj){
            delete list;
        }
    }
    std::list<Pessoa *>::iterator ite2 = correntistas.begin();

    for (auto &list : correntistas){
        if (list->getCpfOuCnpj() == cpfoucnpj){
            correntistas.erase(ite2);
            delete list;
        }
        ++ite2;
    }
}

void Banco::removeConta(int numConta){
    if (!validarNumConta(numConta)){
        throw BancoExcecao("\nConta nao existente.");
    }
    auto ite2 = contas.begin();
    for(auto &list : contas){
        if (list->getNumConta() == numConta){
            contas.erase(ite2);
            delete list;
        }
        ++ite2;
    }
}

void Banco::consultaContas(const string &cpfOuCnpj) const {
    if (!validarNomePessoa(cpfOuCnpj)){
        throw BancoExcecao("\nPessoa nao cadastrada.");
    }
    for (auto &list : contas){
        if(list->getCpfOuCnpjCorrentista() == cpfOuCnpj){
            list->extrato();
        }
    }
}

void Banco::consultaUnicaConta(int numConta) const {
    if (!validarNumConta(numConta)){
        throw BancoExcecao("\nConta nao existente.");
    }
    for (auto &list : contas){
        if (list->getNumConta() == numConta){
            list->extrato();
        }
    }
}

void Banco::depositarNaConta(int numConta, double saldo) {
    if (!validarNumConta(numConta)){
        throw BancoExcecao("\nConta nao existente.");
    }
    for (auto &list: contas){
        if (list->getNumConta() == numConta){
            *list << saldo;
        }
    }
}

void Banco::retiradaDaConta(int numConta, double saldo) {
    if (!validarNumConta(numConta)){
        throw BancoExcecao("\nConta nao existente.");
    }
    for (auto &list: contas){
        if (list->getNumConta() == numConta){
            *list >> saldo;
        }
    }
}

void Banco::transferenciaEntreContas(int numConta1, int numConta2, double saldo) {
    if (!validarNumConta(numConta1)){
        throw BancoExcecao("\nConta nao existente.");
    }
    if (!validarNumConta(numConta2)){
        throw BancoExcecao("\nConta nao existente.");
    }
    for (auto &list : contas){
        if (list->getNumConta() == numConta1){
            for (auto &list2 : contas){
                if (list2->getNumConta() == numConta2){
                    if(list->getNumConta() == list2->getNumConta()){
                        throw ContaExcecao("\nNao se pode fazer transferencia para a mesma conta.");
                    }
                    list->transferenciaEntreConta(*list2, saldo);
                }
            }
        }
    }
}

bool Banco::conexaoContaCliente(int numConta, const string& cpfOuCnpj) const {
    if (!validarNumConta(numConta)){
        throw BancoExcecao("\nConta nao existente.");
    }
    if (!validarNomePessoa(cpfOuCnpj)){
        throw BancoExcecao("\nPessoa nao cadastrada");
    }
    for (auto &list : contas){
        if (list->getNumConta() == numConta && list->getCpfOuCnpjCorrentista() == cpfOuCnpj){
            return true;
        }
    }
    return false;
}

void Banco::consultaPessoa(const string &cpfOuCnpj) const {
    if (!validarNomePessoa(cpfOuCnpj)){
        throw BancoExcecao("\nPessoa nao cadastrada");
    }
    for (auto &list : correntistas){
        if (list->getCpfOuCnpj() == cpfOuCnpj){
            list->mostrarDados();
        }
    }
}

void Banco::trocaDeNome(const string &nome, const string &cpfOuCnpj) {
    for (auto &list : correntistas){
        if (list->getCpfOuCnpj() == cpfOuCnpj){
            list->setNome(nome);
        }
    }
}