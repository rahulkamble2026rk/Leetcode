class Solution {
public:
    bool canConstruct(string s, int k)
    {   
        if(s.size()<k)
        {
            return false;
        }
        if(s.size()==k) 
        {
            return true;
        } 
        map<char,int>stdmap; 
        for(int i=0;i<s.size();i++)
        {
            stdmap[s[i]]++;
        } 
        
        int c=0;
        for(const auto& i:stdmap)
        {
            if((i.second)%2)
            {
                c++;
            }
        } 
        return c<=k;
    }
};