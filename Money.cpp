#include <iostream>
#include <sstream>
#include <cmath>
#include "Money.h"

Money::Money(double dollars){
		cents = static_cast<int>(round(dollars))*100;  
		dollars *= 100;
		dollars -= cents;
		cents += static_cast<int>(round(dollars));
}

std::string Money::getFigure(){
	std::stringstream outString;
	int dollars = static_cast<int> (cents/100);
	std::string buffy;
	if (abs(dollars*100-cents) < 10){
		buffy = "0";
	}else{
		buffy="";
	}
	
	if (cents < 0) {
		outString << "-$" << (-1)*dollars << "." << buffy << dollars*100-cents;
	}else{
		outString << "$" << dollars << "." << buffy << cents - dollars*100;
	}
	return outString.str();
}

bool Money::isWithdrawal(){
	return (cents<0);
}

Money Money::add(Money addend1, Money addend2){
	int centSum = addend1.getCents() + addend2.getCents();
	Money sum(static_cast<double>(centSum)/100.0);
	return sum;
}

//TODO We need overloads for >, <, >=, <=, ==, !=, and <<.  The overload for << should use getFigure().  But he also says we need to use a friend function for the << overload.  Isn't that just the normal way to overload an operator?
