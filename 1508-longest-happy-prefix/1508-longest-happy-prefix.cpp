class Solution {
public:
    string longestPrefix(string s) 
    {
        string str="";   
        int maxi=0; 
        string ans=""; 
        for(int i=0;i<s.size();i++)
        {
            str+=s[i]; 
            if(s.starts_with(str)&&s.ends_with(str)&&ans.size()<str.size()&&str!=s)
            {
                 ans=str;
            }
        } 
        return ans;
    }
};