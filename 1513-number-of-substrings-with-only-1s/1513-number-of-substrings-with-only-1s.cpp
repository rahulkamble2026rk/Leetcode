class Solution {
public:
    int numSub(string s)  
    {
        //we have to return the no. of substrings will all character,  
        //give the contonuos marking sum=1 , upto the end: 
         
         long long sum=0;  
        const long long mod = 1e9 + 7;
         long long  ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
              sum+=1;
            } 
            else 
            {
               ans = (ans + count(sum)) % mod; 
                sum=0;
            }
        } 
        ans=(ans+count(sum))%mod;

        return ans;
    } 

    long long count(long long sum)
    { 
       return (sum * (sum + 1)) / 2;
    }
};