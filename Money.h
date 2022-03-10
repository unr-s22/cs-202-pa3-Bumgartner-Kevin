
#include <string>
#ifndef MONEY_H
#define MONEY_H

class Money{
private:
	int cents; // This is an integer, the total number of cents.  This is negative or
		   // positive, with negative meaning a withdrawal, and positive meaning
		   // a deposit.
public:
	//CONSTRUCTORS
	Money():cents(0){};
	Money(int dollars) :cents(100*dollars){};
	Money(int dollars, int cents) :cents(100*dollars+cents){};
	Money(double); 	//This constructor takes a double (number of
			//  dollars) and rounds to the nearest cent
	
	//getters
	std::string getFigure();		//Use getFigure() to overload '<<'
	int getCents(){ return cents; }
	bool isWithdrawal();			//NOTE: isWithdrawal() is true if money is negative.
	
	static Money add(Money, Money);		//TODO: Use this to overload '+'
};

#endif
