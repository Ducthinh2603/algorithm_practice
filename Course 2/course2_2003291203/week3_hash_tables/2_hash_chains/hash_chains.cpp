#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;
    vector<string>* hash_table;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count):
    bucket_count(bucket_count) {
        hash_table = new vector<string>[bucket_count];
    }

    Query readQuery(std::fstream &output) const {
        Query query;
        output >> query.type;
        // std::cout << query.type << " ";
        if (query.type != "check") {
            output >> query.s;
            // std::cout << query.s << "\n";
        }
        else {
            output >> query.ind;
            // std::cout << query.ind << "\n";
        }
        return query;
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void writeSearchResult(bool was_found, std::ofstream &out) const {
        out << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            // this is naive implementation
//            for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
//                if (hash_func(elems[i]) == query.ind)
//                    std::cout << elems[i] << " ";
//            std::cout << "\n";
            vector<string> bucket = hash_table[query.ind];
            for (int i = bucket.size() - 1; i >= 0; i--) {
                std::cout << bucket[i] << " ";
            }
            std::cout << "\n";
        } else {
            int index = hash_func(query.s);
            vector<string>::iterator it = std::find(hash_table[index].begin(), hash_table[index].end(), query.s);

            if (query.type == "find")
                writeSearchResult(it != hash_table[index].end());
            else if (query.type == "add") {
                if (it == hash_table[index].end())
                    hash_table[index].push_back(query.s);
            } else if (query.type == "del") {
                if (it != hash_table[index].end())
                    hash_table[index].erase(it);
            }
        }
    }

    void processQuery(const Query& query, std::ofstream &out) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            // this is naive implementation
//            for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
//                if (hash_func(elems[i]) == query.ind)
//                    std::cout << elems[i] << " ";
//            std::cout << "\n";
            vector<string> bucket = hash_table[query.ind];
            for (int i = 0; i < bucket.size(); i++) {
                out << bucket[i] << " ";
            }
            out << "\n";
        } else {
            int index = hash_func(query.s);
            vector<string> bucket = hash_table[index];
            vector<string>::iterator it = std::find(bucket.begin(), bucket.end(), query.s);

            if (query.type == "find")
                writeSearchResult(it != bucket.end(), out);
            else if (query.type == "add") {
                if (it == bucket.end())
                    hash_table[index].push_back(query.s);
            } else if (query.type == "del") {
                if (it != bucket.end())
                    hash_table[index].erase(it);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }

    void processQueries(std::fstream &output) {
        // string file = "/Users/thdg/Personal/algorithm_practice/Course 2/course2_2003291203/week3_hash_tables/2_hash_chains/tests/06";
        // std::ofstream out(file);
        int n;
        output >> n;
        // log
        for (int i = 0; i < n; ++i)
            processQuery(readQuery(output));
        // out.close();
    }
};

void test() {
    string file = "/Users/thdg/Personal/algorithm_practice/Course 2/course2_2003291203/week3_hash_tables/2_hash_chains/tests/06";
    std::fstream output;
    output.open(file);
    int bucket_count;
    output >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries(output);
    output.close();
}

int main() {
    test();
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
