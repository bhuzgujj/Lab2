//
// Created by Jesus Urias on 4/23/25.
//

#ifndef CURRENCYABSTRACTCLASS_H
#define CURRENCYABSTRACTCLASS_H

#include <iostream>
#include <string>

class CurrencyAbstractClass {
public:
    CurrencyAbstractClass():wholeValue(0),fractionalValue(0){};
    CurrencyAbstractClass(const double value) {
        if(value<0) {
            throw std::string("Invalid Currency value");
        }
        wholeValue = static_cast<int>(value);
        fractionalValue = static_cast<int>(value - wholeValue)*100;
    };
    CurrencyAbstractClass(CurrencyAbstractClass const &other):wholeValue(other.wholeValue), fractionalValue(other.fractionalValue){};
    ~CurrencyAbstractClass();
    unsigned int getWholeValue() const{return wholeValue;};
    void setWholeValue(unsigned int newDollarValue) {
        wholeValue = newDollarValue;
    };
    unsigned int getFractionalValue() const{return fractionalValue;};
    void setFractionalValue(unsigned int newCentValue) {
        fractionalValue = newCentValue;
    };
    void addCurrency(CurrencyAbstractClass *currency);
    void subtractCurrency(CurrencyAbstractClass *currency);
    bool isEqual(const CurrencyAbstractClass &other) const {
        return wholeValue == other.wholeValue && fractionalValue == other.fractionalValue;
    }
    bool isGreater(const CurrencyAbstractClass &other) const {
        if(wholeValue == other.getWholeValue() && fractionalValue > other.getFractionalValue()) return true;
        return wholeValue > other.getWholeValue();
    }
    virtual std::string toString() const =0;
    void print() const {
        std::cout << toString() << std::endl;
    };

private:
    unsigned int wholeValue;
    unsigned int fractionalValue;
};

inline void CurrencyAbstractClass::addCurrency(CurrencyAbstractClass *currency) {
    fractionalValue += currency->getFractionalValue();
    if(fractionalValue > 100) {
        fractionalValue -= 100;
        ++wholeValue;
    }
    wholeValue += currency->getWholeValue();
};

inline void CurrencyAbstractClass::subtractCurrency(CurrencyAbstractClass *currency) {
    if (!isGreater(*currency) && !isEqual(*currency)) {
        throw std::string("Invalid subtraction");
    }
    if(fractionalValue - currency->getFractionalValue() < 0 ) {
       fractionalValue += 100;
        --wholeValue;
    }
    wholeValue -= currency->getWholeValue();
    fractionalValue -= currency->getFractionalValue();
};

#endif //CURRENCYABSTRACTCLASS_H
