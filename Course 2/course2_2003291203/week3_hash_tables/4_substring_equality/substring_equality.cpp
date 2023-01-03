#include <iostream>

using namespace std;


long long m1 = 1000000007;
long long m2 = 1000000009;
int x = 263;

class Solver {
	string s;
	long long* hash_m1;
	long long* hash_m2;
public:

	Solver(string s) : s(s) {	
		// initialization, precalculation
		
		int n = s.length();
		hash_m1 = new long long[n + 1];
		hash_m2 = new long long[n + 1];
		hash_m1[0] = 0;
		hash_m2[0] = 0;
		long long t1 = 0;
		long long t2 = 0;
		for (int i = 1; i <= n; i++) {
			t1 = ((t1 * x + s[i - 1]) % m1 + m1) % m1;
			t2 = ((t2 * x + s[i - 1]) % m2 + m2) % m2;
			hash_m1[i] = t1;
			hash_m2[i] = t2;
		}
	}
	bool ask(int a, int b, int l) {
		if (b < a) {
			int c = a;
			a = b;
			b = c;
		}
		long long xtol_m1 = 1;
		long long xtol_m2 = 1;

		for (int i = 0; i < l; i++) {
			xtol_m1 = ((xtol_m1 * x) % m1 + m1) % m1;
			xtol_m2 = ((xtol_m2 * x) % m2 + m2) % m2;
		}
		long long c1 = ((hash_m1[a + l] - hash_m1[a] * xtol_m1) % m1 + m1) % m1; 
		long long c2 = ((hash_m2[a + l] - hash_m2[a] * xtol_m2) % m2 + m2) % m2; 
		long long d1 = ((hash_m1[b + l] - hash_m1[b] * xtol_m1) % m1 + m1) % m1; 
		long long d2 = ((hash_m2[b + l] - hash_m2[b] * xtol_m2) % m2 + m2) % m2;
		return c1 == d1 && c2 == d2;
	}
};


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
