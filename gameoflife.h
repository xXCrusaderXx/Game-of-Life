#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>
#include "mainwindow.h"

class gameoflife
{
public:    
    gameoflife(int,int);

    std::vector<bool> pushCells(std::vector<bool>&prevCell);
    std::vector<bool> buildCell(std::vector<bool>cell);
    void setRules(int ruleOne, int ruleTwo, int ruleThree, int ruleFour);


private:
    std::vector<bool> naightourCheck(std::vector<bool>prevCell);
    unsigned int trueCheck(int,int);

    int _height;
    int _width;

    int _ruleOne = 3;
    int _ruleTwo = 2;
    int _ruleThree = 3;
    int _ruleFour = 1;
};

#endif // GAMEOFLIFE_H
