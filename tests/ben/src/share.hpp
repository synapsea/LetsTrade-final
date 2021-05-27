#ifndef SHARE_H
#define SHARE_H
#include "stock.hpp"
#include "player.hpp"

class Share {
public:
    Share();
    Share(Stock*, Player*, double);
    Share(Stock*, Player*, double, int);
private:
    Stock* stock;           // Required
    Player* shareHolder;    // Required
    double purchasePrice;   // Required
    int numberOfShares = 0; // Any better name?
};

class Certificate {
public:
    Certificate();
    void PrintCertificate();
private:
    Company* company;
    Player* owner;
    Stock* stock;
    Date* date;
};

#endif
