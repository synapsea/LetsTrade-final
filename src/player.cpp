#include "player.hpp"

Player::Player(){};
Player::Player(std::string name, int age)
    :name(name),
    age(age){};
Player::Player(std::string n, int a, Portfolio* p)
    :name(n),
    age(a),
    portfolio(p){};

// Getter
std::string Player::GetName()
    { return this->name; };
int Player::GetAge()
    { return this->age; };
Portfolio Player::GetPortfolio()
    { return *(this->portfolio); };

// Setter
void Player::SetName(std::string name)
    { this->name = name; };
void Player::SetAge(int age)
    { this->age = age; };

// Destructor
Player::~Player(){
    delete this->portfolio;
    this->portfolio = NULL;
};
