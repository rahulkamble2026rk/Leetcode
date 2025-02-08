
class Solution {
public:
    vector<int> countBits(int n)
    {   
        vector<int>vct; 
        vct.push_back(0);
        for(int i=1;i<=n;i++)
        {
            vct.push_back(__builtin_popcount(i));
        } 
        return vct;
    } 
    
};