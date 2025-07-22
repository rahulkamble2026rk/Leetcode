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
    vector<int> inorderTraversal(TreeNode* root)  
    {
        //By using the Morris Traversal: 
        return morris(root);
    } 
    vector<int>morris(TreeNode* root)
    {
        TreeNode* curr=root; 
        vector<int>inorder; 

        //At the time of the coding think about the diagram and process , code will form
        while(curr!=NULL)
        {
            //case 1:if the current -> left is NULL then we will print the node or store 
            if(curr->left==NULL)
            {
                inorder.push_back(curr->val);  
                curr=curr->right;
            } 
            
            //case 2:if the current -> left is present then , move to the left side and go to the extreme right element and connect(link) the current and extreme right element right 

            else 
            {
                TreeNode* prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr)  //prev->right!=curr This condition is use for the avoid the same route
                {
                    prev=prev->right;
                } 
                if(prev->right==NULL)   //➕ Threading
                {
                    prev->right=curr; 
                    curr=curr->left;
                } 
                else     // \U0001f504 Remove thread and visit
                {
                    prev->right=NULL; 
                    inorder.push_back(curr->val); 
                    curr=curr->right;
                }
            }

        } 
        return inorder;
    }
};