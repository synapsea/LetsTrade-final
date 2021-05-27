#include "csvExtractor.hpp"

/* CSVExtractor */

// Constructor
CSVExtractor::CSVExtractor(string filePath){
    ifstream ip(filePath);
    this->ExtractData(ip);
    ip.close();
};

// Methods
vector<vector<string>> CSVExtractor::GetResult(){ return this->result; };

void CSVExtractor::ExtractData(ifstream& ip){
    vector<vector<string>> result;
    vector<string> v;
    string symbol, name, type;

    if(!ip.is_open()) cout << "ERROR" << endl;
    else
    {
        while(ip.good()){
            this->ExtractOneLine(ip, symbol, name, type);
            v.push_back(symbol); v.push_back(name); v.push_back(type);
            result.push_back(v);
            v.clear();
        }
    }
    this->result = result;
};

void CSVExtractor::ExtractOneLine(ifstream& ip, string& s, string& n, string& t){
    getline(ip, s, ',');
    getline(ip, n, ',');
    getline(ip, t, '\n');
};

/* GenerateRandomNumbers */

// Constructor
RandomNumberGenerator::RandomNumberGenerator(int start, int end, int size){

    vector<int> v;
    vector<int> result;
    int random;
    int count = 0;

    /* Error Handling */
    try
    {
        if( (end - start) <= size )
            throw "csvExt)ractor.cpp in constructor \'CSVExtractor::CSVExtractor(int start, int end, int size)\': \"end\" must be bigger than \"size\"";
    }
    catch(const char* err)
    {
        cout << err << endl;
        cout << "Program Terminated with an error code -1" << endl;
        exit(-1);
    }

    /* Start */
    for(int i = start;  i <= end; i++) //0 - 9
        v.push_back(i);

    while(count != size){
        random = this->RandomWithRange(start, end);

        // If the vector element in the index is -1, pick again
        while(v.at(random) == -1)
            random = this->RandomWithRange(start, end);
        result.push_back(v.at(random));

        // Replace the used number as -1
        v.at(random) = -1;
        count ++;
    }
    v.clear();
    this->numbers = result;
};

// Methods
vector<int> RandomNumberGenerator::GetNumbers()
    { return this->numbers; };
int RandomNumberGenerator::RandomWithRange(int start, int end)
    { return (rand()%(end - start)); };
