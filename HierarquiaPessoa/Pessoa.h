#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;
class Pessoa{
    public:

        explicit Pessoa(const string &nome) : nome(nome) {}

        virtual ~Pessoa(){}

        virtual void mostrarDados() const = 0;
        virtual string getCpfOuCnpj() const = 0;
        virtual string getNome() const {return this->nome;};
        virtual void setNome(const string &nome) {this->nome = nome;}

    protected:
        string nome;
};

#endif