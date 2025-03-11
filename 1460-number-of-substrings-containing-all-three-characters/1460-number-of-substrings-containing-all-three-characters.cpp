
class Solution 
{
public:
    int numberOfSubstrings(string s) 
    {
        int r=0; 
        int l=0;  
        string str="";
        vector<int>vct(3,-1); 
        int count=0;  
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            vct[s[i]-'a']=i; 
            if(vct[0]!=-1 && vct[1]!=-1 && vct[2]!=-1)
            {
                count=count+(1+min({vct[0],vct[1],vct[2]}));
            }
        } 
        return count;
    }
};