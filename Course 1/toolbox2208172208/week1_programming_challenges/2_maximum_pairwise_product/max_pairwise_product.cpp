#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    int n = numbers.size();

    int first = std::max(numbers[0], numbers[1]);
    int second = std::min(numbers[0], numbers[1]);

    for (int i = 2; i < n; i++) {
        if (numbers[i] > first) {
            second = first;
            first = numbers[i];
        }
        else {
            if (numbers[i] > second) {
                second = numbers[i];
            }
        }
    }

    return (long long)(first) * second;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
