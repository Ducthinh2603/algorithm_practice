#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;

bool sortbysec(const pair<int, int>& x, const pair<int, int>& y) {
    return x.second < y.second;
}

double distance(const pair<int, int>& x, const pair<int, int>& y) {
    return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

double trivial_case(const vector<pair<int, int>> points, int left, int right) {
    double d = 2000000002;
    for (int i = left; i < right - 1; i++) {
        for (int j = i + 1; j < right; j++) {
            d = std::min(d, distance(points[i], points[j]));
        }
    }
    return d;
}

double minimal_distance_execute(
    vector<pair<int, int>> points, int left, int right, bool sortbyx) {
    // handle trivial cases:
    if (right - left <= 3) {
        return trivial_case(points, left, right);
    }

    // recursive part
    int mid = left + (right - left) / 2 + 1;
    double d1 = minimal_distance_execute(points, left, mid, sortbyx);
    double d2 = minimal_distance_execute(points, mid, right, sortbyx);
    int line = sortbyx ? points[mid].first : points[mid].second;
    double d = min(d1, d2);
    vector<pair<int, int>> vicinity;
    vicinity.push_back(points[mid]);
    int il = mid - 1;
    int ir = mid + 1;
    while (il >= left && ir < right) {
        //handle left
        int left_ele = sortbyx ? points[il].first : points[il].second;
        int right_ele = sortbyx ? points[ir].first : points[ir].second;

        if (line - left_ele < d) vicinity.push_back(points[il--]);
        else il = left - 1;

        //handle right
        if (right_ele - line < d) vicinity.push_back(points[ir++]);
        else ir = right;
    }
    if (sortbyx) {
        std::sort(vicinity.begin(), vicinity.end(), sortbysec);
        d = std::min(d, minimal_distance_execute(vicinity, 0, vicinity.size(), false));
    }
    else d = std::min(d, trivial_case(vicinity, 0, right - left));

    return d;

}

double minimal_distance(vector<int> x, vector<int> y) {
    //write your code here
    int n = x.size();
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        points.push_back({ x[i], y[i] });
    }

    std::sort(points.begin(), points.end());

    return minimal_distance_execute(points, 0, n, true);
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
