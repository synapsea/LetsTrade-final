#pragma once

#include <memory>
#include "share.hpp"

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

class Portfolio {
public:
    // Constructors
    Portfolio();
    Portfolio(const vector<std::shared_ptr<Stock>>&);

    // Getter
    std::vector<Share> GetShares();
    Share* GetShareByIndex(int);
    Share* GetShareByStock(Stock*);

    // Methods
    void InitializeEmptyShares(const vector<std::shared_ptr<Stock>>&);
    void BuyShare(Stock*, int);
    void SellShare(Stock*, int);
private:
    std::vector<Share> shares;
    
};

#endif
