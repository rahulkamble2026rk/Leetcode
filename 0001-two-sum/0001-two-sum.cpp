// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target)  
//     {
//         map<int,int>stdmap; 
//         for(int i=0;i<nums.size();i++)
//         {
//             stdmap.insert({nums[i],i});  
//         } 

//             vector<int>ans;
//         for(const auto it:stdmap)
//         {
//             int curr=it.first; 
//             int rem=target-curr; 
//             auto save=stdmap.find(rem);
//             if(save!=stdmap.end() && (it.se))
//             {    
//                 ans.push_back(it.second);  
//                 ans.push_back(save->second);
//                 break;
//             }
//         } 
//         return ans;
//     }
// };    //This Approach might tendds to error due to the duplicated entries ,so use the unordered_ map. 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)  
    { 
        unordered_map<int,int>indexMap; 

        for(int i=0;i<nums.size();i++)
        {
            int rem=target-nums[i]; 

            if(indexMap.count(rem))
            {
                return {indexMap[rem],i};
            } 

            indexMap[nums[i]]=i;
        } 
        return {};
     } 
};