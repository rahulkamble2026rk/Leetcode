class Solution {
public:
    int climbStairs(int n)  
    {   
        //distinct ways: total of the all occrances
        //can either one stair up or 2 and at the end their might be one 0   
        // 1.recursion fails due to tle
        //2.memoization:
         
        vector<int>dp(n+1,-1);
        return countstairs(dp,n);
    } 
    int countstairs(vector<int>&dp,int n)
    { 
        if(n==0)
        {
            return 1;
        } 
        if(n==1)
        {
            return 1;
        }  
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int onestep=countstairs(dp,n-1); 
        int twostep=countstairs(dp,n-2); 
        return dp[n]=onestep+twostep;
    }
};