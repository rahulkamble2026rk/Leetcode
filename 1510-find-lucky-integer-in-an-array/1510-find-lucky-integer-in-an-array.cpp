class Solution {
public:
    int findLucky(vector<int>& arr)  
    {
        map<int,int>stdmap; 
        for(int i:arr)
        {
            stdmap[i]++;
        } 

        vector<pair<int,int>>vct(stdmap.begin(),stdmap.end()); 
        sort(vct.begin(),vct.end(),greater<>());
        for(int i=0;i<vct.size();i++)
        {
            if(vct[i].first==vct[i].second)
            {
                return vct[i].first;
            }
        } 
        return -1;
    }
};