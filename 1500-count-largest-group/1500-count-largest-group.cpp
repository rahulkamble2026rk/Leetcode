class Solution {
public:
    int countLargestGroup(int n)  
    {
        vector<vector<int>>vct(37); 
        int ans=0; 
        for(int i=1;i<=n;i++)
        {
            int sum=findsum(i); 
            vct[sum].push_back(i);
        } 
        int maxi=-10000000000; 
        for( vector<int>i:vct)
        {
            maxi=max(maxi,(int)i.size());
        } 
        for(vector<int>i:vct)
        {
            if((int)i.size()==maxi)
            {
                ans++;
            }
        } 
        return ans;
    } 
    int findsum(int n)
    { 
        int sum=0;
        while(n>0)
        {
            sum+=n%10; 
            n/=10;
        } 
        return sum;
    }
};