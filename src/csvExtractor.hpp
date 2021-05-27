#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "stock.hpp"
#include <fstream>
#include <iostream>
#include <vector>

class CSVExtractor{
public:
    CSVExtractor(const string);
    vector<vector<string>> GetResult();
    void ExtractData(ifstream&);
    void ExtractOneLine(ifstream&, string&, string&, string&);

private:
    vector<vector<string>> result;
};

class RandomNumberGenerator{
public:
    RandomNumberGenerator(int, int, int);
    vector<int> GetNumbers();
    int RandomWithRange(int, int);

private:
    vector<int> numbers;
};

#endif
