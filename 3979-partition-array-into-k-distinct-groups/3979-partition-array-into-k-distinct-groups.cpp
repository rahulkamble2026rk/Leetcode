class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) 
    {
        //1. zitna max no.of the occurace hai , we have to form that many number of groups 
        //2. the size of the array must be multiple of k  

        
        map<int,int>stdmap; 
        int maxi=0; 

        for(int i=0;i<nums.size();i++)
        {     
            stdmap[nums[i]]++; 
            if(maxi<stdmap[nums[i]])
            {
                maxi=stdmap[nums[i]];
            }
        } 
        int n=nums.size(); 
        if(nums.size()%k!=0 || (maxi*k)>n)
        {   
            return false;
        } 
        return true;

    }
};