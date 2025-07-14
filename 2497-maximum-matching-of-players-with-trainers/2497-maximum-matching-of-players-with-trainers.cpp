class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
    int j=0;  
        int count=0; 
        sort(g.begin(),g.end()); 
        sort(s.begin(),s.end());
        for(int i=0;i<g.size() && j<s.size();)
        {    
            if(j<s.size() && g[i]<=s[j])
            {
                count++;  
                i++;
            }   
              j++;
            
        } 
        return count;
    }
};