#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
// #include "../../../../utils/cpp/file_interator.h"


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool inner(int& lastBiggest, const vector<Node>& tree, int ind, bool& check) {
  if (!check) return false;

  int l = tree[ind].left, r = tree[ind].right, tempBiggest = tree[ind].key;
  bool hasLeft = false;
  if (l != -1) {
    check = inner(lastBiggest, tree, tree[ind].left, check);
    hasLeft = true;
  }
  if ((hasLeft && lastBiggest < tree[ind].key) || (!hasLeft && lastBiggest <= tree[ind].key)) {
    lastBiggest = tree[ind].key;
  }
  else return false;
  if (r != -1) {
    check = inner(lastBiggest, tree, tree[ind].right, check);
  }
  return check;
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if (tree.size() == 0) return true;
  bool check = true;
  int init = INT32_MIN;
  check = inner(init, tree, 0, check);
  return check;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
// int main() {
//   FileInteractor file = FileInteractor("Course 2\\course2_2003291203\\week4_binary_search_trees\\2_is_bst\\test\\01");
//   int nodes;
//   file.fileStream >> nodes;
//   vector<Node> tree;
//   for (int i = 0; i < nodes; ++i) {
//     int key, left, right;
//     file.fileStream >> key >> left >> right;
//     tree.push_back(Node(key, left, right));
//   }
//   if (IsBinarySearchTree(tree)) {
//     cout << "CORRECT" << endl;
//   } else {
//     cout << "INCORRECT" << endl;
//   }
//   return 0;
// }