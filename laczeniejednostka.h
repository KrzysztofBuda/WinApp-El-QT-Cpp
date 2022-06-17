#ifndef LACZENIEJEDNOSTKA_H
#define LACZENIEJEDNOSTKA_H
#include "QtCore"


class laczeniejednostka
{
public:
    double rownoleglewynik(double laczenieRown,int laczenieRownJednostkaInt, double laczenieRownWynik);
    QString rownoleglestring(QString laczenieRownJednostka, int laczenieRownJednostkaInt);
    double szeregowowynik(double laczenieSzer,int laczenieSzerJednostkaInt, double laczenieSzerWynik);
    QString szeregowostring(QString laczenieSzerJednostka, int laczenieSzerJednostkaInt);
};

#endif // LACZENIEJEDNOSTKA_H
