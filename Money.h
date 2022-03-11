
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
	std::string getFigure();		//This getFigure() function is used to overload '<<'
	int getCents(){ return cents; }
	bool isWithdrawal();			//NOTE: isWithdrawal() is true if money is negative.
	
	Money operator+(Money);			//This overloads '+'.  Because we use the sign of cents
						// to determine if Money is a withdrawal, we actually
						//don't even need an overload for '-'.  Just add.
	bool operator==(Money);
	bool operator>=(Money);
	bool operator<=(Money);
	bool operator>(Money);			//Comparison operators
	bool operator<(Money);
	bool operator!=(Money);
};

#endif
