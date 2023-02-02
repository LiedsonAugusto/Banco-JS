#ifndef BANCO_H
#define BANCO_H

#include "../ExtensoesGerais/ExtensoesGerais.h"

class Banco : public PessoaJuridica {

    public:
        explicit Banco(const string &, const string &, const string &, const string &, const string &);
        ~Banco() override;
        
        string getNomeBanco() const {return this->nomeBanco;}

        //funcionario
        void cadastraPessoa(int);
        void cadastrarConta(int, const string &);
        void removeConta(int);
        void removePessoa(const string &);
        void consultaContas(const string &) const;
        void consultaUnicaConta(int) const;
        void consultaPessoa(const string &) const;

        //cliente
        void depositarNaConta(int, double);
        void retiradaDaConta(int, double);
        void transferenciaEntreContas(int, int, double);
        bool conexaoContaCliente(int, const string&) const;
        void trocaDeNome(const string &, const string &);

        bool contasVazio() const {return this->contas.empty();}
        bool correntistasVazio() const {return this->correntistas.empty();}

    private:
        string nomeBanco;
        std::list<Conta *> contas;
        std::list<Pessoa *> correntistas;
        bool validarNumConta(int) const;
        bool validarNomePessoa(const string &)const ;
};

#endif