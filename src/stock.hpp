#pragma once
#include <time.h>
#include <math.h>
#include <ctime>
#include <vector>
#include "transaction.hpp" // has public header

#ifndef STOCK_H
#define STOCK_H

class Company {
public:
    Company(string);
    Company(string, string);
    string companyName;
    string companyType;
    double companyPrice;
    double companyValue;

    // ToString
    friend ostream& operator<<(ostream& strm, const Company& c);
};

class Stock{
public:
    Stock();
    Stock(string, Company*);
    Stock(string, double, Company*);

    // Get
    double GetCurrentPrice();
    double GetPrevPrice();
    double GetChangedPercentage();
    string GetSymbol();
    Company GetStockIssuer();

    // Set
    void SetCurrentPrice(double);
    void SetPrevPrice(double);
    void SetSymbol(string);
    void SetStockIssuer(Company*); // Just passing pointer

    // Methods
    void UpdateChangedPercentage();
    void UpdateStockPrice();
    void UpdateStockPrice(double newStockPrice);
    int GetRandomNumber(int);


    // In Progress
    vector<Transaction> GetTransactionHistory();
    double GetRandomStockPrice(int = 4);
    //void AddTransactionHistory();
    //void PrintTransactionHistory();

    // Tests

    // Dectructor
    ~Stock();

protected:
    double stockCurrentPrice;
    double stockPrevPrice;
    double stockUniqueConstant = 0.01418953;
    double stockChangedPercentage;
    string stockSymbol;
    Company* stockIssuer; // Stock Issuer
    vector<Transaction> transactionHistory; // Needa fix

    // ToString
    friend ostream& operator<<(ostream& strm, const Stock& s);
};

#endif
