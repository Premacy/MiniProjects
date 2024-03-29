#include "BigNumber.h"

BigNumber::BigNumber(){
    setDefaultValue();
}

BigNumber::BigNumber(int n){
    parseFromInt(n);
}

BigNumber::BigNumber(const BigNumber &n){
    digits = n.digits;
}

BigNumber::BigNumber(BigNumber &&n){
    digits = std::move(digits);
    n.setDefaultValue();
}

BigNumber& BigNumber::operator=(const BigNumber &n){
    digits.clear();
    digits = n.digits;

    return (*this);
}

void BigNumber::setNumberLenght(int l){
    digits.reserve(l);
}

void BigNumber::setDefaultValue(){
    digits.clear();
    digits.push_back(0);
}

void BigNumber::parseFromInt(int n){
    int digit(0);
    int nth = static_cast<int>(log10(n)) + 1;

    digits.reserve(nth);

    while ( n > 0 ){
        digit = n % 10;
        n /= 10;
        
        digits.push_back(digit);
    }
}

BigNumber BigNumber::operator * (int n){
    BigNumber n_;

    int rem(0), digit(0);
    int res(0);

    const size_t sizeN = len();

    for (size_t i = 0; i < sizeN; i++){
        res = digits[i] * n + rem;    // умножили

        digit = res % 10;
        rem = res / 10;

        n_.digits.push_back(digit);
    }

    if (rem) n_.digits.push_back(digit);

    return n_;
}

BigNumber operator *(const BigNumber &n1, const BigNumber &n2){
    int rd(10), rem(0);
    int pw(1);
    double digit(0);

    const size_t sizeN1 = n1.len();
    const size_t sizeN2 = n2.len();

    BigNumber result;

    for (size_t i = 0; i < sizeN1; ++i){
        BigNumber n;

        digit = n2.getDigit(i) * pw;
        result = result + ( n1 * digit );

        pw *= rd;
    }
    
    return result;
}

BigNumber operator +(const BigNumber &n1, const BigNumber &n2){
    BigNumber result;
    
    int rem(0), sum(0), d(0);
    int newDigit;

    //const numSize1 = n1.len();

    const size_t maxLen = std::max( n1.len(), n2.len() );

    int digit1, digit2;

    for (size_t i = 0; i < maxLen; i++){
        if   ( i >= n1.len() ) digit1 = 0;
        else                   digit1 = n1.getDigit(i);

        if   ( i >= n2.len() ) digit2 = 0;
        else                   digit2 = n2.getDigit(i);

        sum = digit1 + digit2 + d;
        newDigit = sum % 10;
        d = sum / 10;  

        result.addDigit(newDigit);
    }

    if (d > 0) result.addDigit(d);

    return result;
}

void BigNumber::printNumber() const{
    for(auto itr = digits.rbegin(); itr != digits.rend(); ++itr){
        std::cout << (*itr);
    }
    std::cout << "\n";
}

size_t BigNumber::len(void) const{
    return digits.size();
}

int BigNumber::getDigit(int i) const{
    // добавить обработку?!
    return digits[i];
}

void BigNumber::addDigit(int digit){
    digits.push_back(digit);
}