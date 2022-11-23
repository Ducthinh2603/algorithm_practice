#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int>& a, vector<int>& b, size_t left, size_t right) {
    long long number_of_inversions = 0;
    if (right <= left + 1) {
        b[left] = a[left];
        return number_of_inversions;
    }
    size_t ave = left + (right - left) / 2;
    number_of_inversions += get_number_of_inversions(a, b, left, ave);
    number_of_inversions += get_number_of_inversions(a, b, ave, right);
    //write your code here
    int ia = left, ib = ave;
    int i = left;
    int* c = new int[right - left];
    for (int i = 0; i < right - left; i++) {
        c[i] = b[left + i];
    }
    while (!(ia >= ave && ib >= right)) {
        int l = ia < ave ? c[ia - left] : 1000000001;
        int r = ib < right ? c[ib - left] : 1000000001;
        if (l <= r) {
            b[i++] = l;
            ia++;
        }
        else {
            b[i++] = r;
            ib++;
            number_of_inversions += (ave - ia);
        }
    }
    return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
