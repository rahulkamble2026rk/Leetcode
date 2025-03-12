class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
       int pmax=0;
       int nmax=0; 

       for(int i=0;i<nums.size();i++)
       {
        if(nums[i]>0)
        {
            pmax++;
        } 
        else if(nums[i]<0)
        {
            nmax++;
        }
       }     
       return max(pmax,nmax);
    }
};
