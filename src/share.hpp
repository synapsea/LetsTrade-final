#pragma once

#include <memory>
#include "stock.hpp"
#include "transaction.hpp"

#ifndef SHARE_H
#define SHARE_H

class Share {
public:
    Share() = default;
    Share(Stock*, int);

    // Methods
    void IncreaseAmount(int);
    void DecreaseAmount(int);

    // Getter
    Stock GetStock();
    Stock* GetStockPtr();
    int GetPosition();
    double GetValue();
    double GetPercentage();
    double GetPrevPrice();
    double GetCurrentPrice();
    std::vector<Transaction> GetTransactionHistory();

    // Setter
    void RenewValue();
    void SetValue(double);

private:
    Stock* stock;
    int position = 0;
    std::vector<Transaction> transactionHistory;
    double value = 0.00;
};

#endif
