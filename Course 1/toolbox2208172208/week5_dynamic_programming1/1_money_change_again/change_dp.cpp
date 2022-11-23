#include <iostream>
#include <math.h>

using std::min;

int get_change(int m) {
	//write your code here
	int* money = new int[m + 1];

	for (int i = 1; i <= m; i++) {
		int a = i - 1 >= 1 ? money[i - 1] : 0;
		int b = i - 3 >= 1 ? money[i - 3] : 0;
		int c = i - 4 >= 1 ? money[i - 4] : 0;
		money[i] = min(min(a, b), c) + 1;
	}
	return money[m];
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
