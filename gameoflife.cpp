#include "gameoflife.h"

gameoflife::gameoflife(int w, int h)
    : _height(h)
    , _width(w)
{}

std::vector<bool> gameoflife::naightourCheck(std::vector<bool> prevCell)
{
    //n1,n2,n3,
    //n4,XX,n5,
    //n6,n7,n8;

    int counterLebt = 0;
    int fullfield = _height * _width;
    unsigned int n1,n2,n3,n4,n5,n6,n7,n8;

    std::vector<bool> newCell;
    newCell = buildCell(newCell);

    for (int c= 0 ; c<(fullfield); c++)
    {
        unsigned int index = static_cast<unsigned int>(c);

        n1 = trueCheck(c - _width - 1, fullfield);
        n2 = trueCheck(c - _width    , fullfield);
        n3 = trueCheck(c - _width + 1, fullfield);
        n4 = trueCheck(c -          1, fullfield);
        n5 = trueCheck(c +          1, fullfield);
        n6 = trueCheck(c + _width - 1, fullfield);
        n7 = trueCheck(c + _width    , fullfield);
        n8 = trueCheck(c + _width + 1, fullfield);


                if(prevCell.at(n1)==true) {++counterLebt;}
                if(prevCell.at(n2)==true) {++counterLebt;}
                if(prevCell.at(n3)==true) {++counterLebt;}

                if(prevCell.at(n4)==true) {++counterLebt;}
                if(prevCell.at(n5)==true) {++counterLebt;}

                if(prevCell.at(n6)==true) {++counterLebt;}
                if(prevCell.at(n7)==true) {++counterLebt;}
                if(prevCell.at(n8)==true) {++counterLebt;}

                if(prevCell.at(index)==false)
                {
                    //Regel1
                    if(counterLebt == _ruleOne)
                    newCell.at(index)=true;
                }

                else
                {
                    //Regel4
                    if(counterLebt < _ruleFour)
                        newCell.at(index)=false;
                    //Regel2
                    if(counterLebt == _ruleTwo||_ruleTwo+1)
                        newCell.at(index)=true;
                    //Regel3
                    if(counterLebt > _ruleThree)
                        newCell.at(index)=false;
                }
              counterLebt = 0;
    }
    return newCell;
}

    unsigned int gameoflife::trueCheck(int checkNumber,int fullField)
    {
        int cell;

        if(checkNumber < 0)
        {
            cell = checkNumber + fullField;
        }
        else if(checkNumber > fullField-1)
        {
            cell = checkNumber - fullField;
        }
        else
        {
            cell = checkNumber;
        }

        return static_cast<unsigned int>(cell);
    }

    std::vector<bool> gameoflife::pushCells(std::vector<bool>&prevCell)
    {
        return naightourCheck(prevCell);
    }

    std::vector<bool> gameoflife::buildCell(std::vector<bool> cell)
    {
        int fullField = _height * _width;
        for(int index = 0; index < fullField; ++index)
        {
            cell.push_back(false);
        }
        return cell;
    }

    void gameoflife::setRules(int ruleOne, int ruleTwo, int ruleThree, int ruleFour)
    {
        _ruleOne    = ruleOne;
        _ruleTwo    = ruleTwo;
        _ruleThree  = ruleThree;
        _ruleFour   = ruleFour;
    }
