class Solution {
public:
    string removeKdigits(string num, int k)
    {
        if(k==num.size())
        {
            return "0";
        }  
        stack<char>stk;
        for(int i=0;i<num.size();i++)
        {
            char x=num[i]; 
            while(!stk.empty()&&x-'0'<stk.top()-'0'&&k>0)
            {
                stk.pop(); 
                k--;
            } 
            stk.push(x);
        }  
         while(k>0)
        {
            stk.pop();
            k--;
        }
        string str="";
        while(!stk.empty())
        {
            str+=stk.top(); 
            stk.pop();
        }    
       
         reverse(str.begin(),str.end());
        while(str[0]=='0')
        {
            str.erase(0,1);
        }  
        if(str.empty())
        {
            str="0";
        } 
        return str;

    }
};