// class Solution {
// public:
//     long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) 
//     {
//         int ans=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             //unordered_map<int,int>stdmap; 
//             int count=0; 
//             int cnt=0;
//             for(int j=i;j<nums.size();j++)
//             {
//                 if(nums[j]%modulo==k)
//                 {
//                     count++;
//                 } 
//                 if(count%modulo==k)
//                 {
//                     cnt++;
//                 }
//             } 
//              ans+=cnt;
//         } 
//         return ans;
//     }
// }; 


class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) 
    { 
        long long ans=0; 
        unordered_map<long long ,long long>prefixcount; 
        prefixcount[0]=1;   //Intilzaize for empty prefix; 

        long long prefix=0; 
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%modulo==k)
            {
                prefix++;
            }  
            long long target = ((prefix % modulo - k) % modulo + modulo) % modulo;
            ans += prefixcount[target];

            // Update the prefix sum count
            prefixcount[prefix % modulo]++;

        } 
        return ans;
    }
};