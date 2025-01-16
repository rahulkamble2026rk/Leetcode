#define MOD 1000000007

class Solution {
public:
    long long modExp(long long base, long long exp, long long mod) 
    {
        long long result = 1;
        while (exp > 0) 
        {
            if (exp % 2 == 1) 
            { // If exp is odd
                result = (result * base) % mod;
            }
            base = (base * base) % mod; // Square the base
            exp /= 2;
        }
        return result;
    }
    
    int countGoodNumbers(long long n) 
    {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        
        long long first = modExp(5, even, MOD); // 5^even % MOD
        long long second = modExp(4, odd, MOD); // 4^odd % MOD
        
        return (int)((first * second) % MOD);
    }
};
