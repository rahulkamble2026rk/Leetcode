class Solution {
public:
    vector<vector<int>> generate(int n)  
    {
        if(n==1) 
        {
            return {{1}};
        } 
        else if(n==2)
        {
            return {{1},{1,1}};
        } 
        vector<vector<int>>vct;
        vct.push_back({1});
        vct.push_back({1,1}); 

        for(int i=2;i<n;i++)
        {
            vector<int>test=vct.back(); 

            vector<int>ans;  
            ans.push_back(test[0]); 
            int j=0;
            for( j=0;j<test.size()-1;j++)
            {
                ans.push_back(test[j]+test[j+1]); 
            } 
            ans.push_back(test[j]); 

            vct.push_back(ans);
        } 
        return vct;
    }
};