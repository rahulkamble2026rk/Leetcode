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
    int maxDepth(TreeNode* root)  
    {  
        if(root==NULL)
        {
            return 0;
        }
        return find_max_depth(root);
    }  

    int find_max_depth(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        } 
        int lc=find_max_depth(root->left); 
        int rc=find_max_depth(root->right); 
        return 1+max(lc,rc);
    }

};