// class Solution {
// public:
//     int maximumSum(vector<int>& nums) 
//     {
//         map<int,int>stdmap; 
//         for(int i=0;i<nums.size();i++)
//         {
//             stdmap[nums[i]]=sum(nums[i]);
//         } 
         
//         for(auto it:stdmap)
//         {
//             int first=it.first; 
//             int second=it.second;
//         }
//     } 

    // int sum(int num)
    // {
    //     int s=0; 
    //     while(num>0)
    //     {
    //         s+=num%10; 
    //         num/=10;
    //     } 
    //     return s;
    // }
// }; 

class Solution {
public:
    int maximumSum(vector<int>& nums) 
    {   
        unordered_map<int,vector<int>>digitmap; 
        for(int num:nums)
        {
            int digitsum=sum(num); 
            digitmap[digitsum].push_back(num);
        } 
        int maxi=-1; 
        for(auto it:digitmap)
        {
            int sumVal=it.first; 
            vector<int>values=it.second; 

            if(values.size()>1)
            {
                sort(values.rbegin(),values.rend()); 
                maxi=max(maxi,values[0]+values[1]);
            }
        }
        return maxi;
    }   

    int sum(int num)
    {
        int s=0; 
        while(num>0)
        {
            s+=num%10; 
            num/=10;
        } 
        return s;
    }
};