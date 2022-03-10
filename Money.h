
#include <string>
#ifndef MONEY_H
#define MONEY_H

class Money{
private:
	int cents;
public:
	Money():cents(0){};
	Money(int dollars):cents(100*dollars){};
	Money(int dollars, int cents):cents(100*dollars+cents){};
	Money(double);
	
	std::string getFigure();
	int getCents(){ return cents; }
	bool isWithdrawal();
	
	static Money add(Money, Money);
};

#endif
