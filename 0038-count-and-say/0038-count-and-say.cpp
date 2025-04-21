class Solution {
public:
    string countAndSay(int n)  
    {   
        string ans2="";
         ans(1,n,"1",ans2); 
         return ans2;
    } 
    void ans(int i,int n,string str,string &str2)
    {
        if(i==n)
        { 
            str2=str;
            return;
        } 
        map<char,int>stdmap; 
        for(int i=0;i<str.size();i++)
        {
            stdmap[str[i]]++;
        } 

        string newstring=""; 
        int count = 1;

        for (int j = 0; j < str.size(); j++)  
        {
            if (j+1<str.size() && str[j] == str[j+1])  
            {
                count++;
            }  
            else  
            {
                newstring += to_string(count);
                newstring += str[j];
                count = 1;
            }
        }
        ans(i+1,n,newstring,str2);
    }
};