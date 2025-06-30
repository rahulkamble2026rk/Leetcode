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
    TreeNode* searchBST(TreeNode* root, int val)  
    {
        return check(root,val);
    } 
    TreeNode* check(TreeNode* root,int val)
    {
        if(root==NULL)
        {
            return NULL;
        } 
        if(root->val==val)
        {
            return root;
        }   
        TreeNode* rc=NULL; 
         TreeNode* lc=NULL;
        if(val>root->val)
        {
             rc=check(root->right,val); 
        } 
        else if(val<root->val)
        {
            lc=check(root->left,val); 
        }
       
        if(lc!=NULL) 
        {
            return lc;
        } 
        if(rc!=NULL)
        { 
            return rc;
        } 
        return NULL;
    }
};