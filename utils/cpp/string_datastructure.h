#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef map<char, int> edges;
typedef vector<edges> trie;

// Trie
class Trie
{
public:
    trie build_trie(vector<string> &patterns)
    {
        trie t(1, edges());
        int current_num = 1;
        // write your code here
        for (const auto &p : patterns)
        {
            int next_ind = 0;
            for (const auto &c : p)
            {
                if (t[next_ind].count(c))
                {
                    next_ind = t[next_ind][c];
                }
                else
                {
                    t[next_ind][c] = current_num;
                    next_ind = current_num;
                    t.push_back(edges());
                    current_num++;
                }
            }
        }
        return t;
    }

    trie build_trie(string &text)
    {
        trie t(1, edges());
        int current_num = 1;
        int n = text.size();
        vector<string> patterns;

        for (int i = 0; i < n; i++)
        {
            patterns.push_back(text.substr(i, n - i));
        }
        return build_trie(patterns);
    }
};


// Suffix Tree

//Suffix Tree node
struct Node
    {
        Node *suffixLink;
        int s, t;
        Node *next[5];
        Node(int s, int t)
        {
            this->s = s;
            this->t = t;
            this->suffixLink = NULL;
            next[0] = NULL;
            next[1] = NULL;
            next[2] = NULL;
            next[3] = NULL;
            next[4] = NULL;
        }
        int length()
        {
            return this->t - this->s;
        }
    };

class SuffixTree
{
private:
    string text;

    int stringToIndex(char letter)
    {
        switch (letter)
        {
        case 'A':
            return 0;
            break;
        case 'C':
            return 1;
            break;
        case 'G':
            return 2;
            break;
        case 'T':
            return 3;
            break;
        case '$':
            return 4;
            break;
        default:
            assert(false);
            return -1;
        }
    }

    void createNewOldHalfNode(Node *node, Node *newOldHalfNode, Node &root, const string &text)
    {
        for (int i = 0; i < 5; i++)
        {
            newOldHalfNode->next[i] = node->next[i];
            node->next[i] = NULL;
        }
        newOldHalfNode->suffixLink = node->suffixLink;
        node->t = newOldHalfNode->s;
        node->next[stringToIndex(text[node->t])] = newOldHalfNode;
        node->suffixLink = &root;
    }

    Node *walkDown(int start, int end, Node *startNode, const string &text, Node &root)
    {
        int len = startNode->length();

        if (len < end - start)
        {
            int ind = stringToIndex(text[start + len]);
            if (startNode->next[ind] != NULL)
            {
                startNode = walkDown(start + len, end, startNode->next[ind], text, root);
                return startNode;
            }
            else
            {
                // type A without create extra internal node
                Node *newNode = new Node(start + len, text.length());
                newNode->suffixLink = &root;
                startNode->t = (startNode->t == -1 || startNode->t != text.length()) ? startNode->t : start + len;
                startNode->next[ind] = newNode;
                return startNode;
            }
        }
        else
        {
            int i = startNode->s;
            int j = start;
            bool isTypeC = true;
            for (int k = 0; k < end - start; k++)
            {
                if (text[i] != text[j])
                {
                    isTypeC = false;
                    break;
                }
                i++;
                j++;
            }
            if (!isTypeC)
            {
                // type A create extra internal node

                // create half old node
                Node *newOldHalfNode = new Node(i, startNode->t);
                createNewOldHalfNode(startNode, newOldHalfNode, root, text);

                // create new half node
                Node *newNewHalfNode = new Node(j, text.length());
                newNewHalfNode->suffixLink = &root;
                startNode->next[stringToIndex(text[j])] = newNewHalfNode;

                return startNode;
            }
            else
            {
                // type C
                return NULL;
            }
        }
    }

public:

    SuffixTree(string text)
    {
        this->text = text;
    }

    Node *createSuffixTree()
    {
        int n = text.length();

        Node root(-1, -1);
        root.suffixLink = &root;
        int numLeafNode = 0;
        Node *startNode = &root;

        for (int i = 1; i <= n; i++)
        {
            bool isPreviousTypeA1 = false;
            Node *previousInternalNode = NULL;
            for (int j = numLeafNode; j < i; j++)
            {
                Node *node = walkDown(j, i, startNode, text, root);
                if (node == NULL)
                {
                    break;
                }
                else
                {
                    if (!isPreviousTypeA1)
                    {
                        isPreviousTypeA1 = true;
                        previousInternalNode = node;
                    }
                    else
                    {
                        previousInternalNode->suffixLink = node;
                        previousInternalNode = node;
                    }
                    startNode = node->suffixLink;
                    numLeafNode++;
                }
            }
        }
        return &root;
    }
};
