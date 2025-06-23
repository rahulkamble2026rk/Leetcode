class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)  
    {   
        int size1=text1.size(); 
        int size2=text2.size(); 
        //1.recursion 
        //2.Memoization:  
        //3.Tabulzaton: 
        //4.Optimization: As here thre is use of the dp[i-1][j] ot dp[i][j-1] , so can do the optimization , 

        // vector<vector<int>>dp(size1+1,vector<int>(size2+1,0));   

        vector<int>prev(size2+1,0);  
        vector<int>curr(size2+1,0); 

        //intilization : take the base case of teh memoization and start : 
        // for(int i=0;i<size1;i++)
        // {
        //     dp[i][0]=0; 
        // } 

        // for(int j=0;j<size2;j++)
        // {
        //     dp[0][j]=0;
        // }
       
         for(int i=1;i<=size1;i++)
         {
            for(int j=1;j<=size2;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    curr[j]=1+prev[j-1];
                }  
                else 
                {
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
         } 
         return prev[size2];
        // return longestSub(size1-1,size2-1,text1,text2,dp);
    } 
    int longestSub(int ind1,int ind2,string s1,string s2, vector<vector<int>>&dp)
    {    

        if(ind1<0 || ind2<0)  //Base conditon is always on top
        {
            return 0;
        }
        //if Matching then  
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        if(s1[ind1]==s2[ind2])
        {
            return 1+longestSub(ind1-1,ind2-1,s1,s2,dp);
        } 

        //if not mathcing then there might be maximum sequence from either one string or another string ,so -1 from one and then from anohter , we reduce the index from the both string's then we might loss some of hte characters
        else 
        {
            int take1=longestSub(ind1-1,ind2,s1,s2,dp);  //decrease the index-1 from one string index
            int take2=longestSub(ind1,ind2-1,s1,s2,dp); 
            return dp[ind1][ind2]=max(take1,take2);  
        }

    }
};