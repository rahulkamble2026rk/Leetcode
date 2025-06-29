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
    bool isBalanced(TreeNode* root)  
    {
        if(root==NULL)
        { 
            return true;
        }  

        //traveerse and for the each node what is the height( height is nothing but the longest path from the root and upto the leaf node) 
         
          
        return traverse_check(root);

    }  
    bool traverse_check(TreeNode* root)
    {
        if(root==NULL)
        {
            return true;
        }
        int lc=find_max_depth(root->left); 
        int rc=find_max_depth(root->right);
        
        int val=abs(lc-rc); 
        if(val<=1 && traverse_check(root->left) && traverse_check(root->right)) 
        {
            return true;
        } 
        return false;
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