class Solution {
public: 
static const long long MOD = 1000000007;
    int numOfWays(int n)  
    {
        
    long long A = 6;  // Type A ways for row 1
    long long B = 6;  // Type B ways for row 1

    for (int i = 2; i <= n; i++)
    {
        long long newA = (2 * A + 2 * B) % MOD;
        long long newB = (2 * A + 3 * B) % MOD;

        A = newA;
        B = newB;
    }

 return (A + B) % MOD;
    }
};