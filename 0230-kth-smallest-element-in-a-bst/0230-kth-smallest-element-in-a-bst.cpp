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
    int kthSmallest(TreeNode* root, int k)  
    {
        deque<TreeNode*>dq; 
        traverse_store(dq,root);  
        TreeNode* t=dq[k-1];
        return t->val;

    } 
    void traverse_store(deque<TreeNode*>&stk,TreeNode* root)
    {  
        if(root==NULL)
        {
            return;
        }
       
       traverse_store(stk,root->left);
       stk.push_back(root);  
       traverse_store(stk,root->right);

    }
};