#include <iostream>
#include <vector>
using std::vector;

int fibonacci_sum(long long n) {
    if (n < 0) return 0;
    if (n <= 1) return n;

    long long rem = n % 60;
 
        // Checking the remainder
    if(rem == 0)
       return 0;
    else {
        long long f0 = 0;
        long long f1 = 1;
        for(long long i = 2; i < rem + 3; i++)
        {
           long long f = (f0 + f1) % 60;
           f0 = f1;
           f1 = f;
        }
         
        long long s = f1 - 1;
        return s % 10;
    }   
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    int s = fibonacci_sum(to) - fibonacci_sum(from - 1);
    return s >= 0 ? s : 10 + s;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
