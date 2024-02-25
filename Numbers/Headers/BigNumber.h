#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using std::size_t;

// было бы прикольно переписать для произвольной системы счисления.
// цифры числа храним в векторе, первая цифра - последний элемен вектора.
// ну и как бы по скорости тоже надо смотреть,
// пока что реализация достаточно жадная(тупая)
class BigNumber{
public:

    BigNumber();
    BigNumber(int n);
    BigNumber(const BigNumber &n);
    BigNumber(BigNumber &&n);

    BigNumber& operator =(const BigNumber &n);
    //BigNumber& operator =(BigNumber &&n);

    BigNumber operator*(int n);

    friend BigNumber operator *(const BigNumber &n1, const BigNumber &n2);
    friend BigNumber operator +(const BigNumber &n1, const BigNumber &n2);
    //friend ostream& operator <<(std::ostream &os, const BigNumber &n);

    void printNumber(void) const;
    size_t len(void) const;        // количество цифр в числе
    
private:
    void parseFromInt(int n);
    void setDefaultValue();
    void setNumberLenght(int l);

    // это все на случай, если я захочу поменять логику хранения и добавления цифр
    int getDigit(int i) const;
    void addDigit(int digit);

private:
    std::vector<int> digits;
};