class Solution {
public:
    string processStr(string s)  
    {   
        string result="";
        for(int i=0;i<s.size();i++)
            {
                if(s[i]>='a' && s[i]<='z')
                {
                    result+=s[i]; 
                    // cout<<"result 1:"<<result;
                } 
                else if(s[i]=='*' && !result.empty())
                {
                    result.pop_back(); 
                    // cout<<"result 2:"<<result;
                } 
                else if(s[i]=='#' && !result.empty())
                {
                    result+=result; 
                    // cout<<"result :"<<result;
                } 
                 else if(s[i]=='%' && !result.empty())
                {
                   reverse(result.begin(),result.end()); 
                    // cout<<"result 1:"<<result;
                } 
            
            } 
        return result;
    }
};