class Solution {
public:
    long long removeZeros(long long n)  
    {
        long long sum=0; 

        long long  mult=1; 
        while(n>0)
        {
            int rem=n%10; 

            if(rem!=0)
            {
                sum=sum+(rem*mult); 
                mult*=10;
            } 
            n/=10;
        } 

        return sum;
    }
};