#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>
#include "../../HorarioAtual/FuncaoHorarioAtual.h"
using std::string;

class Transacoes {
  public:
    explicit Transacoes(const tm &, double, string);

    tm getData() const {return this->data;}
    double getValorTransacao() const {return this->valorTransacao;}
    string getDescricao() const {return this->descricao;}

    void imprimirTransacao() const;

  
  private:
    tm data;
    double valorTransacao;
    string descricao;
};

#endif