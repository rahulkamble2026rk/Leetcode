class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)  
    {
        vector<int>vct; 
        for(const auto& str3:strs)
        {
            vct.push_back(str3.size());
        } 

        int maxsize=*min_element(vct.begin(),vct.end()); 
 
         string str="";
        for(int i=0;i<maxsize;i++)
        { 
            int flag=0;
            for(int j=0;j<strs.size()-1;j++) 
            {
                if(strs[j][i]!=strs[j+1][i])
                {
                    return str;
                }
            } 
            str+=strs[0][i];
        } 
        return str;

    }
};