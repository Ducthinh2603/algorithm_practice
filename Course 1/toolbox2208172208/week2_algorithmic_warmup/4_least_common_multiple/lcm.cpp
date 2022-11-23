#include <iostream>

int gcd_fast(int a, int b) {
  int c = std::max(a, b);
  int d = std::min(a, b);
  int r = c % d;
  do {
    r = c % d;
    c = d; 
    d = r;
  } while (r > 0) ;
  return c;
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {
  long long gcd = gcd_fast(a, b);
  return gcd * (a / gcd) * (b / gcd);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
