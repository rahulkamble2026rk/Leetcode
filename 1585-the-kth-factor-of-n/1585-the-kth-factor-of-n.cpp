class Solution {
public:
    int kthFactor(int n, int k)  
    {
        vector<int>vct;
         for(int i=1;i<=n;i++)
         {
            if(n%i==0)
            {
                vct.push_back(i);
            }
         } 
         if(vct.size()<k)
         {
            return -1;
         } 
         return vct[k-1];
    }
};