class Solution {
public:
    int smallestValue(int n)  
    {
        if(is_prime(n))
        {
            return n;
        } 
 
        vector<int>prime(n+1,1); 

        for(int i=2;i*i<=n;i++)
        {
            if(prime[i]==1)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    prime[j]=0;
                }
            }
        }
        if(prime[n]==1)
        {
            return n;
        }   
        while(is_prime(n)==false)
        { 
            int sum=0,temp=n;
            while(temp>1)
            {
                for(int i=2;i<=temp;i++)
                {
                    if(temp%i==0)
                    {
                        sum+=i;
                        temp/=i;
                        i--;
                    }
                }
            } 

                if (sum == n)  
                {
                    return n;
                }
            n = sum; 
        }
       return n;
    } 
    bool is_prime(int num)
    {
        if(num<=1)
        {
            return false;
        } 
        if(num==2 || num==3)
        {
            return true;
        } 
        if(num%2==0 || num%3==0)
        {
            return false;
        } 
        for(int i=5;i*i<=num;i+=6)
        {
            if(num%i==0 || num%(i+2)==0)  //(6k-1) , (6k)
            {
                return false;
            }
        } 
        return true;
    }
};