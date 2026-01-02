class Solution {
public:
    int repeatedNTimes(vector<int>& nums)  
    { 
        int n=nums.size(); 
        map<int,int>stdmap; 

        for(int i=0;i<nums.size();i++)
        {
            stdmap[nums[i]]++;
        } 

        //we have to dfind the such element which has the half than total elemenets 

        int ans=0;
        for(auto it:stdmap)
        {
            if(it.second==(n/2))
            {  
                ans=it.first;
                break;
            }
        } 

        return ans;
    }
};