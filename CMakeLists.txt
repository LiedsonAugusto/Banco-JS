cmake_minimum_required(VERSION 3.22)

project(ProjetoBanco)

set(CMAKE_CXX_STANDARD 14)

add_executable(empty
        ExtensoesGerais/ExtensoesGerais.h
        HierarquiaBanco/BancoExcecoes.h
        HierarquiaBanco/Banco.h
        HierarquiaBanco/Banco.cpp
        HierarquiaConta/Conta.h
        HierarquiaConta/Transacoes/Transacoes.h
        HierarquiaConta/Transacoes/Transacoes.cpp
        HierarquiaConta/ContaPoupanca/ContaPoupanca.h
        HierarquiaConta/ContaPoupanca/ContaPoupanca.cpp
        HierarquiaConta/ContaCorrenteComum/ContaCorrenteComum.h
        HierarquiaConta/ContaCorrenteComum/ContaCorrenteComum.cpp
        HierarquiaConta/ContaCorrenteComLimite/ContaCorrenteComLimite.cpp
        HierarquiaConta/ContaCorrenteComLimite/ContaCorrenteComLimite.h
        HierarquiaPessoa/Pessoa.h
        HierarquiaPessoa/PessoaFisica/PessoaFisica.h
        HierarquiaPessoa/PessoaFisica/PessoaFisica.cpp
        HierarquiaPessoa/PessoaJuridica/PessoaJuridica.h
        HierarquiaPessoa/PessoaJuridica/PessoaJuridica.cpp
        main.cpp
        HierarquiaConta/ContaExcecao.h
        UsuaryInterface/UsuaryInterface.h
        UsuaryInterface/UsuaryInterface.cpp
        HorarioAtual/FuncaoHorarioAtual.h
        HorarioAtual/FuncaoHorarioAtual.cpp)