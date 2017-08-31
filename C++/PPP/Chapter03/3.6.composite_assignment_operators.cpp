#include "std_lib_facilities.h"

int main()
{
	int number_of_words = 0;
	string previous = " ";
	string current;
	while (cin >> current) {
		++number_of_words;
		if (previous == current)
			cout << "word number " << number_of_words
				<< " repeated: " << current << '\n';
		previous = current;
	}
	return 0;
}