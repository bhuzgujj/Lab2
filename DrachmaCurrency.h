//
// Created by jesus on 4/25/2025.
//

#ifndef DRACHMACURRENCY_H
#define DRACHMACURRENCY_H

#include "Currency.h"

class DrachmaCurrency : public Currency {
public:
    DrachmaCurrency(){};
    DrachmaCurrency(double value):Currency(value){};

    std::string toString() const override {
        return Currency::toString() + " " + coinName;
    };

    void addCurrency(Currency *currency) override;

    void subtractCurrency(Currency *currency) override;

private:;
    std::string coinName = "Drachma";
};

void DrachmaCurrency::addCurrency(Currency *currency) {
    if (DrachmaCurrency *newCurrency = dynamic_cast<DrachmaCurrency *>(currency)) {
        Currency::addCurrency(newCurrency);
    } else {
        throw std::string("Invalid Addition of Currency Type");
    }
}

void DrachmaCurrency::subtractCurrency(Currency *currency) {
    if (DrachmaCurrency *newCurrency = dynamic_cast<DrachmaCurrency *>(currency)) {
        Currency::subtractCurrency(newCurrency);
    } else {
        throw std::string("Invalid Subtraction of Currency Type");
    }
}

#endif //DRACHMACURRENCY_H
