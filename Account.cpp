#include "Money.cpp"
#include "Account.h"

//Simple constructor
Account::Account(Money initialDeposit){
	accounting.push_back(initialDeposit);
}

//Compound constructor
Account::Account(double initialDeposit){
	Money initialMoney(initialDeposit);
	accounting.push_back(initialMoney);
}

//Produces the output required.  Uses stringstream.
std::string Account::printAccount(){
	std::stringstream outString;
	int deposits(0);
	int withdrawals(0);
	Money balance = this->getBalance();

	
	for (auto trans:accounting){
		if (trans.isWithdrawal()) {
			withdrawals++;
		}else{
			deposits++;
		}
	}
	
	outString << "Account Details" << std::endl
		<< "--------------------------" << std::endl
		<< "Current Balance:"  << balance.getFigure()
		<< std::endl << "--------------------------" << std::endl
		<< "Number of Deposits: " << deposits << std::endl
		<< "--------------------" << std::endl;
	int i=1;
	for (auto trans:accounting){
		if (!trans.isWithdrawal()){
			outString << "(" << i << ") " << trans.getFigure() << std::endl;
			i++;
		}
	}
	outString << "--------------------------" << std::endl
		<< "Number of Withdrawals: " << withdrawals << std::endl
		<< "--------------------------" << std::endl;
	i = 1;
	for (auto trans:accounting){
		if (trans.isWithdrawal()){
			outString << "(" << i << ") " << trans.getFigure() << std::endl;
			i++;
		}
	}
	outString << "----";
	return outString.str();
	
}

//Brings balance up to speed with any new deposits or withdrawals.  Inefficient but sufficient.
//This function also resets the updateNeeded flag to false.
void Account::updateBalance(){
	balance = 0;
	for (auto trans:accounting){
		balance = Money::add(trans, balance);
	}
	updateNeeded=false;
}

//Retrieves the current balance.  If the balance needs to be updated first (updateNeeded=TRUE)
//then it does this first.
Money Account::getBalance(){
	if (updateNeeded) this->updateBalance();
	return balance;
}

//Adds a new deposit to the account.
void Account::deposit(Money dep){
	accounting.push_back(dep);
	updateNeeded=true;
}

//Constructs a money object from a double, then deposits it to the account.
void Account::deposit(double dep){
	Money depo(dep);
		accounting.push_back(depo);
	updateNeeded=true;
}

//Adds a new deposit to the account.
void Account::withdraw(Money dep){
	Money depo(-dep.getCents());
	updateNeeded=true;
}

//Constructs a money object from a double, then deposits it to the account.
void Account::withdraw(double dep){
	Money depo(-dep);
		accounting.push_back(depo);
	updateNeeded=true;
}
