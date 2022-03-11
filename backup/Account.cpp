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

//Simply wraps the extract() friend function as an insertion operator.
std::ostream& operator<<(std::ostream& stream, Account account){
	return extract(stream, account);
}

//Produces the output required.
std::ostream& extract(std::ostream& stream, Account account){
	int deposits(0);
	int withdrawals(0);
	Money balance = account.getBalance();
	std::vector<Money> accounting = account.getAccounting();

	
	for (auto trans:accounting){
		if (trans.isWithdrawal()) {
			withdrawals++;
		}else{
			deposits++;
		}
	}
	
	stream << "Account Details" << std::endl
		<< "--------------------------" << std::endl
		<< "Current Balance:"  << balance
		<< std::endl << "--------------------------" << std::endl
		<< "Number of Deposits: " << deposits << std::endl
		<< "--------------------" << std::endl;
	int i=1;
	for (auto trans:accounting){
		if (!trans.isWithdrawal()){
			stream << "(" << i << ") " << trans << std::endl;
			i++;
		}
	}
	stream << "--------------------------" << std::endl
		<< "Number of Withdrawals: " << withdrawals << std::endl
		<< "--------------------------" << std::endl;
	i = 1;
	for (auto trans:accounting){
		if (trans.isWithdrawal()){
			stream << "(" << i << ") " << trans << std::endl;
			i++;
		}
	}
	stream << "----" << std::endl;	
	return stream;
}

//Brings balance up to speed with any new deposits or withdrawals.  Inefficient but sufficient.
//This function also resets the updateNeeded flag to false.
void Account::updateBalance(){
	balance = 0;
	for (auto trans:accounting){
		balance = trans+balance;
	}
	updateNeeded=false;
}

//Retrieves the current balance.  If the balance needs to be updated first (updateNeeded=TRUE)
//then it does this first.
Money Account::getBalance(){
	if (updateNeeded) this->updateBalance();
	return balance;
}

std::vector<Money> Account::getAccounting(){
	return accounting;
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

//Comparison operators

bool Account::operator==(Account account){
	return getBalance() == account.getBalance();
}

bool Account::operator>=(Account account){
	return getBalance() >= account.getBalance();
}

bool Account::operator<=(Account account){
	return getBalance() <= account.getBalance();
}

bool Account::operator>(Account account){
	return getBalance() > account.getBalance();
}

bool Account::operator<(Account account){
	return getBalance() < account.getBalance();
}

bool Account::operator!=(Account account){
	return getBalance() != account.getBalance();
}
