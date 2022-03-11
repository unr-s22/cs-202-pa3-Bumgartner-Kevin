all: main.cpp Account.o
	g++ -std=c++11 -Werror -o pa3 main.cpp

Account.o: Account.cpp Account.h Money.o
	g++ -std=c++11 -Werror -c Account.cpp

Money.o: Money.cpp Money.h
	g++ -std=c++11 -Werror -c Money.cpp

clean:
	rm *.o pa3

test: test.cpp Money.o
	g++ -std=c++11 -Werror -o test test.cpp
