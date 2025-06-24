class Solution {
public:
    int longestPalindromeSubseq(string s)  
    {
        //longest pallindromic subsequene is nothing but that revese teh current string , and use that string as the another string, and then find the lcs 

        int size1=s.size(); 
        string p=s; 
        reverse(p.begin(),p.end());  
        vector<vector<int>>dp(size1+1,vector<int>(size1+1,-1));
        return countLongestPallindromic(size1,size1,s,p,dp)-1;   
    }  
    int countLongestPallindromic(int ind1,int ind2,string&first,string&second,vector<vector<int>>&dp)
    {   
        //Base condition
        if(ind1<0 || ind2<0)
        {
            return 0;
        } 
         
         //
         if(dp[ind1][ind2]!=-1)
         {
            return dp[ind1][ind2];
         }

        //If mathcing: 
        if(first[ind1]==second[ind2])
        {
            return 1+countLongestPallindromic(ind1-1,ind2-1,first,second,dp);
        } 
        //if not matching : then either reduce the either one index of 1st string or of another string 
        else
        {
            int take1=countLongestPallindromic(ind1-1,ind2,first,second,dp); 
            int take2=countLongestPallindromic(ind1,ind2-1,first,second,dp); 
            return dp[ind1][ind2]=max(take1,take2);
        }
    }
};