// class Solution {
// public:
//     int minSubarray(vector<int>& nums, int p)  
//     {
//         // we have to removet the smallest subarray (empty is also allowed) sum of teh remaining element is divisible by p, not allow to remove teh whole array 

//         //return the length of the smallest subarray that we need to remove or -1 if it is impossible. 

//         //I think we have to find the prefix here  
//         int sum=accumulate(nums.begin(),nums.end(),0); 
//         if(sum%p==0)
//         {
//             return 0;
//         } 

//         unordered_map<int,bool>stdmap; 
//         for(int i=0;i<nums.size();i++)
//         {
//             stdmap[nums[i]]=false;
//         } 

//         int mod=sum%p; 
//         //we have to find the whether any sum of this type is present or noy 
//         int mini=1e9;
//         for(int i=0;i<nums.size();i++)
//         {    
//             int j=i; 
//             int temp=mod;
//             while(temp>=0)
//             {
//                 temp=temp-nums[j]; 
//                 j++;
//             } 
//             if(temp==0) 
//             {
//                 mini=min(mini,j-i+1);
//             }
//         } 

//         return mini;

//     }
// }; 

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;

        // Step 1: Calculate total sum and target remainder
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }

        int target = totalSum % p;
        if (target == 0) return 0;  // The array is already divisible by p

        // Step 2: Use a hash map to track prefix sum mod p
        unordered_map<int, int> modMap;
        modMap[0] =
            -1;  // To handle the case where the whole prefix is the answer
        int currentSum = 0, minLen = n;

        // Step 3: Iterate over the array
        for (int i = 0; i < n; ++i) {
            currentSum = (currentSum + nums[i]) % p;

            // Calculate what we need to remove
            int needed = (currentSum - target + p) % p;

            // If we have seen the needed remainder, we can consider this
            // subarray
            if (modMap.find(needed) != modMap.end()) {
                minLen = min(minLen, i - modMap[needed]);
            }

            // Store the current remainder and index
            modMap[currentSum] = i;
        }

        // Step 4: Return result
        return minLen == n ? -1 : minLen;
    }
};