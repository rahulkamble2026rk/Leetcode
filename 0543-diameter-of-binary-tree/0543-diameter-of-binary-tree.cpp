class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root)  
    {  
        int Dia = 0;
        Diameter(root, Dia);  
        return Dia;
    }

    int Diameter(TreeNode* root, int& Dia)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lc = Diameter(root->left, Dia); 
        int rc = Diameter(root->right, Dia); 

        Dia = max(Dia, lc + rc); // update diameter

        return 1 + max(lc, rc); // return height
    }
};
