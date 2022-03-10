#include <vector>
#include <string>



#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
private:
	std::vector<Money> accounting;
	bool updateNeeded=true;
	Money balance=0;
public:
	Account(Money);
	std::string printAccount();
	void updateBalance();
	Money getBalance();
	void deposit(Money);
	//void withdraw(Money);
};

#endif
