// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) 
//     { 
//         int n=matrix.size(); 
//         int m=matrix[0].size();  
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         int mini=INT_MAX;
//         for(int i=0;i<m;i++)
//         {   
//             //cout<<"for "<<i<<"column"<<minifind(i,0,n,m,matrix,dp)<<endl;
//             mini=min(mini,minifind(0,i,n,m,matrix,dp));
//         } 
//         return mini;
//     } 
//     int minifind(int i,int j,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&dp)
//     {  
//         if(j<0 || j>=m)
//         {
//             return INT_MAX;
//         } 

//         if(i==n-1)
//         {
//             return matrix[i][j];
//         } 
         
//         if(dp[i][j]!=-1)
//         {
//             return dp[i][j];
//         }
//         int lde=minifind(i+1,j-1,n,m,matrix,dp); 
//         int dde=minifind(i+1,j,n,m,matrix,dp);  
//         int rde=minifind(i+1,j+1,n,m,matrix,dp);  
//         return dp[i][j]=matrix[i][j]+min({lde,dde,rde});
//     }
// }; 





//By usinf the tabulazation 
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) 
//     { 
//         int n=matrix.size(); 
//         int m=matrix[0].size();  
//         vector<vector<int>>dp(n,vector<int>(m,0)); 
//         for(int i=0;i<m;i++)
//         {
//             dp[0][i]=matrix[0][i];
//         }
       
//         for(int i=1;i<n;i++)
//         {   
//            for(int j=0;j<m;j++)
//            {    
//                 int lde=(j>0)?matrix[i][j]+dp[i-1][j-1]:1e9; 
//                 int rde=(j<m-1)?matrix[i][j]+dp[i-1][j+1]:1e9;  
//                 int dde=matrix[i][j]+dp[i-1][j];  
//                 dp[i][j]=min({lde,dde,rde});
//            }
//         } 

//         int mini=dp[n-1][0];
//         for(int j=1;j<m;j++)
//         {
//             mini=min(mini,dp[n-1][j]);
//         } 
//         return mini;
//     } 
    
        
     
// }; 



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    { 
        int n=matrix.size(); 
        int m=matrix[0].size();  
       vector<int>prev(n,-1);
        for(int i=0;i<m;i++)
        {
            prev[i]=matrix[0][i];
        }
       
        for(int i=1;i<n;i++)
        {      
            vector<int>curr(m,0);
           for(int j=0;j<m;j++)
           {    
                int lde=(j>0)?prev[j-1]:1e9; 
                int rde=(j<m-1)?prev[j+1]:1e9;  
                int dde=prev[j];  
                curr[j]=matrix[i][j]+min({lde,dde,rde});
           } 
           prev=curr;
        } 

        int mini=prev[0];
        for(int j=1;j<m;j++)
        {
            mini=min(mini,prev[j]);
        } 
        return mini;
    } 
    
        
    
};