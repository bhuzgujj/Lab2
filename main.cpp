#include "DrachmaCurrency.h"
#include "PesoCurrency.h"

using namespace std;

const int ARRAY_SIZE = 2;

int main() {
    Currency *currencies[2];
    Currency *currency;
    string currencyName;
    char operation, currencyType;
    double value;
    int index = -1;
    currencies[0] = new PesoCurrency();
    currencies[1] = new DrachmaCurrency();

    currencies[0]->print();
    cout << " ";
    currencies[1]->print();
    cout << endl;

    cin >> operation;
    while(operation != 'q') {
        try {
            cin >> currencyType >> value >> currencyName;
            if (currencyName == "peso") {
                currency = new PesoCurrency(value);
            } else if (currencyName == "drachma") {
                currency = new DrachmaCurrency(value);
            } else {
                currency = nullptr;
                cerr << "Invalid Currency Name" << endl;
            }
            if(currency != nullptr) {
                switch (currencyType) {
                    case 'p':
                        index = 0;
                        break;
                    case 'd':
                        index = 1;
                        break;
                    default:
                        index = -1;
                        cerr << "Invalid Currency Type" << endl;
                }
                if(index > -1) {
                    switch (operation) {
                        case 'a':
                            currencies[index]->addCurrency(currency);
                            break;
                        case 's':
                            currencies[index]->subtractCurrency(currency);
                            break;
                        default:
                            cerr << "Invalid Operation" << endl;
                    }
                }
            }

        } catch (std::string &e)  {
            cerr << e << std::endl;
        }

        currencies[0]->print();
        cout << " ";
        currencies[1]->print();
        cout << endl;
        cin >> operation;
    }
    delete currencies[0];
    delete currencies[1];
    return 0;
}
