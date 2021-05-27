#pragma once
#include "player.hpp"
#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;


class Account {

public:

	Account();

	Account(Player* a_player);

	Account(Player* player, string account_number, double balance);

	// Account(Player* p, string accountName, Bank* b); => A constructor using 'Bank' class
	//~Account();


	vector <string> log;


	void initialize_balance();
	void bal_change(Transaction t);
	double get_balance();
	void set_balance(double balance);
	void create_account_number();
	string create_log(Transaction t, Date* d);
	void print_record();
	void input_record(Transaction t, Date* d);
	void info_Account();
	void add_balance(double balance);
	double get_previous_balance();



private:
	Player* player;
	string account_number;
	double balance;
	string bank_name;
	std::vector<double> balance_records;
};
