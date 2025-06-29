class Solution {
public:
    int maxPathSum(TreeNode* root)  
    {
        int sum = INT_MIN; 
        maxsum(root, sum); 
        return sum;
    } 

    int maxsum(TreeNode* root, int& sum)
    {
        if (root == NULL) return 0; 

        int lc = maxsum(root->left, sum); 
        int rc = maxsum(root->right, sum);

        int left = max(0, lc);
        int right = max(0, rc); 

        int total = root->val + left + right; 
        sum = max(sum, total); 

        // Return the max gain including current node and one child (left or right)
        return root->val + max(left, right);
    }
};
