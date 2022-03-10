#include <vector>
#include <string>



#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
private:
	std::vector<Money> accounting; //The accounting vector is a vector of moneys.
	bool updateNeeded=true;        //Indicates if there has been a transaction since the last
					//balance update.
	Money balance=0;               //This is the current balance.
public:
	Account(Money);			//Initiates an account with an initial deposit.
	Account(double);		//Initiates an account with an initial deposit constructed from a double.
	friend std::ostream& extract(std::ostream&, Account);//Produces the output required by the assignment.
	void updateBalance();		//Brings balance up to date with the accounting vector.
	Money getBalance();		//Returns the current balance.  If needed, the balance is updated first.
	std::vector<Money> getAccounting();
	void deposit(Money);		//Adds a deposit to the account.
	void deposit(double);		//Adds a deposit to the account after constructing a money object.
	void withdraw(Money);		//Adds a withdrawal to the account.
	void withdraw(double);		//Adds a withdrawal after constructing the money object.
};

#endif

//TODO: We need to have deposit() and withdraw() throw errors if they receive negative values.
