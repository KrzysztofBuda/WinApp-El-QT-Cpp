#ifndef LACZENIE_H
#define LACZENIE_H
#include "QtCore"


class laczenie
{
public:
    double rownolegle(double laczenieRownR1,double laczenieRownrR2, int laczenieRownR1Mnoznik, int laczenieRownR2Mnoznik, double laczenieRown);
    int rownoleglejednostka(double laczenieRown, int laczenieRownJednostkaInt);
    double szeregowo(double laczenieSzerR1,double laczenieSzerR2, int laczenieSzerR1Mnoznik, int laczenieSzerR2Mnoznik, double laczenieSzer);
    int szeregowojednostka(double laczenieSzer, int laczenieSzerJednostkaInt);


};

#endif // LACZENIE_H
