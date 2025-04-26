//
// Created by jesus on 4/25/2025.
//

#ifndef PESOCURRENCY_H
#define PESOCURRENCY_H

#include "Currency.h"

class PesoCurrency : public Currency {
public:
    PesoCurrency(){};
    PesoCurrency(double value):Currency(value){};
    std::string toString() const override {
        return Currency::toString() + " " + coinName;
    };
    void addCurrency(Currency *currency) override;
    void subtractCurrency(Currency *currency) override;
private:;
    std::string coinName = "Peso";
};

void PesoCurrency::addCurrency(Currency *currency) {
    if (PesoCurrency *newCurrency = dynamic_cast<PesoCurrency *>(currency)) {
        Currency::addCurrency(newCurrency);
    } else {
        throw std::string("Invalid Addition");
    }
}

void PesoCurrency::subtractCurrency(Currency *currency) {
    if (PesoCurrency *newCurrency = dynamic_cast<PesoCurrency *>(currency)) {
        Currency::subtractCurrency(newCurrency);
    } else {
        throw std::string("Invalid Subtraction");
    }
}
#endif //PESOCURRENCY_H
