#include "std_lib_facilities.h"

int main()
try {
	int i = 0;
	while (true) {
		int* p = new int[262144];
		cout << ++i << " MB\n";
	}
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
}
