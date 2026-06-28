#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);

                level.push_back(node->val);
            }

            ans.push_back(level);
        }

        return ans;
    }
};











/*

//very basics 

#include <iostream>     // for input/output
#include <queue>        // for queue
using namespace std;

// A simple binary tree node (just like struct in C)
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

// Function to do level order traversal
void levelOrder(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;     // queue to store tree nodes
    q.push(root);           // push root node to start

    while (!q.empty()) {
        TreeNode* node = q.front();  // get the front node
        q.pop();                     // remove it from queue

        cout << node->val << " ";    // print the node value

        // push left and right children (if not NULL)
        if (node->left != NULL) {
            q.push(node->left);
        }

        if (node->right != NULL) {
            q.push(node->right);
        }
    }
}

int main() {
    // Create a sample tree:
    //      1
    //     / \
    //    2   3

    TreeNode* root = new TreeNode(1);        // root node
    root->left = new TreeNode(2);            // left child
    root->right = new TreeNode(3);           // right child

    cout << "Level Order Traversal: ";
    levelOrder(root);        // call the function

    return 0;
}


*/