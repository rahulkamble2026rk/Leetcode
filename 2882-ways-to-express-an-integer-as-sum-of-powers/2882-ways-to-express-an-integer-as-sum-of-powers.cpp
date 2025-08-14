class Solution {
public: 

    // int modulo=109 + 7 
     const int MOD = 1000000007;
    int numberOfWays(int n, int x)  
    {
        //as there is n, and x(as the power that we have to take) 
        //step1: foramtion of the vector which containg the values as the square of the numbers upto the n: 
        vector<int>vct; 
        for(int i=1;i<=n;i++)
        {   
             long long val = pow(i, x); 
             if(val>n)
             {
                break;
             }
            vct.push_back((int)val);
        }  

        // for(int i:vct)
        // {
        //     cout<<i<<" ";
        // }  
        vector<vector<int>>dp(vct.size()+1,vector<int>(n+1,-1) );
        return count_ways(vct,n,0,dp);
    } 

    int count_ways(vector<int>&vct,int n,int ind,vector<vector<int>>&dp)
    {   

        if(n==0)
        {   
            // cout<<"I am counted";
            return 1;
        }  
       
        if(ind>=vct.size())
        {
            return 0;
        }  

         if(dp[ind][n]!=-1)
        {
            return dp[ind][n];
        }

        //take it:  
        int take=0;
        if(n>=vct[ind])
        {
            take=count_ways(vct,n-vct[ind],ind+1,dp);
        } 
        int not_take=count_ways(vct,n,ind+1,dp); 
        return dp[ind][n]=((take+not_take)%MOD);
    }
};