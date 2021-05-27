// Followed the charyt in https://www.interactivebrokers.com/en/software/am3/am/funding/viewingtransactionhistory.htm
#include "transaction.hpp"

time_t NOW = time(0); // current system date/time
tm* GMT_TIME = gmtime(&NOW);

/* Date */

// Constructors
Date::Date(){ // This will give exact current time
    this->year = (1900 + (GMT_TIME->tm_year));
    this->month = (GMT_TIME->tm_mon);
    this->day = (GMT_TIME->tm_mday);
    this->hour = (9); // Always start from 9am
    this->time_stamp = ctime(&NOW);
};
Date::Date(int year, int month, int day, int hour) // This will be used to implement game's time system
    :year(year),
    month(month),
    day(day),
    hour(hour)
        { this->time_stamp = ctime(&NOW); };

// Get
int Date::GetYear()
    { return this->year; };
int Date::GetMonth()
    { return this->month; };
int Date::GetDay()
    { return this->day; };
int Date::GetHour()
    { return this->hour; };
string Date::GetTimeStamp()
    { return this->time_stamp; };

// Methods
void Date::AddYear()
    { this->year+=1; };
void Date::AddMonth(){
    this->month += 1;
    if(this->month >= 11){
        this->AddYear();
        this->month = 0;
    }
};
void Date::AddDay(){
    DAYS_OF_MONTH dom = this->GetMaxDate();
    this->day += 1;
    if (this->day >= dom){
        this->AddMonth();
        this->day = 0;
    }
};
void Date::AddHour(){ // 9am to 3pm
    this->hour += 1;
    if(this->hour >= 15){
        this->AddDay();
        this->hour = 9;
    }
};
void Date::AddGameTime(Date* gameDate){ // static
    gameDate->AddHour();
};
DAYS_OF_MONTH Date::GetMaxDate(){
    DAYS_OF_MONTH mth;
    switch(this->month){
        case 0: mth=JAN; break;
        case 1: mth=FEB; break;
        case 2: mth=MAR; break;
        case 3: mth=APR; break;
        case 4: mth=MAY; break;
        case 5: mth=JUN; break;
        case 6: mth=JUL; break;
        case 7: mth=AUG; break;
        case 8: mth=SEP; break;
        case 9: mth=OCT; break;
        case 10: mth=NOV; break;
        case 11: mth=DEC; break;
    }
    return mth;
};

/* Transaction */

// Constructors
Transaction::Transaction(TRANSACTION_TYPE t)
    :type(t)
    {
        Date date = Date();
        this->date = date;
    };
Transaction::Transaction(TRANSACTION_TYPE t, double a) // add hour later
    :type(t),
    amount(a)
    {
        Date date = Date();
        this->date = date;
    };
Transaction::Transaction(TRANSACTION_TYPE t, double a, Date d) // Create Transaction with given Date
    :type(t),
    amount(a),
    date(d){};

// Get
Date Transaction::GetDate()
    { return this->date; };
double Transaction::GetAmount()
    { return this->amount; };
string Transaction::GetTransactionType(){
    TRANSACTION_TYPE t;
    t = this->type;
    switch (t) {
        case STOCK_BUY: return "Buy Stock"; break;
        case STOCK_SELL: return "Sell Stock"; break;
        case ACCOUNT_DEPOSIT: return "Bank Account Deposit"; break;
        case ACCOUNT_WITHDRAW: return "Bank Account Withraw"; break;
        default:
            return "TRANSACTIONTYPE::Error: Wrong input transaction type";
            break;
    }
};


// Methods
void Transaction::AddTransaction(vector<Transaction>&v, Transaction& t){
    v.push_back(t);
};

// In progress
string GetMonth()
    { return "MONTH"; };

// __str__
ostream& operator<<(ostream& strm, Date& d) {
    return strm << "\n\nYear:\t\t\t" << d.GetYear() << "\n\nMonth:\t\t\t" << d.GetMonth() << "\n\nDay:\t\t\t" << d.GetDay() << "\n\nHour:\t\t\t" << d.GetHour() << "\n\n";
};
ostream& operator<<(ostream& strm, Transaction& t) {
    Date d = t.date;
    try{
        if(!t.type)
            throw "\n\nTransaction::Error:No specified transaction type\n\n";
        else if(!t.amount)
            throw "\n\nTransaction::Error:Zero amount of the transaction\n\n";
        else
            return strm << "\n\nTransaction Type:\t" << t.GetTransactionType() << "\n\nAmount:\t\t\t$" << t.amount << d;
    }catch(const char* err){
        return strm << err;
    }
};
