#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QRadioButton"
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include "QTimer"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QRadioButton *button[2500];

private:
    Ui::MainWindow *ui;

    int lifeCycleCount = 0;

    int windowSizeX = 750;
    int windowSizeY = 900;

    int C = 50;
    int fieldSizeY = 50;
    int fieldSizeX = 50;

    std::vector<bool>cells;

    int buttonSizeX = 15;
    int buttonSizeY = 15;

    int ruleOneValue;
    int ruleTwoValue;
    int ruleThreeValue;
    int ruleFourValue;

    QPushButton *startButton, * updateButton, *resetButton;
    QComboBox *refreshValue, *ruleOneValueBox, *ruleTwoValueBox, *ruleThreeValueBox, *ruleFourValueBox;
    QLabel *refreshValueLabel, *ruleOneValueBoxLable, *ruleTwoValueBoxLable, *ruleThreeValueBoxLable, *ruleFourValueBoxLable, *infoLabel1, *infoLabel2, *infoLabel3;

    void createWidgets();

    QTimer *refresh = new QTimer(this);

private slots:
    void startButton_clicked();
    void getCells();
    void changeData();
    void resetGame();

};

#endif // MAINWINDOW_H
