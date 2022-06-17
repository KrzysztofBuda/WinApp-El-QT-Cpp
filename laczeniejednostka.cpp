#include "laczeniejednostka.h"

double laczeniejednostka::rownoleglewynik(double laczenieRown,int laczenieRownJednostkaInt, double laczenieRownWynik){

    laczenieRownWynik = laczenieRown / pow(10,3*laczenieRownJednostkaInt);

    return laczenieRownWynik;
}
QString laczeniejednostka::rownoleglestring(QString laczenieRownJednostka, int laczenieRownJednostkaInt){

    if (laczenieRownJednostkaInt == 0){
        laczenieRownJednostka = " Ohm";

    }else if (laczenieRownJednostkaInt == 1){
        laczenieRownJednostka = " kOhm";
    }else if (laczenieRownJednostkaInt == 2){
        laczenieRownJednostka = " MOhm";
    }else if (laczenieRownJednostkaInt == 3){
        laczenieRownJednostka = " GOhm";
    }else {
        laczenieRownJednostka = "inna";
    }

    return laczenieRownJednostka;
}

double laczeniejednostka::szeregowowynik(double laczenieSzer,int laczenieSzerJednostkaInt, double laczenieSzerWynik){

    laczenieSzerWynik = laczenieSzer / pow(10,3*laczenieSzerJednostkaInt);

    return laczenieSzerWynik;
}

QString laczeniejednostka::szeregowostring(QString laczenieSzerJednostka, int laczenieSzerJednostkaInt){
    if (laczenieSzerJednostkaInt == 0){
        laczenieSzerJednostka = " Ohm";

    }else if (laczenieSzerJednostkaInt == 1){
        laczenieSzerJednostka = " kOhm";
    }else if (laczenieSzerJednostkaInt == 2){
        laczenieSzerJednostka = " MOhm";
    }else if (laczenieSzerJednostkaInt == 3){
        laczenieSzerJednostka = " GOhm";
    }else {
        laczenieSzerJednostka = "inna";
    }

    return laczenieSzerJednostka;
}
