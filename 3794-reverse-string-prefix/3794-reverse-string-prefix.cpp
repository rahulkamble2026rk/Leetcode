class Solution {
public:
    string reversePrefix(string s, int k)  
    {
        //we have to return the first , reverse k characters:   
        string str="";
        for(int i=0;i<k;i++)
        {
            str+=s[i];
        } 
 
        reverse(str.begin(),str.end()); 
        cout<<str<<endl; 

        for(int j=k;j<s.size();j++)
        {
            str+=s[j];
        }
        return str;
    }
};