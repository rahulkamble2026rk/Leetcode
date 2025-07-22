// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums)  
//     {
//      vector<int>ans; 
//      int maxvalue=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             vector<int>vct; 
//              maxvalue=0; 
//             for(int j=i;j<nums.size();j++)
//             {
//                 if(find(vct.begin(),vct.end(),nums[j])==vct.end())
//                 {
//                     vct.push_back(nums[j]); 
//                     maxvalue+=nums[j];
//                 } 
//                 else 
//                 {
//                     ans.push_back(maxvalue); 
//                     break;
//                 }
//             } 
//              ans.push_back(maxvalue); 
//         } 
       
//         return *max_element(ans.begin(),ans.end());
//     }
// }; 


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums)  
    {
         int left=0; 
         int right=0;  
         int sum=0; 
         int maxi=0;
         unordered_set<int>seen;
         int size=nums.size(); 
         while(right<size)
         { 
            if(seen.find(nums[right])==seen.end())
            {
              seen.insert(nums[right]); 
              sum+=nums[right];
              maxi=max(maxi,sum); 
              right++;
            }
             else 
             { 
                seen.erase(nums[left]);
                sum-=nums[left];  
                left++;
        
             } 
         } 
         return maxi;
    }
};