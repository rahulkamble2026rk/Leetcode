class Solution {
public:
    int countHomogenous(string s)  
    {
        //we have to count, first we have to sort the string: 
        // sort(s.begin(),s.end());   
        long long sum = 1;
        const long long mod = 1e9 + 7; 
         long long ans = 0;

        //zarvar tak chaltay tavar tak , sum and then count: 
         
        

         for(int i=0;i<s.size()-1;i++)
         {
            if(s[i]==s[i+1])
            {
                sum++;
            } 
            else
            {
                ans = (ans + count(sum)) % mod;  // <-- Fix added
                sum = 1;
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