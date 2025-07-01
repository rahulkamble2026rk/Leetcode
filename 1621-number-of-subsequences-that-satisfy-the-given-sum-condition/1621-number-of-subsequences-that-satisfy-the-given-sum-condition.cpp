class Solution {
public: 
    int MOD=1e9+7;
    int numSubseq(vector<int>& nums, int target)  
    {
        //In this problem the sequence does not matter because we just need to sott the no. which summation is less than or equal to the target.  

        sort(nums.begin(),nums.end());  

        int n=nums.size(); 
        vector<int>power(n+1); 
        precompute(power,n); 

        int l=0;
        int r=nums.size()-1;  
      
        int sequence=0;
        while(l<=r)
        {
            if(nums[l]+nums[r]>target)
            {
                r--;
            } 
            else 
            {
               //sequence+=(2^(r-l));  very imp property 
              // sequence+=pow(2,(r-l));this can give you tle,so use the precomputation  
               
               sequence=(sequence+power[r-l])%MOD;
                l++;
            }
        } 

    
        return sequence; 

    }    

    void precompute(vector<int>&power,int& n)
    {
        power[0]=1;  
        
        for(int i=1;i<=n;i++)
        {
            power[i]=(power[i-1]*2LL)%MOD;
        }
    }
};