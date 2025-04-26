//
// Created by Jesus Urias on 4/23/25.
//

#ifndef CURRENCYABSTRACTCLASS_H
#define CURRENCYABSTRACTCLASS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

class Currency {
public:
    Currency(): wholeValue(0), fractionalValue(0) {};

    Currency(const double value) {
        if (value < 0) {
            throw std::string("Invalid Currency value");
        }
        wholeValue = static_cast<int>(value);
        fractionalValue = static_cast<int>(round((value - wholeValue)*100)) ;
    };

    Currency(const Currency  &other): wholeValue(other.wholeValue),
                                                               fractionalValue(other.fractionalValue) {};

    virtual ~Currency() {};
    unsigned int getWholeValue() const { return wholeValue; };

    void setWholeValue(unsigned int newDollarValue) {
        wholeValue = newDollarValue;
    };
    unsigned int getFractionalValue() const { return fractionalValue; };

    void setFractionalValue(unsigned int newCentValue) {
        fractionalValue = newCentValue;
    };

    virtual void addCurrency(Currency *currency);

    virtual void subtractCurrency(Currency *currency);

    virtual bool isEqual(const Currency &other) const {
        return wholeValue == other.wholeValue && fractionalValue == other.fractionalValue;
    }

    virtual bool isGreater(const Currency &other) const {
        if (wholeValue == other.wholeValue && fractionalValue > other.fractionalValue) return true;
        return wholeValue > other.wholeValue;
    }

    virtual std::string toString() const {
        std::stringstream ss;
        ss << wholeValue << "." << std::setw(2) << std::setfill('0') << fractionalValue;
        return ss.str();
    };

    void print() const {
        std::cout << toString();
    };

private:
    unsigned int wholeValue;
    unsigned int fractionalValue;
};

void Currency::addCurrency(Currency *currency) {
    fractionalValue += currency->fractionalValue;
    if (fractionalValue > 100) {
        fractionalValue -= 100;
        ++wholeValue;
    }
    wholeValue += currency->wholeValue;
};

void Currency::subtractCurrency(Currency *currency) {
    if (!isGreater(*currency) && !isEqual(*currency)) {
        throw std::string("Invalid Subtractions: Cannot be Negative Currency");
    }
    if (fractionalValue - currency->fractionalValue < 0) {
        fractionalValue += 100;
        --wholeValue;
    }
    wholeValue -= currency->wholeValue;
    fractionalValue -= currency->fractionalValue;
};

#endif //CURRENCYABSTRACTCLASS_H
