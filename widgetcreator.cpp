#include "mainwindow.h"


void MainWindow::createWidgets()
{
int c = 0;
for (int y = 0 ; y < fieldSizeY; y++)
{
    for (int x = 0;x < fieldSizeX;x++)
    {
        button[c] = new QRadioButton(this);
        int coordX = x*buttonSizeX;
        int coordY = y*buttonSizeY;
        button[c]->setGeometry(coordX,coordY,buttonSizeX,buttonSizeY);
        button[c]->setChecked(false);
        button[c]->setAutoExclusive(false);
        ++c;
    }
}

//startButton
startButton = new QPushButton(this);
startButton->setGeometry(0,buttonSizeY*fieldSizeY+10,50,50);
startButton->setText("GO!");

updateButton = new QPushButton(this);
updateButton->setGeometry(0,buttonSizeY*fieldSizeY+50+25,50,50);
updateButton->setText("Update");

resetButton = new QPushButton(this);
resetButton->setGeometry(75,buttonSizeY*fieldSizeY+50+25,50,50);
resetButton->setText("Reset");

//RefreshValue
refreshValueLabel = new QLabel(this);
refreshValueLabel->setGeometry(100,buttonSizeY*fieldSizeY+30,75,25);
refreshValueLabel->setText("resfresh Time:");

refreshValue = new QComboBox(this);
refreshValue->setGeometry(175,buttonSizeY*fieldSizeY+30,100,25);
refreshValue->addItem("250");
refreshValue->addItem("500");
refreshValue->addItem("1000");

//infoLabel1
infoLabel1 = new QLabel(this);
infoLabel1->setGeometry(300,buttonSizeY*fieldSizeY+5,150,25);
infoLabel1->setText("if (Zelle == False)");

//infoLabel2
infoLabel2 = new QLabel(this);
infoLabel2->setGeometry(500,buttonSizeY*fieldSizeY+5,150,25);
infoLabel2->setText("if (Zell == True)");

//infoLabel3 LifeCycles
infoLabel3 = new QLabel(this);
infoLabel3->setGeometry(300,buttonSizeY*fieldSizeY+50+25,150,25);
infoLabel3->setText("none");

//ruleOneValueBox
ruleOneValueBoxLable = new QLabel(this);
ruleOneValueBoxLable->setGeometry(300,buttonSizeY*fieldSizeY+30,75,25);
ruleOneValueBoxLable->setText("Regel 1:");

ruleOneValueBox = new QComboBox(this);
ruleOneValueBox->setGeometry(375,buttonSizeY*fieldSizeY+30,100,25);
ruleOneValueBox->addItem("2");
ruleOneValueBox->addItem("3");
ruleOneValueBox->addItem("4");
ruleOneValueBox->setCurrentIndex(1);

//ruleTwoValueBox
ruleTwoValueBoxLable = new QLabel(this);
ruleTwoValueBoxLable->setGeometry(500,buttonSizeY*fieldSizeY+30,75,25);
ruleTwoValueBoxLable->setText("Regel 2:");

ruleTwoValueBox = new QComboBox(this);
ruleTwoValueBox->setGeometry(575,buttonSizeY*fieldSizeY+30,100,25);
ruleTwoValueBox->addItem("1 o. 2");
ruleTwoValueBox->addItem("2 o. 3");
ruleTwoValueBox->addItem("3 o. 4");
ruleTwoValueBox->setCurrentIndex(1);

//ruleThreeValueBox
ruleTwoValueBoxLable = new QLabel(this);
ruleTwoValueBoxLable->setGeometry(500,buttonSizeY*fieldSizeY+70,75,25);
ruleTwoValueBoxLable->setText("Regel 3:");

ruleThreeValueBox = new QComboBox(this);
ruleThreeValueBox->setGeometry(575,buttonSizeY*fieldSizeY+70,100,25);
ruleThreeValueBox->addItem("2");
ruleThreeValueBox->addItem("3");
ruleThreeValueBox->addItem("4");
ruleThreeValueBox->setCurrentIndex(1);

//ruleFourValueBox
ruleFourValueBoxLable = new QLabel(this);
ruleFourValueBoxLable->setGeometry(500,buttonSizeY*fieldSizeY+110,75,25);
ruleFourValueBoxLable->setText("Regel 4:");

ruleFourValueBox = new QComboBox(this);
ruleFourValueBox->setGeometry(575,buttonSizeY*fieldSizeY+110,100,25);
ruleFourValueBox->addItem("1");
ruleFourValueBox->addItem("2");
ruleFourValueBox->addItem("3");
ruleFourValueBox->setCurrentIndex(0);
}
