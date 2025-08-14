class Solution {
public:
    string largestGoodInteger(string num)  
    {
        vector<string>vct;  
        string maxString;
        int n=num.size();
        for(int i=0;i<=n-3;i++)
        {
            if(check( num.substr(i,3) ))
            {  
                if(!vct.empty())
                {
                    string str=vct.back();  
                    vct.pop_back(); 
                    maxString=max(str,num.substr(i,3)); 
                    vct.push_back(maxString);
                }  
                else 
                {
                    maxString=num.substr(i,3); 
                    vct.push_back(maxString);
                }
 
            }
        }  
        if(!vct.empty()) 
        {
            return vct.back(); 
        }   
        return "";      


    } 

    bool check(string str)
    {
        if(str[0]==str[1] && str[1]==str[2] && str[0]==str[2])
        {
            return true;
        } 
        return false;
    }
};