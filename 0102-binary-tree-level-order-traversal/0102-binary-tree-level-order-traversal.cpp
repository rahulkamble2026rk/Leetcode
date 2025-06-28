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
    vector<vector<int>> levelOrder(TreeNode* root)  
    { 
        queue<TreeNode*>que1,que2;  
         vector<int>vct;
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        que1.push(root); 
        TreeNode* temp=root;  
       
        do 
        {
            while(!que1.empty())
            {
                temp=que1.front();  
                que1.pop(); 
                vct.push_back(temp->val);
                if(temp->left!=NULL)
                {
                    que2.push(temp->left);
                } 
                if(temp->right!=NULL)
                {
                    que2.push(temp->right);
                } 
                
            } 
            swap(que1,que2); 
            ans.push_back(vct);
            vct.clear();

        }while(!que1.empty());

        return ans;
    } 
};
    