class Solution {
public:
    int minOperations(vector<int>& nums)  
    {
        int count1=0;   

        //Firstly count the all the ones and then n-count1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                count1++;
            }
        } 

        if(count1!=0) 
        {
            return n-count1;
        } 

        int mini=1e9; 

        for(int i=0;i<n-1;i++)
        {
            int gcd=nums[i]; 
            for(int j=i+1;j<n;j++)
            {
                gcd=__gcd(gcd,nums[j]); 
                if(gcd==1)
                {
                    mini=min(mini,j-i);
                }
            }
        } 

        if(mini==1e9)
        {
            return -1;
        } 
        return mini+(n-1);
    }
};