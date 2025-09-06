// class Solution {
// public:
//     int numSquares(int n) 
//     {
//         vector<int>store;  
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         for(int i=1;i*i<=n;i++)
//         {
//             store.push_back(i*i);
//         } 

//         sort(store.rbegin(),store.rend()); 

//         return min_step(0,store,n,dp);
//     } 

//     int min_step(int ind,vector<int>&store,int num,vector<vector<int>>&dp)
//     {
//         if(ind>=store.size())
//         {
//             return 1e9;
//         } 
//         if(dp[ind][num]!=-1)
//         {
//             return dp[ind][num];
//         }
//         if(num==0)
//         {
//             return 0;
//         }  

//         int take=1e9; 
//         if(num>=store[ind])
//         {
//             int res=min_step(ind,store,num-store[ind],dp); 
//             if(res!=1e9)
//             {
//                 take=1+res;
//             }
//         } 

//         int not_take=min_step(ind+1,store,num,dp); 

//         return dp[ind][num]=min(take,not_take);
//     }
// };


class Solution {
public:
    int numSquares(int n) 
    {
        vector<int>store;  
        
        for(int i=1;i*i<=n;i++)
        {
            store.push_back(i*i);
        } 

        sort(store.rbegin(),store.rend());   
        int m=store.size(); 

        vector<vector<int>>dp(m+1,vector<int>(n+1,1e9));


        //setting the base case is that if the num=0 then answer=0;  

        for(int i=0; i<=m;i++)
        {
            dp[i][0]=0;
        } 


        //reverse from the memoization:

        for(int ind=m-1;ind>=0;ind--)
        {
            for(int num=1;num<=n;num++)

            {
                int take=1e9; 
                if(num>=store[ind])
                {
                    take=1+dp[ind][num-store[ind]];
                } 

                int not_take=dp[ind+1][num]; 
                dp[ind][num]=min(take,not_take);
            }
        }
        return dp[0][n];
    } 

    
};