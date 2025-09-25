// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) 
//     {
//         int m=triangle.size(); 
//         int n=triangle[0].size();  
//         vector<vector<int>>dp(m);  
//         for(int i=0;i<m;i++)
//         {
//             dp[i]=vector<int>(triangle[i].size(),-1);
//         } 
      
//         return minimumcount(0,0,m,triangle,dp);
//     } 
//     int minimumcount(int i,int j,int finalrow,vector<vector<int>>&triangle,vector<vector<int>>&dp)
//     {
//         if(i==finalrow-1)
//         {
//             return triangle[i][j];
//         } 
       
//         if(j>=triangle[i].size())
//         {
//             return 0;
//         }  

//          if(dp[i][j]!=-1)
//         {
//             return dp[i][j];
//         }  
        

//         int first=triangle[i][j]+minimumcount(i+1,j,finalrow,triangle,dp);  
//         // cout<<"I am first"<<first<<endl;
//         int second=triangle[i][j]+minimumcount(i+1,j+1,finalrow,triangle,dp);  
//         // cout<<"I am second"<<second<<endl;
//         int mini=min(first,second); 
//         // cout<<"I am going to add"<<mini<<endl;
//         return dp[i][j]=min(first,second);
//     }
// }; 


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m=triangle.size(); 
        int n=triangle[0].size();  
        vector<vector<int>>dp(m);  
        for(int i=0;i<m;i++)
        {
            dp[i]=vector<int>(triangle[i].size(),-1);
        } 
      

        for(int i=0;i<m;i++)
        {
            dp[m-1][i]=triangle[m-1][i];
        } 


        for(int i=m-2;i>=0;i--)    //as the memoization starts from  top->bottom but here tabulzation always work in the diff. manner so it will be in bottom->top 
        {
            for(int j=i;j>=0;j--)
            {
                int first=triangle[i][j]+dp[i+1][j]; 
                int second=triangle[i][j]+dp[i+1][j+1]; 
                dp[i][j]=min(first,second);
            }
        } 
        return dp[0][0];
    } 
   
};