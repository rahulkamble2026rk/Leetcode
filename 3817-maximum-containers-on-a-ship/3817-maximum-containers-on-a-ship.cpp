class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) 
    {  
        int max=n*n; 
        int ans=0;
        for(int i=max;i>=0;i--)
        {
            if(i*w<=maxWeight)
            {
                ans=i;
                break;
            }
        } 
        return ans;
    }
};