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
    TreeNode* insertIntoBST(TreeNode* root, int val)  
    {
        if(root==NULL)
        {
            return new TreeNode(val);
        }
        insert(root,val); 
        return root;
    } 
    TreeNode* insert(TreeNode* root,int val)
    {
        if(root==NULL)
        {
            root=new TreeNode(val);  
            return root;
        } 
        if(val>root->val)   //means val is present at the  right side then move to the right side
        {
            root->right=insert(root->right,val); 
            return root;
        } 
        else if(val<root->val)
        {
            root->left=insert(root->left,val);  
            return root;
        } 

        return root;
    }
};