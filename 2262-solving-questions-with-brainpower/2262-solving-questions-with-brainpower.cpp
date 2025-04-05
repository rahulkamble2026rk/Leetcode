class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int size=questions.size(); 
        vector<long long>dp(size,-1);
        return countpoints(size,questions,0,dp);
    } 
    long long countpoints(int size,vector<vector<int>>&questions,int ind,vector<long long>&dp)
    {
         
        if(ind>=size)
        {
            return 0;
        }  
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int points=questions[ind][0]; 
        int jump=questions[ind][1];
        long long take=points+countpoints(size,questions,ind+jump+1,dp); 
        long long nottake=countpoints(size,questions,ind+1,dp); 
        return dp[ind]=max(take,nottake);
    }
};