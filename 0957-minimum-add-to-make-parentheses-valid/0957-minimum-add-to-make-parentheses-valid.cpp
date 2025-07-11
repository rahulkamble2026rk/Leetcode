class Solution {
public:
    int minAddToMakeValid(string s)  
    {
        //  int sum=0; 
        // int maxi=0;
        // for(int i=0;i<s.size();i++)
        // {
        //     if(s[i]=='(')
        //     { 
        //         sum++;
        //         maxi=max(maxi,sum);
        //     }
        //     else if(s[i]==')')
        //     {
        //         sum--;
        //     }
        // } 
        // if(sum==0)
        // {
        //     return 0;
        // }
        // return maxi; 

        //by using the two stacks 
        stack<char>stk1;
        stack<char>stk2; 

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                stk1.push('(');
            } 
            else if(s[i]==')')
            {  
                if(!stk1.empty())
                {
                    if(stk1.top()=='(')
                    {
                      stk1.pop();
                    }
                } 
                 else 
                {
                    stk2.push(s[i]);
                }
                
            } 
            else 
            {
                stk2.push(s[i]);
            }
        } 

        return stk1.size()+stk2.size();
    }
};