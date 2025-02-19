class Solution {
public:
    int change(int amount, vector<int>& coins) 
    { 
        int n=coins.size(); 
        //here they are interested in the to know that what are the possibilities so take the count directly  
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return count(amount,coins,n-1,dp);
    } 
    int count(int target,vector<int>&coins,int ind,vector<vector<int>>&dp)
    {
        if(target==0)
        {
            return 1;
        }  
        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }
        if(ind==0)
        {
            if(target%coins[ind]==0)
            {
                return 1;
            } 
            else
            {
                return 0;
            }
        } 

        int nottake=count(target,coins,ind-1,dp); 
        int take=0; 
        if(target>=coins[ind])
        {
            take=count(target-coins[ind],coins,ind,dp);
        } 
        return dp[ind][target]=take+nottake;
    }
};