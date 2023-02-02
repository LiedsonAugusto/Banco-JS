#ifndef CONTACORRENTECOMUM_H
#define CONTACORRENTECOMUM_H
#include "../../ExtensoesGerais/ExtensoesGerais.h"

class ContaCorrenteComum : public Conta{
    public:

        explicit ContaCorrenteComum(int, double, Pessoa *);

        ~ContaCorrenteComum() override;

        void imprimirTransacoes() const override;

        void operator>>(double) override;

        void extrato() const override;

        void transferenciaEntreConta(Conta &c, double saldo) override;

};

#endif