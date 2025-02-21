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
class FindElements {
public: 
TreeNode* finalroot;
    FindElements(TreeNode* root) 
    {   
        if(root==NULL)
        {
            return;
        }
        int val=root->val;  
        if(val!=-1)
        {
            traverse(root,root->val);
        } 
        else
        {   
            val=0;
            traverse(root,val);
        }
        finalroot=root;
    }  

    void traverse(TreeNode* root,int val)
    {
        if(root==NULL)
        {
            return;
        } 
        if(root->val==-1)
        {
            root->val=val;
        } 
        if(root->left!=NULL)
        {   
            if(root->left->val==-1)
            {
                traverse(root->left,((root->val)*2)+1);
            } 
            else
            {
                traverse(root,root->val);
            }  
        } 

        if(root->right!=NULL)
        {
            if(root->right->val==-1)
            {
                traverse(root->right,((root->val)*2)+2);
            } 
            else
            {
                traverse(root,root->val);
            }
        }
    }
    
    bool find(int target) 
    {   
        int flag=0;
       traversefind(finalroot,target,flag);
        return (flag==1?true:false);
    }  

    void traversefind(TreeNode* root,int target,int& flag)
    {
        if(flag==1 ||root==NULL)
        {
            return;
        }  
        if(root->val==target)
         {
            flag=1; 
            return;
         }
        traversefind(root->left,target,flag); 
        traversefind(root->right,target,flag);
    }


};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */