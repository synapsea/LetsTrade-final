#include "share.hpp"

Share::Share(Stock* s, int a)
    :stock(s),
    position(a){};

// Methods
void Share::IncreaseAmount(int a)
{
    double current = ( this->stock )->GetCurrentPrice();
    this->position += a;
    RenewValue();
};
void Share::DecreaseAmount(int a)
{
    double current = ( this->stock )->GetCurrentPrice();
    if(this->position > 0)
        this->position -= a;
    std::cout << "You have too less shares." << std::endl;
    RenewValue();
};

// Getter
Stock Share::GetStock()
    { return *(this->stock); };
Stock* Share::GetStockPtr()
    { return this->stock; };
int Share::GetPosition()
    { return this->position; };
double Share::GetValue() // Reset
{
    Share::RenewValue();
    return this->value;
};
double Share::GetPercentage() // Reset
{
    return( this->stock )->GetChangedPercentage();
};
double Share::GetPrevPrice() // Reset
{
    return( this->stock )->GetPrevPrice();
};
double Share::GetCurrentPrice() // Reset
{
    return( this->stock )->GetCurrentPrice();
};
std::vector<Transaction> Share::GetTransactionHistory()
    { return this->transactionHistory; };

// Settter
void Share::RenewValue(){
    double current = ( this->stock )->GetCurrentPrice();
    SetValue(current * this->position);
}
void Share::SetValue(double v)
    { this->value = v; };
