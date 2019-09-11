#include "mainwindow.h"
#include "gameoflife.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QTimer"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
  , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    this->setWindowTitle("Game of Life");
    this->setFixedSize(windowSizeX,windowSizeY);

    QMessageBox msgBox;
    msgBox.setText("Bitte 5 aneinander liegende Punkte setzen! ");
    msgBox.exec();

    gameoflife myLife(fieldSizeX,fieldSizeY);
    cells = myLife.buildCell(cells);

    createWidgets();

    QObject::connect(startButton,SIGNAL(clicked()),this,SLOT(startButton_clicked()));
    QObject::connect(resetButton,SIGNAL(clicked()),this,SLOT(resetGame()));
    QObject::connect(updateButton,SIGNAL(clicked()),this,SLOT(changeData()));
    QObject::connect(refresh,SIGNAL(timeout()),this,SLOT(getCells()));

    MainWindow::show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startButton_clicked()
{
    unsigned int startCounter = 0;

    if(!refresh->isActive())
    {
        for (int index = 0;index < fieldSizeX*fieldSizeY; ++index)
        {
            if(button[index]->isChecked())
            {
                ++startCounter;
            }
        }

        if(startCounter >=5)
        {
            gameoflife myLife(fieldSizeX,fieldSizeY);
            changeData();

            int fullField = fieldSizeY * fieldSizeX;
            for(int index = 0; index < fullField; ++index)
            {
                if(button[index]->isChecked()==true)
                {
                cells.at(static_cast<unsigned>(index))=true;
                }
                else
                {
                cells.at(static_cast<unsigned>(index))=false;
                }
            }
    }
    refresh->start(500);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("nicht genug Felder gesetzt!");
        msgBox.exec();
    }
}

void MainWindow::getCells()
{
    int fullField = fieldSizeY * fieldSizeX;
    for(int index = 0; index < fullField; ++index)
    {
        cells.at(static_cast<unsigned>(index)) = button[index]->isChecked();
    }
    gameoflife myLife(fieldSizeX,fieldSizeY);
    cells = myLife.pushCells(cells);
    for (int index = 0;index < fullField;++index)
    {
        button[index]->setChecked(cells.at(static_cast<unsigned>(index)));
    }

    lifeCycleCount++;
    QString tmp;
    QString count = tmp.setNum(lifeCycleCount);
    infoLabel3->setText(count);
}

void MainWindow::resetGame()
{
    if(refresh->isActive() == true)
    {
        refresh->stop();

            for (int c = 0;c < fieldSizeX*fieldSizeY; c++)
            {
               button[c]->setChecked(false);
            }

        QMessageBox msgBox;
        msgBox.setText("Das Spiel wurde zurückgesetzt!");
        msgBox.exec();
    }
}

void MainWindow::changeData()
{
    //refresh->stop();

    int tValue = refreshValue->itemText(refreshValue->currentIndex()).toInt();
    ruleOneValue = ruleOneValueBox->itemText(ruleOneValueBox->currentIndex()).toInt();

    int indexRuleTwo = ruleTwoValueBox->currentIndex();
    if(indexRuleTwo == 0){ruleTwoValue = 1;}
    if(indexRuleTwo == 1){ruleTwoValue = 2;}
    if(indexRuleTwo == 2){ruleTwoValue = 3;}

    ruleThreeValue = ruleThreeValueBox->itemText(ruleThreeValueBox->currentIndex()).toInt();
    ruleFourValue = ruleFourValueBox->itemText(ruleFourValueBox->currentIndex()).toInt();

    gameoflife myLife(fieldSizeX,fieldSizeY);
    myLife.setRules(ruleOneValue, ruleTwoValue, ruleThreeValue, ruleFourValue);

    if(refresh->isActive()==true)
    refresh->start(tValue);

    statusBar()->showMessage(tr("Daten geändert"), 5000);
}

