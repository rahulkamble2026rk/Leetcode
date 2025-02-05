class Solution {
public:
    bool areAlmostEqual(string s1, string s2)  
    {   
        
        map<char,int>stdmap1; 
        map<char,int>stdmap2; 
        for(char c:s1)
        {
            stdmap1[c]++;
        } 
        for(char c:s2)
        {
            stdmap2[c]++;
        } 
        if(stdmap1!=stdmap2)
        {
            return false;
        }
        if(s1.size()!=s2.size())
        {
            return false;
        } 
        
        if(s1==s2)
        { 
            return true;
        } 
        else
        {   
            int count=0;
            for(int i=0;i<s1.size();i++)
            {        
                if(count>2)
                {
                    return false;;
                }
                if(s1[i]!=s2[i])
                {
                    count++;
                }
            }  
            
            if(count>2)
                {
                    return false;;
                }
              
           
        } 
         return true; 
    }
};