class Solution {
public:
    bool isStrictlyPalindromic(int n) 
    {
        int number=n;  
        int i=0;
        for( i=2;i<=n-2;)
        {
            if(Given_string(i,n))
            { 
                i++;
            }
            else 
            {
                return false;
            }
        } 

        if(i==n-1)
        {
            return true;
        } 
        return false;
    } 

    bool Given_string(int i,int n)
    {
        string ans=""; 
        while(n>0)
        {
            ans+=(n%i); 
            n/=i;
        }  
        string temp=ans; 
        reverse(temp.begin(),temp.end());
        return ans==temp; 

    }
};