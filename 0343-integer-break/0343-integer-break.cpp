class Solution {
public:
    int integerBreak(int n)  
    {   
        //This is the Problem of the unbounded knapsack
        vector<int>vct; 
        for(int i=1;i<n;i++)
        {
            vct.push_back(i); 
        } 
        return maxProduct(vct,n,vct.size()-1);
    } 

    int maxProduct(vector<int>&vct,int Target,int ind) 
    {    
        if(Target==0)
        {
            return 1;
        }
        if(ind<0)
        {
           return 0;
        } 
        int not_take=0+maxProduct(vct,Target,ind-1);  
        int take=0;
        if(vct[ind]<=Target)
        {
            take=vct[ind]*maxProduct(vct,Target-vct[ind],ind);
        } 
        return max(take,not_take);
    }
};