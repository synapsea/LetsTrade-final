/* Include */
#include "stock.hpp"

//time_t NOW = time(0); // current system date/time
double INITIAL_STOCK_PRICE = -10000;

/* Company */
Company::Company(string n) // Test
    :companyName(n){};
Company::Company(string n, string t)
    :companyName(n),
    companyType(t),
    companyPrice(0.00),
    companyValue(0.00){};

/* Stock */
Stock::Stock(){};
Stock::Stock(string s, Company* c)
    :stockSymbol(s),
    stockPrevPrice(INITIAL_STOCK_PRICE),
    stockIssuer(c){
        this->stockUniqueConstant = (this->GetRandomNumber(4) + 1) * 0.00418953;
        //cout << this->stockUniqueConstant << endl;
    };
Stock::Stock(string s, double p, Company* c)
    :stockSymbol(s),
    stockCurrentPrice(p),
    stockPrevPrice(INITIAL_STOCK_PRICE),
    stockIssuer(c){
        this->stockUniqueConstant = (this->GetRandomNumber(4) + 1) * 0.0418953;
        //cout << this->stockUniqueConstant << endl;
    };

// Get
double Stock::GetCurrentPrice()
    { return this->stockCurrentPrice; };
double Stock::GetPrevPrice()
    { return this->stockPrevPrice; };
double Stock::GetChangedPercentage()
    { return this->stockChangedPercentage; };
string Stock::GetSymbol()
    { return this->stockSymbol; };
Company Stock::GetStockIssuer()
    { return *(this->stockIssuer); }; // Return Object(Not pointer)

// Set
void Stock::SetCurrentPrice(double cp)
    { this->stockCurrentPrice = cp; };
void Stock::SetPrevPrice(double pp)
    { this->stockPrevPrice = pp; };
void Stock::SetSymbol(string s)
    { this->stockSymbol = s; };
void Stock::SetStockIssuer(Company* c)
    { this->stockIssuer =  c; };

// Methods
void Stock::UpdateChangedPercentage(){
    this->stockChangedPercentage = ((this->stockCurrentPrice  - this->stockPrevPrice) / this->stockPrevPrice) * 100;
};
void Stock::UpdateStockPrice(){
    double newStockPrice;
    // codes here
    newStockPrice = GetRandomStockPrice();
    this->stockPrevPrice = this->stockCurrentPrice;
    this->stockCurrentPrice = newStockPrice;
    this->UpdateChangedPercentage();
};
void Stock::UpdateStockPrice(double newStockPrice){
    this->stockPrevPrice = this->stockCurrentPrice;
    this->stockCurrentPrice = newStockPrice;
    this->UpdateChangedPercentage();
};
int Stock::GetRandomNumber(int num){ return (rand() % num); };

// In Progress
vector<Transaction> Stock::GetTransactionHistory()
    { return this->transactionHistory; };
double Stock::GetRandomStockPrice(int i){
    int r = GetRandomNumber(i);
    double percentage  = (r * 0.0125 * 0.125) + this->stockUniqueConstant;
    double result;

    // More logic here
    if(rand()%2 == 1 && (this->stockCurrentPrice-this->stockPrevPrice) > 10)
        // Minus
        percentage = percentage * (-1);

    result = this->stockCurrentPrice + (this->stockCurrentPrice * percentage);
    return result;
};

// Tests

// Destructor
Stock::~Stock(){
    delete this->stockIssuer;
    this->stockIssuer = NULL;
};

// String Representation of the object
ostream& operator<<(ostream& strm, const Stock& s) {
    if(s.stockIssuer)
        return strm << "\n\n" << "Stock Symbol: " << s.stockSymbol << "\n\nCurrent Price: $" << s.stockCurrentPrice << "\n\nOwned Company:\n\n" << *(s.stockIssuer);
    return strm << "\n\n" << "Stock Symbol: " << s.stockSymbol << "\n\nCurrent Price: $" << s.stockCurrentPrice << "\n\nOwned Company:\n\n" << "NONE";
};

ostream& operator<<(ostream& strm, const Company& c) {
    return strm << "\tName: " << c.companyName << "\n\n\tType: " << c.companyType << "\n\n";
};
