#include "Vahb_apb.h"

Vahb_apb* create_Vahb_apb() {
    return new Vahb_apb();
}

void eval (Vahb_apb* obj) {
    obj->eval();
}

void finalize (Vahb_apb* obj) {
    obj->final();
}
