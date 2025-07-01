// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) 
//     {
//         TreeNode* root=new TreeNode(nums[nums.size()/2]); 
//         int left=(nums.size()/2)-1; 
//         int right=(nums.size()/2)+1; 
         
//         while(left>0 && right>(nums.size())/2)
//         {
//             root->left=create_node(nums[left]);  
//             left--;
//             root->right=create_node(nums[right]);   
//             right--;
//         }   

//         while(left>0)
//         {
//             root->left=create_node(nums[left]);  
//             left--;
//         }   
//         while(right>(nums.size()/2))
//         {
//             root->right=create_node(nums[right]);   
//             right--;
//         }

//         return root;
//     } 

//     TreeNode* create_node(int node)
//     {
//         TreeNode* p=new TreeNode(node); 
//         return p;
//     }
// }; 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_tree(nums, 0, nums.size() - 1);
    }

    TreeNode* build_tree(vector<int>& nums, int low, int high) {
        if (low > high) return nullptr;

        int mid = (low + high) / 2;
        TreeNode* root = create_node(nums[mid]);

        root->left = build_tree(nums, low, mid - 1);
        root->right = build_tree(nums, mid + 1, high);

        return root;
    }

    TreeNode* create_node(int val) {
        TreeNode* p = new TreeNode(val);
        return p;
    }
};
