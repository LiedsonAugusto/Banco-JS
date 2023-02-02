#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H
#include "../../ExtensoesGerais/ExtensoesGerais.h"

class ContaPoupanca : public Conta{
    public:

        explicit ContaPoupanca(int, double, Pessoa *,const tm &);

        ~ContaPoupanca() override;

        tm getData() const {return this->data;}

        void imprimirTransacoes() const override;
        
        void operator>>(double) override;

        void extrato() const override;

        void transferenciaEntreConta(Conta &c, double saldo) override;

    private:
        tm data;
};

#endif