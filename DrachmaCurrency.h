//
// Created by jesus on 4/25/2025.
//

#ifndef DRACHMACURRENCY_H
#define DRACHMACURRENCY_H

#include "CurrencyAbstractClass.h"

class DrachmaCurrency : public CurrencyAbstractClass {
public:
    DrachmaCurrency();
    ~DrachmaCurrency();
private:
    CurrencyAbstractClass* currency;
    std::string coinName;
};

#endif //DRACHMACURRENCY_H
