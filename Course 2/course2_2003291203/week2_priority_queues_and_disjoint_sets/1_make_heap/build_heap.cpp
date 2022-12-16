#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <assert.h>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;

    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void WriteResponse(std::string file) const {
        std::ifstream output;
        output.open(file);
        int n = swaps_.size();
        int m;
        output >> m;
        assert(n == m);
        for (int i = 0; i < swaps_.size(); ++i) {
            int a, b;
            output >> a >> b;
            assert(
                (swaps_[i].first == a && swaps_[i].second == b) ||
                (swaps_[i].first == b && swaps_[i].second == a)
            );
        }
        output.close();
    }

    void ReadData(std::string file) {
        std::ifstream output;
        output.open(file);
        int n;
        output >> n;
        data_.resize(n);
        for (int i = 0; i < n; ++i)
            output >> data_[i];
        output.close();
    }

    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> data_[i];
    }

    void complyHeapRule(int n, int m, int k) {
        int ind;
        do {
            ind = k;
            int left = 2 * k + 1;
            if (left < n && data_[left] < data_[ind]) {
                ind = left;
            }
            int right = 2 * k + 2;
            if (right < n && data_[right] < data_[ind]) {
                ind = right;
            }

            if (ind != k) {
                swaps_.push_back(make_pair(k, ind));
                swap(data_[k], data_[ind]);
            }
            k = ind;
        } while (k <= m);
    }

    void GenerateSwaps() {
        swaps_.clear();
        // naive swap for heap
        int n = data_.size();
        int m = (n - 2) / 2;
        for (int i = m; i >= 0; i--) {
            complyHeapRule(n, m, i);
        }
    }

public:
    void Solve(bool test) {
        std::string file_name = "D:\\My_project\\Data Structures and Algorithms Specialization\\algorithm_practice\\Course 2\\course2_2003291203\\week2_priority_queues_and_disjoint_sets\\1_make_heap\\tests\\04";
        ReadData(file_name);
        GenerateSwaps();
        WriteResponse(file_name + ".a");
    }
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
