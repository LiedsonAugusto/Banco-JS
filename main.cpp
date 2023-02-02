#include <iostream>
#include <locale.h>
#include "ExtensoesGerais/ExtensoesGerais.h"



int main(){
    setlocale(LC_ALL, "Portuguese");
    Banco bancoJS("Liedson", "1234", "abc", "lied", "bancoJS");
    UsuaryInterface us(&bancoJS);
    us.ClienteOuFuncionario();
    do {
        try{us.loopFuncionalidades();
            us.printDespedida();

        } catch (BancoExcecao &e){
            std::cout << "\nErro! " << e.what() << '\n';
        } catch (ContaExcecao &e) {
            std::cout << "\nErro! " << e.what() << '\n';
        } catch (std::exception &e){
            std::cout << "\nErro inesperado.\n";
        }
    }
    while (us.getEscolhas() != 9);

    return 0;
}