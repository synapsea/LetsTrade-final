#include "banking.hpp"

string list_bank[9]{
	"CIT Bank", "Bank of The West", "WELLS FARGO",
	"Washington Federal Savings and Loan", "Umpqua Bank",
	"Golden1 Credit Union", "EASTWEST BANK", "Charles Schwab", "CHASE"
};

char codebook[] = { 'a','A','b','B','c','C','d','D','e',
					'E','f','F','g','G','h','H','i','I','j','J','k','K',
					'l','L','m','M','n','N','o','O','p','P','q','Q','r',
					'R','s','S','t','T','u','U','v','V','w','W','x','X',
					'y','Y','z','Z','0','1','2','3','4','5','6','7','8','9',
					'!','@','#','$','%','&','*' };

Account::Account(Player* a_player) {

	player = a_player;
	set_balance(100);
	bank_name = list_bank[rand()%9];
	create_account_number();
	initialize_balance();

}

Account::Account(Player* player, string account_number, double balance)
	:player(player),
	account_number(account_number),
	balance(balance){};


void Account::initialize_balance(){
	this->balance = 100000.00;
}


double Account::get_balance(){

	return balance;
}

void Account::set_balance(double balance){

	this->balance = balance;
}

void Account::create_account_number(){

	char address[8];

     for(int i =0; i<8; i++){

		 address[i] = codebook[rand()%69];

	 }

	 this->account_number = address;

}

void Account::bal_change(Transaction t){
	if(t.GetTransactionType()=="Buy Stock"||"Bank Account Withraw"){
		balance -= t.GetAmount();
	}
	else if (t.GetTransactionType() == "Sell Stock"||"Bank Account Deposit"){
		balance += t.GetAmount();
	}
}

// void increase_bal

// void decrease_bal

string Account::create_log(Transaction t, Date* d){
	string tmp = account_number+to_string(d->GetMonth())+":"+to_string(d->GetDay())+":"+to_string(d->GetYear())+",	Description:"+t.GetTransactionType()+", Amount:"+to_string(t.GetAmount())+", current balance:"+ to_string(balance);
	return tmp;
}

void Account::input_record(Transaction t, Date* d){

		bal_change(t);
		string tmp = create_log(t,d);
		log.push_back(tmp);

}


void Account::print_record() {

	if(log.empty()){
		cout << "There is no transaction yet." << endl;
	}

	else{

	for(int i=0; i<log.size();i++){
		cout<<log.at(i);
	}
	}

}

void Account::info_Account(){

	cout << "User "<< player->GetName() << "'s account" << endl;
	cout << "Bank fo transaction : " << bank_name << endl;
	cout << "Account number : " << account_number << endl;
	cout << "Current balance : " << get_balance() << endl;
	print_record();

}

void Account::add_balance(double balance){
	this->balance_records.push_back(balance);
}

double Account::get_previous_balance(){
	return this->balance_records.back();
}
