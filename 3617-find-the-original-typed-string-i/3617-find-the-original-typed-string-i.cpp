class Solution {
public:
    int possibleStringCount(string word)  
    {
        map<char,int>stdmap;  
        map<char,int>stdmap2;
        for(int i=0;i<word.size();i++)
        {   
            if(stdmap.find(word[i])==stdmap.end())  //if not found;
            {   
                stdmap[word[i]]++;
            }  
            else if(stdmap.find(word[i])!=stdmap.end())  //found but the previos and current same then only add htat one .
            {  
                if(word[i-1]==word[i]) 
                {
                    stdmap2[word[i]]++;
                } 
            }
           
        } 

        int count=0; 
        for(const auto i:stdmap2)
        {
            count=count+i.second;  
        } 
        return count+1;
    }
};