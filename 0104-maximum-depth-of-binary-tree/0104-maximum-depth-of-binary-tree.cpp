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
// class Solution {
// public:
//     int maxDepth(TreeNode* root)  
//     {  
//         if(root==NULL)
//         {
//             return 0;
//         } 

//         return find_max_depth(root);
//     }  

//     int find_max_depth(TreeNode* root)
//     {
//         if(root==NULL)
//         {
//             return 0;
//         } 
//         int lc=find_max_depth(root->left); 
//         int rc=find_max_depth(root->right); 
//         return 1+max(lc,rc);
//     }

// }; 

  
  class Solution {
public:
    int maxDepth(TreeNode* root)  
    {  
        //2.By using the level order traversal: 
        queue<TreeNode*>que1; 
        queue<TreeNode*>que2;   
        if(root==NULL)
        {
            return 0;
        }
        que1.push(root); 
        int count=0;  
        do
        {
            while(!que1.empty())
            {
                TreeNode* T=que1.front(); 
                que1.pop(); 
                
                if(T->left!=NULL)
                {
                    que2.push(T->left);
                } 

                if(T->right!=NULL)
                {
                    que2.push(T->right);
                } 
            } 
            swap(que1,que2);
            count++;
        }while(!que1.empty()); 
        return count;
    }
  };