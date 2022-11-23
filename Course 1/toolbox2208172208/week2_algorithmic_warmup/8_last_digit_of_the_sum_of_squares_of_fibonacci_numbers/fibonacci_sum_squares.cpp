#include <iostream>
 
const long long MAX = 536860000;
int f[MAX] = {0};

int fib(long long n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if ( n < MAX && f[n]) return f[n];

    long long k = (n & 1) ? (n + 1) / 2 : n / 2;
 
    int temp = ((n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
                   : (2 * fib(k - 1) + fib(k)) * fib(k)) % 10; 
    if (n < MAX) f[n] = temp;
    return temp;
}
 
int fibonacci_sum_squares_naive(long long n) {
    return (fib(n+1) * fib(n)) % 10;
    // return 1;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
