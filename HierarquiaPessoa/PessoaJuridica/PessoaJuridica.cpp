#include <iostream>
#include "../../ExtensoesGerais/ExtensoesGerais.h"

PessoaJuridica::PessoaJuridica(const string &nome,const string &cnpj,const string &razaoSocial,const string &nomeFantasia) : Pessoa(nome), 
cnpj(cnpj), razaoSocial(razaoSocial), nomeFantasia(nomeFantasia) {}

void PessoaJuridica::mostrarDados() const  {
    std::cout << "---------- PESSOA JURIDICA ----------\n";
    std::cout << "Nome: " << getNome();
    std::cout << "\nCNPJ: " << getCpfOuCnpj();
    std::cout << "\nRazao Social: " << getRazaoSocial();
    std::cout << "\nNome Fantasia: "<< getNomeFantasia();
    std::cout << "\n------------------------------------\n";
}