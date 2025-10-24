class Solution {
public:
    int missingMultiple(vector<int>& nums, int k)  
    {
        int incre=1; 
        map<int,int>stdmap; 
        for(int i=0;i<nums.size();i++)
        {
            stdmap[nums[i]]++;
        } 

        //we have to return the smallest postive multiple k that is missing from nums 
           
            while(stdmap.count(k*incre)) 
            {
              incre++;
            } 

            return k*incre;   
    }
};