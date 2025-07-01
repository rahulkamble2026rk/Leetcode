/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to check if the tree is a valid BST
    bool isValidBSTUtil(TreeNode* node, long min, long max) {
        // Base case: an empty tree is a valid BST
        if (node == nullptr) 
            return true;

        // If the current node's value violates the min/max constraints, it's not a valid BST
        if (node->val <= min || node->val >= max) 
            return false;

        // Recursively check the left and right subtrees
        // Left subtree: all values must be less than the current node's value
        // Right subtree: all values must be greater than the current node's value
        return isValidBSTUtil(node->left, min, node->val) && 
               isValidBSTUtil(node->right, node->val, max);
    }

    // Main function to check if a binary tree is a valid BST
    bool isValidBST(TreeNode* root) {
        // Call the helper function with initial range (-infinity, infinity)
        return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
    }
};
