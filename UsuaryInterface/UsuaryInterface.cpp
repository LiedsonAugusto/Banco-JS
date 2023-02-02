#include "UsuaryInterface.h"
#include <iostream>
#include "stdlib.h"
using std::cout;

void UsuaryInterface::printLogoBanco() {
    cout << "\n";
    cout << "|-----------------------|\n";
    cout << "|       BANCO JS        |\n";
    cout << "|-----------------------|\n\n";
}

void UsuaryInterface::printOpcoesCliente() {
    cout << "| [1] DEPOSITAR\n";
    cout << "| [2] RETIRAR\n";
    cout << "| [3] EXTRATO BANCARIO\n";
    cout << "| [4] TRANSFERENCIA\n";
    cout << "| [5] ATUALIZAR NOME DA CONTA\n";
    cout << "| [6] TROCAR PARA FUNCIONARIO\n";
    cout << "| [7] SAIR\n";
}

void UsuaryInterface::printOpcoesFuncionario() {
    cout << "| [1] CADASTRAR PESSOA\n";
    cout << "| [2] CADASTRAR CONTA\n";
    cout << "| [3] REMOVER CONTA\n";
    cout << "| [4] REMOVER PESSOA\n";
    cout << "| [5] CONSULTAR CONTA UNICA\n";
    cout << "| [6] CONSULTAR TODAS AS CONTAS\n";
    cout << "| [7] CONSULTAR PESSOA\n";
    cout << "| [8] TROCAR PARA CLIENTE\n";
    cout << "| [9] SAIR\n";
}

void UsuaryInterface::printDespedida() {
    cout << "\n|-----------------------|\n";
    cout << "         OBRIGADO         \n";
    cout << "       VOLTE SEMPRE       \n";
    cout << "|-----------------------|\n";
}

void UsuaryInterface::ClienteOuFuncionario() {
    std::cout << "Deseja entrar como:\n";
    std::cout << "| [1] FUNCIONARIO\n";
    std::cout << "| [2] CLIENTE\n";
    std::cout << "Decisao: ";
    std::cin >> clienteOuFuncionario;
    while ((getClienteOuFuncionario() != 1) && (2 != getClienteOuFuncionario())){
        std::cout << "\nDigite opção valida\n";
        std::cout << "Decisao: ";
        std::cin >> clienteOuFuncionario;
    }
}

void UsuaryInterface::funcaoFuncionario(int escolha) {
    string cpfOuCnpj;
    int fisicaJuridica, tipoDaConta, numConta;
    switch (escolha){
        case 1:
            std::cout << "\n| [1] JURIDICA\n";
            std::cout << "| [2] FISICA\n";
            std::cout << "Decisao: ";
            std::cin >> fisicaJuridica;
            while (fisicaJuridica != 1 && fisicaJuridica != 2){
                std::cout << "\nDigite opção valida\n";
                std::cout << "Decisao: ";
                std::cin >> fisicaJuridica;
            }
            banco->cadastraPessoa(fisicaJuridica);
            std::cout << "\n * PESSOA CADASTRADA * \n";
            break;
        case 2:
            std::cout << "\n| [1] COMUM\n";
            std::cout << "| [2] POUPANCA\n";
            std::cout << "| [3] LIMITE\n";
            std::cout << "Decisao: ";
            std::cin >> tipoDaConta;
            while (tipoDaConta != 1 && tipoDaConta != 2 && tipoDaConta != 3){
                std::cout << "\nDigite opção valida\n";
                std::cout << "Decisao: ";
                std::cin >> tipoDaConta;
            }
            std::cout << "\nDigite o CPF ou CNPJ: ";
            std::cin >> cpfOuCnpj;
            banco->cadastrarConta(tipoDaConta, cpfOuCnpj);
            std::cout << "\n * CONTA CADASTRADA * \n";
            break;
        case 3:
            if(banco->contasVazio()){
                throw BancoExcecao("\nNao existem contas para serem removidas");
            }
            std::cout << "\nDigite o numero da conta: ";
            std::cin >> numConta;
            banco->removeConta(numConta);
            std::cout << "\n * CONTA REMOVIDA * \n";
            break;
        case 4:
            if(banco->correntistasVazio()){
                throw BancoExcecao("\nNao existem pessoas para serem removidas");
            }
            std::cout << "\nDigite o CPF ou CNPJ que deseja remover: ";
            std::cin >> cpfOuCnpj;
            banco->removePessoa(cpfOuCnpj);
            std::cout << "\n * PESSOA REMOVIDA * \n";
            break;
        case 5:
            if(banco->contasVazio()){
                throw BancoExcecao("\nNao existem contas para serem consultadas");
            }
            std::cout << "\nDigite o numero da conta: ";
            std::cin >> numConta;
            banco->consultaUnicaConta(numConta);
            break;
        case 6:
            if(banco->contasVazio()){
                throw BancoExcecao("\nNao existem contas para serem consultadas");
            }
            std::cout << "\nDigite o CPF ou CNPJ das contas: ";
            std::cin >> cpfOuCnpj;
            banco->consultaContas(cpfOuCnpj);
            break;
        case 7:
            if(banco->correntistasVazio()){
                throw BancoExcecao("\nNao existem pessoas para serem consultadas");
            }
            std::cout << "\nDigite o CPF ou CNPJ que deseja consultar: ";
            std::cin >>cpfOuCnpj;
            banco->consultaPessoa(cpfOuCnpj);
            break;
        case 8:
            if(banco->correntistasVazio()){
                throw BancoExcecao("\nNao existem clientes cadastrados");
            }
            acessoFuncionario = 0;
            this->clienteOuFuncionario = (this->clienteOuFuncionario = 1) ? 2 : 1;
            break;
    }

}

void UsuaryInterface::funcaoCliente(int escolha) {
    string novoNome;
    int numConta, numConta2;
    double saldo;
    string cpfOuCnpj;
    std::getchar();
    switch (escolha){
        case 1:
            std::cout << "\nDigite o numero da conta que deseja depositar: ";
            std::cin >> numConta;
            std::cout << "\nDigite o valor do deposito: ";
            std::cin >> saldo;
            banco->depositarNaConta(numConta, saldo);

            std::cout << "\n * DEPÓSITO EFETUADO * \n";
            break;
        case 2:
            std::cout << "\nDigite o numero da conta que deseja retirar: ";
            std::cin >> numConta;
            std::cout << "\nDigite o CPF ou CNPJ da conta: ";
            std::cin >> cpfOuCnpj;
            if (banco->conexaoContaCliente(numConta, cpfOuCnpj)){
                std::cout << "\nDigite quanto deseja sacar: ";
                std::cin >> saldo;
                banco->retiradaDaConta(numConta, saldo);
                std::cout << "\n * SAQUE EFETUADO * \n";
            } else {
                throw ContaExcecao("\nCPF ou CNPJ da conta invalido.");
            }
            break;
        case 3:
            std::cout << "\nDigite o numero da conta que ver o extrato: ";
            std::cin >> numConta;
            banco->consultaUnicaConta(numConta);
            std::cout << '\n';
            break;
        case 4:
            std::cout << "\nDigite o numero da conta que ira realizar a transferencia: ";
            std::cin >> numConta;
            std::cout << "\nDigite o CPF ou CNPJ da conta: ";
            std::cin >> cpfOuCnpj;
            if (banco->conexaoContaCliente(numConta, cpfOuCnpj)){
                std::cout << "\nDigite o numero da conta que ira receber a transferencia: ";
                std::cin >> numConta2;
                std::cout << "\nDigite quanto deseja transferir: ";
                std::cin >> saldo;
                banco->transferenciaEntreContas(numConta, numConta2, saldo);
                std::cout << "\n * TRANSFERENCIA EFETUADA * \n";
            } else {
                throw ContaExcecao("\nCPF ou CNPJ da conta invalido.");
            }
            break;
        case 5:
            std::cout << "\nDigite o CPF ou CNPJ que deseja mudar o nome: ";
            std::getline(std::cin, cpfOuCnpj);
            std::cout << "\nDigite para qual nome deseja mudar: ";
            std::getline(std::cin, novoNome);
            banco->trocaDeNome(novoNome, cpfOuCnpj);
            std::cout << "\n * NOME ATUALIZADO * \n";
            break;
        case 6:
            this->clienteOuFuncionario = (this->clienteOuFuncionario == 1) ? 2 : 1;
            break;
        case 7:
            this->escolhas = 9;
            break;
    }
}

void UsuaryInterface::loopFuncionalidades() {
    string cnpjFuncionario;
    while (this->escolhas != 9) {
        switch (this->clienteOuFuncionario){
            case 1:
                while(acessoFuncionario != 1){
                    std::cout << "\nDigite o seu CNPJ: ";
                    std::cin >> cnpjFuncionario;
                    while (cnpjFuncionario != banco->getCpfOuCnpj()){
                        std::cout << "\nErro. CNPJ nao correspondente.\n";
                        std::cout << "Digite o seu CNPJ: ";
                        std::cin >> cnpjFuncionario;
                    }
                    acessoFuncionario = 1;
                }
                printLogoBanco();
                printOpcoesFuncionario();
                std::cout << "Decisao: ";
                std::cin >> this->escolhas;
                while(this->escolhas < 1 || this->escolhas > 9){
                    std::cout << "Digite valor valido.\n";
                    std::cin >> this->escolhas;
                }
                funcaoFuncionario(this->escolhas);
                break;
            case 2:
                printLogoBanco();
                printOpcoesCliente();
                std::cout << "Decisao: ";
                std::cin >> this->escolhas;
                while(this->escolhas < 1 || this->escolhas > 6){
                    std::cout << "\nDigite valor valido.\n";
                    std::cin >> this->escolhas;
                }
                funcaoCliente(this->escolhas);
                break;
        }
    }
}