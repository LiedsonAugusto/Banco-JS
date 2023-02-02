#ifndef CONTACORRENTECOMLIMITE_H
#define CONTACORRENTECOMLIMITE_H
#include "../../ExtensoesGerais/ExtensoesGerais.h"

class ContaCorrenteComLimite : public Conta{
    public:

    explicit ContaCorrenteComLimite(int, double,  Pessoa *, double);

    ~ContaCorrenteComLimite() override;

    void imprimirTransacoes() const override;

    double getLimite() const {return this->limite;}

    virtual void operator>>(double);

    void extrato() const override;

    void transferenciaEntreConta(Conta &c, double saldo) override;
    
    private:
        double limite;
};

#endif