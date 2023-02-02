
#ifndef PROJETOBANCO_USUARYINTERFACE_H
#define PROJETOBANCO_USUARYINTERFACE_H

#include "../HierarquiaBanco/Banco.h"

class UsuaryInterface {
public:
    explicit UsuaryInterface(Banco *b){banco = b; clienteOuFuncionario = -1; escolhas = -1; acessoFuncionario = 0;}

    int getEscolhas() const {return this->escolhas;}

    void ClienteOuFuncionario();
    void loopFuncionalidades();
    void funcaoFuncionario(int);
    void funcaoCliente(int);
    void printDespedida();
    int getClienteOuFuncionario() const {return this->clienteOuFuncionario;}

private:
     Banco *banco;
     int clienteOuFuncionario;
     int escolhas;
     int acessoFuncionario;
     static void printLogoBanco() ;
     static void printOpcoesCliente() ;
     static void printOpcoesFuncionario();
};

#endif //PROJETOBANCO_USUARYINTERFACE_H
