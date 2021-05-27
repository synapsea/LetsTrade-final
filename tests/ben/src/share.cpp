#include "share.hpp"

/* Share */

// Constructors
Share::Share(){};
Share::Share(Stock* stock, Player* shareHolder, double pp)
    :stock(stock),
    shareHolder(shareHolder),
    purchasePrice(pp){};
Share::Share(Stock* stock, Player* shareHolder, double pp, int numberOfShares)
    :stock(stock),
    shareHolder(shareHolder),
    purchasePrice(pp),
    numberOfShares(numberOfShares){};

// Methods

// ...

/* Certificate */

// Constructors
Certificate::Certificate(){};

// Methods
void Certificate::PrintCertificate(){
    string STRING = "Ben's Certificate";
    cout << "+-------------------------+" << endl;
    for (int i = 0; i < 15; i++){
        cout << "|";
        for (int j = 0; j < 25; j++){
            if(j == 3 && i == 3){
                for (int k = 0; k < STRING.size(); k++){
                    cout << STRING[k];
                    j++;
                }
                cout << ' ';
            }else
                cout << ' ';
        }
        cout << "|\n";
    }
    cout << "+-------------------------+" << endl;
};
