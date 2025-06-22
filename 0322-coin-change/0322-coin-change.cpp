class Solution {
public:
    int coinChange(vector<int>& coins, int W)  
    {   
        int n=coins.size();
        vector<vector<int>>dp(coins.size(),vector<int>(W+1,1e9)); 

    //1.Intialize the base condition : 
    //if the  
      for (int w = 0; w <= W; w++) 
      {
        if (w % coins[0] == 0) {
                dp[0][w] = w / coins[0]; // take coin[0] as many times as needed
            }  
        }

    //now interration .
  
     for(int i=1;i<n;i++)
     {
         for(int w=0;w<=W;w++)
         {
              int not_take=dp[i-1][w];  
              int take=1e9;
               if(coins[i]<=w) 
               {
                   take=1+dp[i][w-coins[i]];
               } 
               dp[i][w]=min(take,not_take);
         }
     } 
     int ans = dp[n - 1][W];
        return ans >= 1e9 ? -1 : ans;
    }
}; 

