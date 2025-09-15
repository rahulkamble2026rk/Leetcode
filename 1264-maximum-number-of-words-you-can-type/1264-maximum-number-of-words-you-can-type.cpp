class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) 
    {
       vector<pair<string,int>>stdmap; 
        int i=0; 
        int n=text.size(); 
        string str="";

        while(i<n)
        {
            if(text[i]==' ')
            {
                stdmap.push_back({str,0}); 
                str.clear();
            } 
            else 
            {
                str+=text[i]; 
            }  
            i++;     
        } 

        stdmap.push_back({str,0}); ; 

        
        int count=0;
         
            
            
                 for(int i=0;i<brokenLetters.size();i++)
                {   
                     for(auto &it:stdmap)
            { 
                    string str=it.first;   
                    if(it.second==0)
                    {
                        if(str.find(brokenLetters[i])!=string::npos )
                        {
                            it.second=1;
                        } 
                    } 
                   
            } 
            
         } 

         for(auto it:stdmap)
         {
            if(it.second==0)
            {
                count++;
            }
         } 
         return count;
    }
};