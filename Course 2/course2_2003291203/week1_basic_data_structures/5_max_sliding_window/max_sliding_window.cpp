#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

void max_sliding_window_naive(vector<int> const& A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}

bool pop_front(vector<int>& a) {
    if (a.empty()) return false;
    a.erase(a.begin());
    return true;
}

void max_sliding_window(vector<int> const& A, int m) {
    vector<int> window;

    for (int i = 0; i < A.size(); i++) {

        while (!window.empty() && window.front() < i - m + 1 ) {
            pop_front(window);
        }
        while (!window.empty()) {
            if (A[i] > A[window.back()])
                window.pop_back();
            else
                break;
        }
        window.push_back(i);
        if (i >= m - 1) {
            cout << A[window.front()] << " ";
        }
    }
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    /*max_sliding_window_naive(A, w);
    cout << "\n";*/
    max_sliding_window(A, w);

    return 0;
}
