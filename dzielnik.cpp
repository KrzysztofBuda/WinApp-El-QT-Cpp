#include "mainwindow.h"
#include "dzielnik.h"

double dzielnik::napiecie(double dzielnikUwe, double dzielnikR1, double dzielnikR2, double dzielnikUwy){
    dzielnikUwy = dzielnikUwe * dzielnikR2 /(dzielnikR1 + dzielnikR2);
    return dzielnikUwy;
}

double dzielnik::prad(double dzielnikUwe, double dzielnikR1, double dzielnikR2, double dzielnikIwy){
    dzielnikIwy = dzielnikUwe/(dzielnikR1 + dzielnikR2);
    return dzielnikIwy;
}

double dzielnik::moc(double dzielnikUwy, double dzielnikIwy, double dzielnikPwy){
    dzielnikPwy = dzielnikIwy * dzielnikUwy;
    return dzielnikPwy;
}
