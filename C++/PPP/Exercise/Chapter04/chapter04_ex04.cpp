/*
	4.猜数游戏，用户给出一个 1 到 100 之间的整数
*/

#include "std_lib_facilities.h"

int main()
{
	cout << "Think of a number between 1 and 100.\n"
		<< "For every guess, enter if your number is\n"
		<< "(l)arger or (s)maller than the one shown.\n"
		<< "Enter 'c' (for 'correct') if the number shown is yours.\n";
	int guess = 50;
	int large = 100;
	int small = 1;
	char answer = ' ';

	while (true) {
		cout << "I guess " << guess << '\n'
			<< "Correct, larger or smaller (c, l, s)? ";
		cin >> answer;
		switch (answer) {
		case 'c':
			cout << "bye\n";
			return 0;
		case 'l':
			large = guess;
			guess = (large+small)/2;
			break;
		case 's':
			small = guess;
			guess = (large+small)/2;
			break;
		default:
			cout << "This is not a valid answer, use 'c', 'l' or 's'\n";
			break;
		}
	}
}