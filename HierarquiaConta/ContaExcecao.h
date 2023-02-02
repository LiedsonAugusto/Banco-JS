#ifndef PROJETOBANCO_CONTAEXCECAO_H
#define PROJETOBANCO_CONTAEXCECAO_H

//#include "../ExtensoesGerais/ExtensoesGerais.h"
#include <stdexcept>

class ContaExcecao : public std::logic_error{
public:
    explicit ContaExcecao(const char *e) : logic_error(e) {}
};

#endif
