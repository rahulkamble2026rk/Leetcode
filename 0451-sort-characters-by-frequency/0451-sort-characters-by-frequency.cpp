class Solution {
public:
    string frequencySort(string s)  
    {
        map<char,int>stdmap; 
        for(int i=0;i<s.size();i++)
        {
            stdmap[s[i]]++;
        } 

         vector<pair<char, int>> freqVec(stdmap.begin(), stdmap.end()); 

        sort(freqVec.begin(),freqVec.end(),cmp);  
        string ans=""; 

        for(auto it:freqVec)
        {  
            for(int i=1;i<=it.second;i++)
            {
                ans+=it.first;
            }
            
        } 
        return ans;
    } 

    static bool cmp(pair<char,int>p1,pair<char,int>p2)
    {
        return p1.second>p2.second;
    }
};