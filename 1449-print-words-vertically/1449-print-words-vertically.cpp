class Solution {
public:
    vector<string> printVertically(string s) 
    { 
        vector<string>vct; 
        string st=""; 
        int maxi=0;
        for(int i=0;i<s.size();i++)
        { 
            if(s[i]==' ')
            {
                vct.push_back(st);  
                int size=st.size();
                maxi=max(maxi,size); 
                st.clear(); 
            } 
            else 
            {
                st+=s[i];
            }  
        } 
        vct.push_back(st);   
        int size=st.size();
        maxi=max(maxi,size);  
        for(int i=0;i<vct.size();i++)
        {
            if(vct[i].size()<maxi)
            {
                while(vct[i].size()<maxi)
                {
                    vct[i].push_back(' ');
                } 
               
            }
        } 
    
         vector<string>ans; 
             
             int i=0;
            while(i<maxi)
            { 
                string str="";
                for(int j=0;j<vct.size();j++)
                {
                    str+=vct[j][i];
                }    
               str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);  
               ans.push_back(str);
               i++;
            }
             
            return ans;
    }
};