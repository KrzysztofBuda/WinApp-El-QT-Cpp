#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "dzielnik.h"
#include "laczenie.h"
#include "testclass.h"
#include "diodarezystor.h"
#include "laczeniejednostka.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_StartButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_PomocButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_DoMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_DzielnikNapiecia_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_PomocButton_2_clicked()
{
    QMessageBox::about(this, "Pomoc. Dzielnik Napięciwy", "Separatorem dziesiętnym musi być kropka (.). \n"
                                                                "Podane muszą zostać wszystkie dane wejściowe (R1,R2,Uwe). \n"
                                                                "Odpowiedzą są Uwy, I - prąd P - moc." );
}


void MainWindow::on_dzielnikR1line_editingFinished()
{
    dzielnikR1 = ui->dzielnikR1line->text().toDouble();
}


void MainWindow::on_dzielnikR2line_editingFinished()
{
    dzielnik2R2 = ui->dzielnikR2line->text();
    for (int i = 0; i<dzielnik2R2.length(); i++)
    {
        if (dzielnik2R2[i] == ',')
            QMessageBox::warning(this, "Błąd","R2 zamień przecinek na kropkę");
            //x[i] = '.' ;
    }
    dzielnikR2 = dzielnik2R2.toDouble();
}


void MainWindow::on_dzielnikUweline_editingFinished()
{
    dzielnikUwe = ui->dzielnikUweline->text().toDouble();
}


void MainWindow::on_pushButton_2_clicked()
{
    if ((dzielnikR1 != 0 and dzielnikR2 != 0) and dzielnikUwe != 0){
        dzielnik dz;
        dzielnikUwy = dz.napiecie(dzielnikUwe, dzielnikR1, dzielnikR2, dzielnikUwy);
        dzielnikIwy = dz.prad(dzielnikUwe, dzielnikR1, dzielnikR2, dzielnikIwy);
        ui->dzielnikUwylabel->setText(QString::number(dzielnikUwy) + " V");
        ui->dzielnikIlabel->setText(QString::number(dz.prad(dzielnikUwe, dzielnikR1, dzielnikR2, dzielnikIwy)) + " A");
        ui->dzielnikPlabel->setText(QString::number(dz.moc(dzielnikIwy,dzielnikUwy,dzielnikPwy)) + " W");


    } else {
        QMessageBox::warning(this, "Błąd", "Musisz podać wszystkie wartości");

    }
}


void MainWindow::on_laczenieButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_laczenieSzerR1Box_currentIndexChanged(int index)
{
    index = ui->laczenieSzerR1Box->currentIndex();
    if (index > 0){
        laczenieSzerR1Mnoznik = index * 3;
    } else {
        laczenieSzerR1Mnoznik = 0 ;
    }
}


void MainWindow::on_laczenieSzerR2Box_currentIndexChanged(int index)
{
    index = ui->laczenieSzerR2Box->currentIndex();
    if (index > 0){
        laczenieSzerR2Mnoznik = index * 3;
    } else {
        laczenieSzerR2Mnoznik = 0 ;
    }
}

void MainWindow::on_laczenieSzerR1Line_editingFinished()
{
    laczenieSzerR1 = ui->laczenieSzerR1Line->text().toDouble();
}


void MainWindow::on_laczenieSzerR2Line_editingFinished()
{
    laczenieSzerR2 = ui->laczenieSzerR2Line->text().toDouble();
}

void MainWindow::on_laczenieRownR1Box_currentIndexChanged(int index)
{
    index = ui->laczenieRownR1Box->currentIndex();
    if (index > 0){
        laczenieRownR1Mnoznik = index * 3;
    } else {
        laczenieRownR1Mnoznik = 0 ;
    }
}

void MainWindow::on_laczenieRownR2Box_currentIndexChanged(int index)
{
    index = ui->laczenieRownR2Box->currentIndex();
    if (index > 0){
        laczenieRownR2Mnoznik = index * 3;
    } else {
        laczenieRownR2Mnoznik = 0 ;
    }
}

void MainWindow::on_laczenieRownR1Line_editingFinished()
{
    laczenieRownR1 = ui->laczenieRownR1Line->text().toDouble();
}


void MainWindow::on_laczenieRownR2Line_editingFinished()
{
    laczenieRownR2 = ui->laczenieRownR2Line->text().toDouble();
}

void MainWindow::on_laczenieObliczButton_clicked()
{
    laczenie la;
    laczenieSzer = la.szeregowo(laczenieSzerR1,laczenieSzerR2,laczenieSzerR1Mnoznik,laczenieSzerR2Mnoznik,laczenieSzer);
    laczenieSzerJednostkaInt = la.szeregowojednostka(laczenieSzer,laczenieSzerJednostkaInt);

    laczeniejednostka lajd;
    laczenieSzerWynik = lajd.szeregowowynik(laczenieSzer,laczenieSzerJednostkaInt,laczenieSzerWynik);
    laczenieSzerJednostka = lajd.szeregowostring(laczenieSzerJednostka, laczenieSzerJednostkaInt);

    ui->laczenieSzerLabel->setText(QString::number((int)laczenieSzerWynik) + laczenieSzerJednostka);

    //laczenie ro;
    laczenieRown = la.rownolegle(laczenieRownR1,laczenieRownR2,laczenieRownR1Mnoznik,laczenieRownR2Mnoznik,laczenieRown);
    laczenieRownJednostkaInt = la.rownoleglejednostka(laczenieRown,laczenieRownJednostkaInt);

    //laczeniejednostka rojd;
    laczenieRownWynik = lajd.rownoleglewynik(laczenieRown,laczenieRownJednostkaInt,laczenieRownWynik);
    laczenieRownJednostka = lajd.rownoleglestring(laczenieRownJednostka, laczenieRownJednostkaInt);

    ui->laczenieRownLabel->setText(QString::number((int)laczenieRownWynik) + laczenieRownJednostka);
}


void MainWindow::on_MocButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_cofnijButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pomocButton3_clicked()
{
    QMessageBox::about(this,"Pomoc","Przecież wszystko jasne");
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch (index){
    case 0:
        diodaNapiecieDiody = 0;
        diodaPradDiody = 0;
        break;
    case 1:
        diodaNapiecieDiody = 1.7;
        diodaPradDiody = 10;
        break;
    case 2:
        diodaNapiecieDiody = 1.7;
        diodaPradDiody = 2;
        break;
    case 3:
        diodaNapiecieDiody = 2.1;
        diodaPradDiody = 10;
        break;
    case 4:
        diodaNapiecieDiody = 2.2;
        diodaPradDiody = 10;
        break;
    case 5:
        diodaNapiecieDiody = 3.4;
        diodaPradDiody = 20;
        break;
    case 6:
        diodaNapiecieDiody = 5.4;
        diodaPradDiody = 20;
        break;
    case 7:
        diodaNapiecieDiody = 3.6;
        diodaPradDiody = 20;
        break;
    }
    ui->diodaNapieceLabel->setText(QString::number(diodaNapiecieDiody) + " V");
    ui->diodaPradLabel->setText(QString::number(diodaPradDiody) + " mA");
}


void MainWindow::on_diodyZasilanie_editingFinished()
{
    diodaNapiecieZasilania = ui->diodyZasilanie->text().toFloat();
}


void MainWindow::on_diodaPomocButton_clicked()
{
    QMessageBox::about(this,"Pomoc","Brak pomocu");
}


void MainWindow::on_diodaObliczButton_clicked()
{
    if (diodaNapiecieDiody == 0 or diodaNapiecieZasilania == 0){
        QMessageBox::warning(this,"Błąd", "Musisz podać napięcie zasilania i wybrać diodę");
    } else {
        diodaRezystor dr;
        diodaRezystancja = dr.rezystancja(diodaNapiecieDiody, diodaNapiecieZasilania, diodaIleDiod, diodaPradDiody,diodaRezystancja);
        if (diodaNapiecieZasilania < diodaNapiecieDiody*diodaIleDiod){
            QMessageBox::warning(this, "Błąd","Zbyt niskie napięcie zasilania");
            ui->diodyRezystancjaLabel->setText(" ____");
        }else {
            ui->diodyRezystancjaLabel->setText(QString::number((int)diodaRezystancja) + " ohm");

        }

    }

}


void MainWindow::on_diodaCofnijButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_dzielnikCofnijButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_ileDiodBox_valueChanged(int arg1)
{
    diodaIleDiod = arg1;

    if (diodaIleDiod == 0){
        QMessageBox::warning(this, "Błąd", "Ilość diod musi być więszka od zaer");

    } else if (diodaIleDiod > 10) {
        QMessageBox::warning(this, "Błąd", "Maksymalnie 10 diod");
    }
}


void MainWindow::on_diodaZapiszButton_clicked()
{
    QFile file ("D:/telekomunikacja/Semestry/Moje/Semestr 4/Programowanie aplikacyjne/projekt/2/Przybotnik_elektronika/file.txt");

    if(file.open(QIODevice::Append | QIODevice::Text)){ // metoda open w otwiera plik w trybie tylko do odczytu z zamianą znaków \r\n ma \n
        QTextStream out(&file);

        out << "\nVin " + QString::number(diodaNapiecieZasilania) + " || " + "Dioda (" + ui->comboBox->currentText() + ") w ilości " + QString::number(diodaIleDiod) +
               " sztuk " + "\nPrzytakich parametrach dobrany rezystor powinien wynoscić około " + QString::number(diodaRezystancja) + " Ohm" + " \n";
        file.close();
    }
}
