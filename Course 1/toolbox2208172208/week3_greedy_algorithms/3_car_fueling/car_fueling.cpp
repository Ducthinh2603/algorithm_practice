#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    int last_stop = 0;
    int rs = 0;
    stops.push_back(dist);
    int n = stops.size();
    int ind = 0;
    while (ind < n) {
        int temp = last_stop + tank;
        if (temp >= stops[n-1]) break;
        if (temp < stops[ind]) {
            if (ind == 0 || last_stop == stops[ind - 1]) {
                rs = -1;
                break;
            }
            else {
                last_stop = stops[ind - 1];
                rs += 1;
            }
        }
        else if (temp == stops[ind]) {
            last_stop = stops[ind];
            rs += 1;
            ind++;
        }
        else ind++;
    }
    // write your code here
    return rs;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
