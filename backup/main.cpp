//SEE test.cpp

//---------------------CHECKLIST FROM ASSIGNMENT-----------------------------
//In your `main` function in `main.cpp`,

//* Create an account with a starting balance of $300.23
//* Print the account to the terminal using the overloaded << operator (i.e., `std::cout << account << std::endl`)
//* Deposit into the account, in order, $200.00, $300.24, and $501.22
//* Print the account to the terminal. (Verify that the sum is correct)
//* Withdraw, in order, $300.10, $201.34 and again print the account to the terminal.
//* Write code to verify that your relational operators are working correctly. This is up to you, however, you must have printouts to the console showing that the operations are correct.
//** For example, you might write...

#include <iostream>
#include "Account.cpp"

//TODO We need overloads for >, <, >=, <=, ==, !=, and <<.

//NOTES OVERALL: This class heirarchy has two tiers.  The Account class contains a vector of class Money.
//The vector contains Money objects with positive integer cents (called "deposits") and Money objects with
//negative integer cents (called "withdrawals").  Each money object can be queried to test if it is a
//deposit or a withdrawal, using the isWithdrawal() method.  The entire vector can be added together to
//get the total balance.  The initial deposit is considered a deposit.

//In the following code, we are using the overloaded constructor to give an initial deposit as a double
//instead of as a money object.  The constructor simply constructs a money object based on the double.
//IT'S IMPORTANT TO NOTE THAT THIS IS FINE; THE ASSIGNMENT REQUIRES WE PROVIDE A CONSTRUCTOR WHICH
//TAKES TWO INTEGERS.  WE PROVIDE ONE, BUT WE ALSO PROVIDE ONE WHICH TAKES A DOUBLE.  BOTH OF THESE
//CONSTRUCT AN OBJECT STORING 'cents' AS AN INTEGER.

int main(){
	Account account(300.23); 
	std::cout << account << std::endl;
	account.deposit(200.00);
	account.deposit(300.24);
	account.deposit(501.22);
	std::cout << account << std::endl;
	account.withdraw(300.10);
	account.withdraw(201.34);
	std::cout << account << std::endl;
}

