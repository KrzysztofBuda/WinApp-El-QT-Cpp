#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //dane
    double dzielnikR1 = 0;
    double dzielnikR2 = 0;
    QString dzielnik2R2;
    double dzielnikUwe = 0;

    int laczenieSzerR1Mnoznik = 0;
    int laczenieSzerR2Mnoznik = 0;
    double laczenieSzerR1;
    double laczenieSzerR2;
    int laczenieSzerJednostkaInt;
    QString laczenieSzerJednostka;
    int laczenieRownR1Mnoznik = 0;
    int laczenieRownR2Mnoznik = 0;
    double laczenieRownR1;
    double laczenieRownR2;
    int laczenieRownJednostkaInt;
    QString laczenieRownJednostka;

    float diodaNapiecieDiody = 0;
    int diodaPradDiody = 0;
    float diodaNapiecieZasilania = 0;
    int diodaIleDiod = 1;


    //wyniki
    double dzielnikUwy;
    double dzielnikIwy;
    double dzielnikPwy;

    double laczenieSzer;
    double laczenieSzerWynik;
    double laczenieRown;
    double laczenieRownWynik;

    double diodaRezystancja;

    double testwartosc1;
    double testwartosc2;
    int testmnoznik1;
    int testmnoznik2;
    double testwynik1;
    double testwynik2;
    double testwynik3;

private slots:
    void on_StartButton_clicked();

    void on_PomocButton_clicked();

    void on_DoMenu_clicked();

    void on_DzielnikNapiecia_clicked();

    void on_PomocButton_2_clicked();

    void on_dzielnikR1line_editingFinished();

    void on_dzielnikR2line_editingFinished();

    void on_dzielnikUweline_editingFinished();

    void on_pushButton_2_clicked();

    void on_laczenieButton_clicked();

    void on_laczenieSzerR1Box_currentIndexChanged(int index);

    void on_laczenieSzerR2Box_currentIndexChanged(int index);

    void on_laczenieObliczButton_clicked();

    void on_laczenieSzerR1Line_editingFinished();

    void on_laczenieSzerR2Line_editingFinished();

    void on_laczenieRownR1Box_currentIndexChanged(int index);

    void on_laczenieRownR2Box_currentIndexChanged(int index);

    void on_laczenieRownR1Line_editingFinished();

    void on_laczenieRownR2Line_editingFinished();

    void on_MocButton_clicked();

    void on_cofnijButton_clicked();

    void on_pomocButton3_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_diodyZasilanie_editingFinished();

    void on_diodaPomocButton_clicked();

    void on_diodaObliczButton_clicked();

    void on_diodaCofnijButton_clicked();

    void on_dzielnikCofnijButton_clicked();

    void on_ileDiodBox_valueChanged(int arg1);

    void on_diodaZapiszButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
