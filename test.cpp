#include <iostream>
#include "Account.cpp"

int main(){
	Money money1(100.10);
	Money money2(50,10);
	Money money3(-150.2);
	Money money4;
	std::cout << std::endl << money1.getFigure() << std::endl
		<< money2.getFigure() << std::endl << money3.getFigure()
		<< std::endl << money4.getFigure() << std::endl;
	
	std::cout << (money1.getCents() + money2.getCents())/100.0 << std::endl;

	Money sum = Money::add(money1,money2);
	std::cout << sum.getFigure() << std::endl;

	std::string type;
	if (money2.isWithdrawal()){
		type="withdrawal";
	}else{
		type="deposit";
	}
	std::cout << "Money2 is a " << type << std::endl;
	
	Account account1(money1);
	account1.deposit(money2);
	std::cout << account1.printAccount() << std::endl;
}

