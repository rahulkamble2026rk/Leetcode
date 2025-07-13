class Solution {
public:
    char kthCharacter(int k)  
    {
        string ans="a"; 
        string temp="b";
        while(ans.size()<k)
        {
            ans+=temp;  
            temp=update(temp);
        }  
        cout<<"ans:"<<ans;
        return ans[k-1];
    } 
    string update(string temp)
    {
        string temp2=temp; 
        for(int i=0;i<temp.size();i++)
        { 
            if(temp[i]=='z')
            {
                temp+='a';
            } 
            else 
            {
                temp2+=char(temp[i]+1);
            }
            
        } 
        return temp2;
    }
};