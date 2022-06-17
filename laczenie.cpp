#include "laczenie.h"
#include "cmath"


double laczenie::rownolegle(double laczenieRownR1,double laczenieRownR2, int laczenieRownR1Mnoznik, int laczenieRownR2Mnoznik, double laczenieRown){
    laczenieRown = ((laczenieRownR1*pow(10,laczenieRownR1Mnoznik))*(laczenieRownR2*pow(10,laczenieRownR2Mnoznik)))/((laczenieRownR1*pow(10,laczenieRownR1Mnoznik))+(laczenieRownR2*pow(10,laczenieRownR2Mnoznik)));

    return laczenieRown;
}

int laczenie::rownoleglejednostka(double laczenieRown, int laczenieRownJednostkaInt){
    if (laczenieRown > 1000){
        for(laczenieRownJednostkaInt = 0; laczenieRown > 1000; laczenieRownJednostkaInt++){
            laczenieRown = laczenieRown / 1000;
        }
    } else {
        laczenieRownJednostkaInt = 0;
    }

    return laczenieRownJednostkaInt;
}

double laczenie::szeregowo(double laczenieSzerR1,double laczenieSzerR2, int laczenieSzerR1Mnoznik, int laczenieSzerR2Mnoznik, double laczenieSzer){
    laczenieSzer = laczenieSzerR1 * pow(10,laczenieSzerR1Mnoznik) + laczenieSzerR2 * pow(10,laczenieSzerR2Mnoznik);
    return laczenieSzer;
}

int laczenie::szeregowojednostka(double laczenieSzer, int laczenieSzerJednostkaInt){

    if (laczenieSzer > 1000){
        for(laczenieSzerJednostkaInt = 0; laczenieSzer > 1000; laczenieSzerJednostkaInt++){
            laczenieSzer = laczenieSzer / 1000;
        }
    } else {
        laczenieSzerJednostkaInt = 0;
    }

    return laczenieSzerJednostkaInt;
}
