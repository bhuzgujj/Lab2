//
// Created by Jesus Urias on 4/23/25.
//

#ifndef CURRENCYABSTRACTCLASS_H
#define CURRENCYABSTRACTCLASS_H

class CurrencyAbstractClass {
public:
    CurrencyAbstractClass():dollarValue(0),centValue(0){};
    CurrencyAbstractClass(double value);
    CurrencyAbstractClass(CurrencyAbstractClass const &other);
    ~CurrencyAbstractClass();

private:
    int dollarValue;
    int centValue;
};

#endif //CURRENCYABSTRACTCLASS_H
