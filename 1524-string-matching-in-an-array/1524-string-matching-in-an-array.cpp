class Solution {
public:
    vector<string> stringMatching(vector<string>& words)  
    {
        vector<string>vct; 
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(i!=j)
                {
                    if(words[j].find(words[i])!=string::npos)
                    {
                        vct.push_back(words[i]); 
                        break;
                    }
                }
            }
        } 
        // set<string>st(vct.begin(),vct.end()); 
        // vct.assign(st.begin(),st.end()); 
        return vct;
    }
};