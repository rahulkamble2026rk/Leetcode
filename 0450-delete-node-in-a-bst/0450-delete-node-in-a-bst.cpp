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


  //In deletion there are manily three conditions are present: 
        //1.Node with leaf node : here we can directly delete the node , can return the NULL 
        //2.Node with signal node: here we cannot direclty delete the node, because there is presence of the child , so we hace to store the child as well and we have to link that child with the parent of the targeted deleted node  

        //3. If there are two childs are present -> findmin(from right of the node) -> replace the value of the targetd deleted node with the minimum of the right side , and then delete that minimum right side partwala node  


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key)  
    {  
        if(root==NULL || search(root,key)==false)
        {
            return root;
        }
       return delete_node(root,key);
    }  

    bool search(TreeNode* root, int key)
    {
        if(root==NULL)
        {
            return false;
        } 
        if(root->val==key)
        {
            return true;
        } 
       
       bool lc=search(root->left,key); 
       bool rc=search(root->right,key); 
       return (lc||rc);
    } 

    TreeNode* delete_node(TreeNode* T,int key)
    {   
        if (key < T->val) {
            T->left = delete_node(T->left, key);
            return T;
        }
        if (key > T->val) {
            T->right = delete_node(T->right, key);
            return T;
        }
        if(T->left==NULL && T->right==NULL)
        {
            delete T; 
            return NULL;   //leaf Node , directly get deleted
        } 

        else if(T->left==NULL)   //node with signal child we don't to loose it so we are storing and returning.
        {
            TreeNode* p=T->right; 
            delete T; 
            return p;
        } 
        else if(T->right==NULL)
        {
            TreeNode* p=T->left; 
            delete T; 
            return p;
        }  

        else
        {
            TreeNode* p=findmin(T->right); 

            T->val=p->val; 
            T->right=delete_node(T->right,p->val); 
            
        } 
        return T;
    }  

    TreeNode* findmin(TreeNode* T)   //finding the minimum
    {
       while(T->left!=NULL)
       {
            T=T->left;
       }  
       return T;
    }

};