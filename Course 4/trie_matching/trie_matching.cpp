#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    5;
int const NA      =   -1;

struct Node
{
	int next [Letters];
	int root;

	Node ()
	{
		fill (next, next + Letters, NA);
	}
	Node(int v) {
		fill(next, next + Letters, NA);
		root = v;
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}

};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		case '$': return 4; break;
		default: assert (false); return -1;
	}
}

vector<Node> build_trie(const string& text) {
	vector<Node> trie(1, Node());
	string t = text + "$";
	int current_ind = 0;
	for (int i = 0; i < t.size(); i++) {
		int ind = 0;
		for (int j = i; j < t.size(); j++) {
			int letter_ind = letterToIndex(t[j]);
			if (trie[ind].next[letter_ind] == NA) {
				trie.push_back(Node(i));
				trie[ind].next[letter_ind] = ++current_ind;	
			}
			
			ind = trie[ind].next[letter_ind];
		}
	}
	return trie;
}

vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;
	auto trie = build_trie(text);

	for (auto p: patterns) {
		int ind = 0;
		bool proceed = true;
		// check if pattern is in trie
		for (auto c: p) {
			int letter_ind = letterToIndex(c);
			if (trie[ind].next[letter_ind] == -1) {
				proceed = false;
				break;
			}
			else {
				ind = trie[ind].next[letter_ind];
			}
		}

		if (proceed) {
			vector<int> q;
			q.push_back(ind);
			while(!q.empty()) {
				int ind = q.back();
				q.pop_back();
				if (trie[ind].isLeaf()) {
					result.push_back(trie[ind].root);
				}
				else {
					for (auto i: trie[ind].next) {
						if (i != -1) {
							q.push_back(i);
						}
					}
				}
			}
		}
	}
	// write your code here
	sort(result.begin(), result.end());

	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++) 
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}