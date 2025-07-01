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
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    { 
        int n=inorder.size(); 
        int postindex=n-1;
        return Build(postorder,inorder,0,n-1,postindex);
    } 
     
     TreeNode* Build(vector<int>&postorder,vector<int>&inorder,int start,int end,int &postindex)
     {
        if(start>end)
        {
            return NULL;
        } 
         
         TreeNode* T=new TreeNode(postorder[postindex]);
         postindex--; 
          
          if(start==end)
          {
            return T;
          } 
           
           int ind=find(inorder,start,end,T->val);
             
            T->right=Build(postorder,inorder,ind+1,end,postindex); 
           T->left=Build(postorder,inorder,start,ind-1,postindex);
           
           return T;
     } 
      
      int find(vector<int>vct,int start,int end,int x)
      { 
        int i=0;
        for( i=start;i<=end;i++)
        {
            if(vct[i]==x)
            {
               break; 
            }
        } 
        return i;
      }
};