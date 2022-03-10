#include <iostream>
#include <sstream>
#include <cmath>
#include "Money.h"

//All other constructors are in-line, this one takes a little work
//please remember that cents is a SIGNED integer, with a negative
//value indicating a debit and a positive indicating a credit
Money::Money(double dollars){
		cents = static_cast<int>(round(dollars))*100;  
		dollars *= 100;
		dollars -= cents;
		cents += static_cast<int>(round(dollars));
}

//This returns the string we'd like to use for overloading '<<'
//Not sure yet if it's ok to return "-$100.00" for a negative
// (withdrawal) but for now let's keep it this way.  Can always just
// delete the "-$" in line 31 to fix.
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

//Tells us if cents is negative
bool Money::isWithdrawal(){
	return (cents<0);
}

//Adds two moneys together, returns a money.
Money Money::add(Money addend1, Money addend2){
	int centSum = addend1.getCents() + addend2.getCents();
	Money sum(static_cast<double>(centSum)/100.0);
	return sum;
}

//TODO We need overloads for >, <, >=, <=, ==, !=, and <<.  The overload for << should use getFigure().  But he also says we need to use a friend function for the << overload.  Isn't that just the normal way to overload an operator?
