#include "diodarezystor.h"
#include "cmath"

double diodaRezystor::rezystancja(float diodaNapiecieDiody, float diodaNapiecieZasilania, int diodaIleDiod, int diodaPradDiody, double diodaRezystancja){

    diodaRezystancja = (diodaNapiecieZasilania - diodaNapiecieDiody*diodaIleDiod) / (diodaPradDiody*pow(10,-3));

    return diodaRezystancja;
}
