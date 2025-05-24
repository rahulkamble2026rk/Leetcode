class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) 
    {
        vector<int>vct; 
        for(int i=0;i<words.size();i++)
        {
            if(words[i].find(x)!=-1)
            { 
                vct.push_back(i);
            }
        } 
        return vct;
    }
};