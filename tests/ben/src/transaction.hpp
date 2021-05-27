#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <time.h>

enum TRANSACTION_TYPE { DEFAULT, STOCK_BUY, STOCK_SELL, ACCOUNT_DEPOSIT, ACCOUNT_WITHDRAW };
enum DAYS_OF_MONTH { JAN = 31, FEB = 28, MAR = 31, APR = 30, MAY = 31, JUN = 30,
            JUL = 31, AUG = 31, SEP = 30, OCT = 31, NOV = 30, DEC = 31 };

// enum MONTH { _JAN, _FEB, _MAR, _APR, _MAY, _JUN, __JUL, _AUG, _SEP, _OCT, _NOV, _DEC };
class Date {
public:
    // Date(int, int, int, int, string);
    Date();
    Date(int, int, int, int);

    // Get
    int GetYear();
    int GetMonth();
    int GetDay();
    int GetHour();
    string GetTimeStamp();

    // Methods
    void AddYear();  // Only adding one year is possible
    void AddMonth(); // Only adding one month is possible
    void AddDay();   // Only adding one day is possible
    void AddHour();  // Only adding one day is possible
    static void AddGameTime(Date*);
    DAYS_OF_MONTH GetMaxDate();

    friend ostream& operator<<(ostream& strm, Date& d);

private:
    int year;
    int month;
    int day;
    int hour;
    string time_stamp;
    // double time;
};

class Transaction {
public:
    // Constructors
    Transaction(TRANSACTION_TYPE type);
    Transaction(TRANSACTION_TYPE type, double amount);
    Transaction(TRANSACTION_TYPE type, double amount, Date date);

    // Get
    Date GetDate();
    double GetAmount();
    string GetTransactionType();

    // Set
    void SetDate(Date);

    // Methods
    static void AddTransaction(vector<Transaction>&, Transaction&);

    // In progress
    string GetMonth();

    friend ostream& operator<<(ostream& strm, Transaction& t);

private:
    Date date;
    TRANSACTION_TYPE type;
    double amount;
};

#endif
