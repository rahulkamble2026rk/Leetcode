// class Solution {
// public:
//     int maxProfit(vector<int>& prices) 
//     {
//         int buy=1;  
//         vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
//         return maxprofit(prices,buy,0,dp);
//     } 
//     int maxprofit(vector<int>&prices,int buy,int ind,vector<vector<int>>&dp)
//     {
//         if(ind>=prices.size())  //when we purchase a share , but don't get chance to sell
//         {
//             return 0; 
//         } 
//         if(dp[ind][buy]!=-1)
//         {
//             return dp[ind][buy];
//         } 
//         int profit=0;
//         if(buy)
//         {
//             int take=-prices[ind]+maxprofit(prices,0,ind+1,dp); 
//             int nottake=0+maxprofit(prices,1,ind+1,dp); 
//             profit=max(take,nottake);
//         } 
//         else 
//         {
//             int take=prices[ind]+maxprofit(prices,1,ind+1,dp); 
//             int nottake=0+maxprofit(prices,0,ind+1,dp); 
//             profit=max(take,nottake);
//         } 
//         return dp[ind][buy]=profit;
//     }
// }; 

//By using the tabulzation(table , basse to top)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy=1;  
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0)); 
        
        int n=prices.size();
   
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int j=0;j<2;j++)
            {
                int profit=0;
                if(j==1)
                {
                    int take=-prices[ind]+dp[ind+1][0]; 
                    int nottake=0+dp[ind+1][1]; 
                    profit=max(take,nottake);
                } 
                else 
                {
                    int take=prices[ind]+dp[ind+1][1]; 
                    int nottake=0+dp[ind+1][0];
                    profit=max(take,nottake);
                } 
                dp[ind][j]=profit;
            }
        }  
         return dp[0][1];  
    }
       

};