class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy=1;   
        int n=prices.size();
       vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return maxprofit(prices,buy,0,dp,2);
    } 
    int maxprofit(vector<int>&prices,int buy,int ind,vector<vector<vector<int>>>&dp,int cap)
    {   
        if(ind>=prices.size())  //when we purchase a share , but don't get chance to sell
        {
            return 0; 
        }   
        if(cap==0)
        {
            return 0;
        } 

        if(dp[ind][buy][cap]!=-1)
        {
            return dp[ind][buy][cap];
        } 
        int profit=0;
        if(buy)
        {
            int take=-prices[ind]+maxprofit(prices,0,ind+1,dp,cap); 
            int nottake=0+maxprofit(prices,1,ind+1,dp,cap); 
            profit=max(take,nottake);
        } 
        else 
        {
            int take=prices[ind]+maxprofit(prices,1,ind+1,dp,cap-1);  //there is completion of the one transation 
            int nottake=0+maxprofit(prices,0,ind+1,dp,cap); 
            profit=max(take,nottake);
        } 
        return dp[ind][buy][cap]=profit;
    }
}; 