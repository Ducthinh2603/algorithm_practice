#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int calculate_tree_height(Node* nodes, int n) {
	int* track_height = new int[n];
	int maxHeight = 0;
	for (int i = 0; i < n; i++) {
		track_height[i] = 1;
	}
	vector<Node*> stack;
	stack.push_back(nodes);
	while (!stack.empty()) {
		Node* v = stack.back();
		stack.pop_back();

		int child_num = v->children.size();
		if (child_num > 0) {
			for (int i = 0; i < child_num; i++) {
				track_height[v->children[i]->key] = track_height[v->key] + 1;
				stack.push_back(v->children[i]);
			}
		}
		else {
			maxHeight = std::max(maxHeight, track_height[v->key]);
		}
	}
	return maxHeight;
}


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  int root_ind;
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    else
      root_ind = child_index;
    nodes[child_index].key = child_index;
  }

  int myHeight = calculate_tree_height(&nodes[root_ind], n);

  // Replace this code with a faster implementation
//  int maxHeight = 0;
//  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
//    int height = 0;
//    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
//      height++;
//    maxHeight = std::max(maxHeight, height);
//  }
//
  std::cout << myHeight << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
