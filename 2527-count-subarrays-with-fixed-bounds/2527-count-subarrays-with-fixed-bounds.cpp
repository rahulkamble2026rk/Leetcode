// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) 
//     {
//         long long ans=0; 
//         int n=nums.size(); 
//         for(int i=0;i<n;i++)
//         {    
//             int mini=1e9; 
//             int maxi=-1e9; 
//             for(int j=i;j<n;j++)
//             {
//                 if(nums[j]<mini)
//                 {
//                     mini=nums[j];
//                 } 
//                 if(nums[j]>maxi)
//                 {
//                     maxi=nums[j];
//                 } 
//                 if(maxi==maxK && mini==minK)
//                 {
//                     ans++;
//                 } 
//                 if(maxi>maxK || mini <minK)
//                 {
//                     break;
//                 }
//             }
//         } 
//         return ans;
//     }
// };

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        long long ans = 0;
        int n = nums.size();
        int minPos = -1, maxPos = -1, badPos = -1;

        for (int i = 0; i < n; i++) 
        {
            if (nums[i] < minK || nums[i] > maxK) 
            {
                badPos = i; // number out of [minK, maxK] range
            }
            if (nums[i] == minK) 
            {
                minPos = i;
            }
            if (nums[i] == maxK) 
            {
                maxPos = i;
            }
            int validStart = min(minPos, maxPos);
            if (validStart > badPos) 
            {
                ans += (validStart - badPos);
            }
        }
        return ans;
    }
};
