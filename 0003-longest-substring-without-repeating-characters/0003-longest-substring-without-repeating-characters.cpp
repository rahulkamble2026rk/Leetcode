class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {  
        int maxi=0;
        for(int i=0;i<s.size();i++)
        {
            unordered_map<char,int>stdmap; 
            for(int j=i;j<s.size();j++)
            {
                 if (stdmap[s[j]] > 0)  
                 {
                    break;
                 }            
                    
                    stdmap[s[j]]=1; 
                    maxi=max(maxi,j-i+1);
                
            }
        } 
        return maxi;
    }
};