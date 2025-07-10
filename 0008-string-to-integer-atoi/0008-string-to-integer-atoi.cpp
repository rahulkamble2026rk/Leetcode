class Solution {
public:
    int myAtoi(string s)  
    {
        //1.remove leading the whitespaces
        //2.remove the sign  
        //3.read the integer by skipping the leading zero's util the nonzero, or at the end if no one is present then keep the 0 
        //4.if the number is greater than the range then do the roundoff the number 

        while(s[0]==' ')
        {
            s.erase(0,1);
        } 

        stack<char>stk;
       
        if(s[0]=='-' || s[0] == '+')
        {
           stk.push(s[0]); 
           s.erase(0,1);
        }  

        while(s[0]=='0')
        {
            s.erase(0,1);
        } 

        string ans=""; 
        int i=0;
        while(i<s.size())
        {  
            if(s[i]>='0' && s[i]<='9')
            {
                ans+=s[i];  
                i++;
            } 
            else 
            {
                break;
            }  
        }   
      long long num = 0;
        for (int j = 0; j < ans.size(); j++)
        {
            num = num * 10 + (ans[j] - '0');
            if (!stk.empty() && stk.top() == '-' && -num < INT_MIN)
                return INT_MIN;
            if ((stk.empty() || stk.top() == '+') && num > INT_MAX)
                return INT_MAX;
        }

       if(!stk.empty() && stk.top()=='-')
        {
            return -num;
        }  
        return num;

    }
};