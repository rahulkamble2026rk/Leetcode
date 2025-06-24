class Solution {
public:
    int longestPalindromeSubseq(string s)  
    {
        //longest pallindromic subsequene is nothing but that revese teh current string , and use that string as the another string, and then find the lcs 

        int size1=s.size(); 
        string p=s; 
        reverse(p.begin(),p.end());   

        //tabilzation:
        vector<vector<int>>dp(size1+1,vector<int>(size1+1,0)); 

        for(int i=0;i<=size1;i++)
        {
            dp[i][0]=0;
        } 

        for(int j=0;j<=size1;j++)
        {
            dp[0][j]=0;
        }  


        //Always rember if the memo -> n-1 to 0 then tabulzation is from 0 to n;  

        for(int i=1;i<=size1;i++)
        {
            for(int j=1;j<=size1;j++)
            {
                if(s[i-1]==p[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                } 
                else 
                {
                    int take1=dp[i-1][j];
                    int take2=dp[i][j-1]; 
                    dp[i][j]=max(take1,take2);
                }
            }
        } 


        // for(int i=0;i<=size1;i++)
        // {
        //     for(int j=0;j<=size1;j++)
        //     {
        //         cout<<"dp["<<i<<"]["<<j<<"] => "<<dp[i][j]<<" , ";
        //     } 
        //     cout<<endl;
        // }
        // return countLongestPallindromic(size1-1,size1-1,s,p,dp);    
        return dp[size1][size1];
    }  
    // int countLongestPallindromic(int ind1,int ind2,string&first,string&second,vector<vector<int>>&dp)
    // {   
    //     //Base condition
        
    //      //
    //      if(dp[ind1][ind2]!=-1)
    //      {
    //         return dp[ind1][ind2];
    //      }

    //     //If mathcing: 
    //     if()
    //     {
    //         return 1+countLongestPallindromic(ind1-1,ind2-1,first,second,dp);
    //     } 
    //     //if not matching : then either reduce the either one index of 1st string or of another string 
    //     else
    //     {
    //         int take1=countLongestPallindromic(ind1-1,ind2,first,second,dp); 
    //         int take2=countLongestPallindromic(ind1,ind2-1,first,second,dp); 
    //         return dp[ind1][ind2]=max(take1,take2);
    //     }
    // }
};