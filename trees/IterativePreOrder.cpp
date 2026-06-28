//root->left->right

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to create a new node
    TreeNode(int value) {
        val = value;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            root=st.top();
            st.pop();
            ans.push_back(root->val);
            if(root->right !=NULL){
                st.push(root->right);
            }
            if(root->left !=NULL){
                st.push(root->left);
            }
            
        }

        return ans;
    }
};



/*
#include <iostream>     // for input/output
#include <vector>       // for dynamic array (vector)
#include <stack>        // for stack data structure

using namespace std;

// A simple tree node like struct in C
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to create a new node
    TreeNode(int value) {
        val = value;
        left = NULL;   // no left child initially
        right = NULL;  // no right child initially
    }
};

class Solution {
public:
    // Function to perform preorder traversal and return values in a vector
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;    // to store result
        if (root == NULL) {
            return preorder;     // if tree is empty, return empty vector
        }

        stack<TreeNode*> st;     // create a stack of tree nodes
        st.push(root);           // start by pushing root node into stack

        while (!st.empty()) {    // while stack is not empty
            TreeNode* node = st.top();  // get node on top of stack
            st.pop();                   // remove it from stack

            preorder.push_back(node->val);  // visit the node (add value to result)

            // Push right child first so that left child is processed first
            if (node->right != NULL) {
                st.push(node->right);
            }

            // Push left child
            if (node->left != NULL) {
                st.push(node->left);
            }
        }

        return preorder;  // return all values in preorder
    }
};

int main() {
    // Create this sample tree:
    //      1
    //     / \
    //    2   3
    //     \
    //      4

    TreeNode* root = new TreeNode(1);       // root
    root->left = new TreeNode(2);           // left child of 1
    root->right = new TreeNode(3);          // right child of 1
    root->left->right = new TreeNode(4);   // right child of 2

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    cout << "Preorder traversal: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}


*/
