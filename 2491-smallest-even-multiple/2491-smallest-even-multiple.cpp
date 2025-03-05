class Solution {
public:
    int smallestEvenMultiple(int n) 
    {
            
        if(n%2==0) 
        {
            
        int small;
        for(int i=n;i>=1;i--) 
        {
            if(i%2==0 && i%n==0)
            {
                small=i;
            }
        } 
        return small; 
        } 
        else
        {
            return 2*n;
        }
    }
};