#include "FuncaoHorarioAtual.h"

tm horarioAtual(){
    time_t my;
    time(&my);
    tm tm = *localtime(&my);
    return tm;
}
