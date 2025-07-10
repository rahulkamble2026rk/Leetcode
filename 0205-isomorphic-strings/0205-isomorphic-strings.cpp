class Solution {
public:
    bool isIsomorphic(string s, string t)  
    {
        unordered_map<char,char>stdmap1; 
        unordered_map<char,char>stdmap2;
        for(int i=0;i<s.size();i++)
        {  
            if( stdmap1.find(s[i])!=stdmap1.end() )
            {
                if(stdmap1[s[i]]!=t[i])
                {
                    return false;
                }
            }  

            else 
            {
                stdmap1[s[i]]=t[i];
            }
            if(stdmap2.find(t[i])!=stdmap2.end() )
            {
                if(stdmap2[t[i]]!=s[i])
                {
                    return false;
                }
            } 
            else
            {
                stdmap2[t[i]]=s[i];
            }
            
            
        } 
        return true;
    }
};