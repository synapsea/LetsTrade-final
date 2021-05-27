#include "portfolio.hpp"
#include "banking.hpp"

/* Portfolio */
Portfolio::Portfolio(){};


Portfolio::Portfolio(const vector<std::shared_ptr<Stock>>& stocks){
    InitializeEmptyShares(stocks);
};
void Portfolio::BuyShare(Stock* stock, int a){
    Share* s = GetShareByStock(stock);
    // BankBalance
    // If user has less than zero amount of balance | cannot afford it, reject it
    // If user is buying less than equal to zero amount, then reject it.
    s->IncreaseAmount(a);
};
void Portfolio::SellShare(Stock* stock, int a){
    Share* s = GetShareByStock(stock);
    s->DecreaseAmount(a);
    // If the position of share is zero, then reject.

};

// Methods
void Portfolio::InitializeEmptyShares(const vector<std::shared_ptr<Stock>>& stocks){
    try{
        for(const auto& s : stocks){
            Stock* stock = s.get();
            this->shares.push_back({ stock,0 });
        }
    } catch(const char* errMessage){
        std::cout << errMessage << std::endl;
        exit(1);
    }
};

// Getter
std::vector<Share> Portfolio::GetShares()
    { return this->shares; };
Share* Portfolio::GetShareByIndex(int index)
{
    Share* s;
    try {
        s = &( (this->shares).at(index) );
        throw "Out of index error";
    } catch(const char* errMessage){
        cout << "Portfolio::Error::" << errMessage << endl;
    }
    return s;
};
Share* Portfolio::GetShareByStock(Stock* stock)
{
    Share* share; //temp
    try {
        for(auto& s : this->shares){
            // Decide which to use. vector.find() or just loop
            if( stock == s.GetStockPtr() ){
                share = &s;
                break;
            }
        }
    } catch(const char* errMessage){
        cout << "Portfolio::Error::" << errMessage << endl;
    }
    return share;
};
