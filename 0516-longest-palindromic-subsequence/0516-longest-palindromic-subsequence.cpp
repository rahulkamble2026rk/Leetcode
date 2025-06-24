class Solution {
public:
    int longestPalindromeSubseq(string s)  
    {
        //longest pallindromic subsequene is nothing but that revese teh current string , and use that string as the another string, and then find the lcs 

        int size1=s.size(); 
        string p=s; 
        reverse(p.begin(),p.end()); 
        return countLongestPallindromic(size1,size1,s,p)-1;   
    }  
    int countLongestPallindromic(int ind1,int ind2,string first,string second)
    {
        if(ind1<0 || ind2<0)
        {
            return 0;
        } 

        //If mathcing: 
        if(first[ind1]==second[ind2])
        {
            return 1+countLongestPallindromic(ind1-1,ind2-1,first,second);
        } 
        //if not matching : then either reduce the either one index of 1st string or of another string 
        else
        {
            int take1=countLongestPallindromic(ind1-1,ind2,first,second); 
            int take2=countLongestPallindromic(ind1,ind2-1,first,second); 
            return max(take1,take2);
        }
    }
};