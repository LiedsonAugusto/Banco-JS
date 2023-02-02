#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H


#include "../../ExtensoesGerais/ExtensoesGerais.h"

class PessoaFisica : public Pessoa{
    public:

        explicit PessoaFisica(const string &, const string &);

        string getCpfOuCnpj() const override {return this->cpf;}

        string getNome() const override {return this->nome;}

        void mostrarDados() const override;

    private:
        string cpf;
};

#endif