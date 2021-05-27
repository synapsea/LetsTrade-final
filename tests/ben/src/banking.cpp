
#include "banking.hpp"
#include <cstdlib>
#include <ctime>


string list_bank[9]{
	"CIT Bank", "Bank of The West", "WELLS FARGO",
	"Washington Federal Savings and Loan", "Umpqua Bank",
	"Golden1 Credit Union", "EASTWEST BANK", "Charles Schwab", "CHASE"
};

Account::Account() {

	bal_account = 0;

	cout << "please input your username : " << endl;
	cin >> this->username;

	bank_name = list_bank[rand() % 9];
	cout << "your account is randomly creadted on " << this->bank_name << endl;

	//log.push_back(username+"'s account created on "+bank_name);


}

Account::Account(string uname, int index_bankarr) {

	bal_account = 0;
	username = uname;
	bank_name = list_bank[index_bankarr];

}

string Account::time_stamp() {

	string ttime;

	return ttime;

}

void Account::record_Account(string rec) {

	log.push_back(rec);

}

void Account::info_Account(Account a){

	cout << "User "<<a.username << "'s account" << endl;
	cout << "Bank fo transaction : " << a.bank_name << endl;
	cout << "Current balance : " << a.bal_account << endl;

}

void Account::decreased_bal(double dprice) {


	bal_account -= dprice;

	string record;
	record = "";
	Account::record_Account(record);


}

void Account::increased_bal(double iprice) {

	bal_account += iprice;

	string record;
	record = "";
	Account::record_Account(record);
}

void Account::transfer_Account(Account toAccount, double tmoney) {

	bal_account -= tmoney;
	toAccount.bal_account += tmoney;

}
