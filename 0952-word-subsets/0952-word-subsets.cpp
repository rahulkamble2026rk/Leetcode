class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {  
        vector<string>vct;
        unordered_map<char,int>maxoccur;
        for(int i=0;i<words2.size();i++)
        {
            pass(words2[i],maxoccur);
        }  
        for(const auto&i:maxoccur)
        {
            cout<<i.first<<endl;
        }
        for(int i=0;i<words1.size();i++)
        {
            if(check(words1[i],maxoccur))
            {
                vct.push_back(words1[i]);
            }
        } 
        return vct;
        
    } 
    void pass(string vct,unordered_map<char,int>&maxoccur)
    {
        unordered_map<char,int>stdmap; 
        for(int i=0;i<vct.size();i++)
        {
            stdmap[vct[i]]++; 
            if(maxoccur[vct[i]]<stdmap[vct[i]])
            {
                maxoccur[vct[i]]=stdmap[vct[i]];
            }
        } 
      
    } 
    bool check(string word,unordered_map<char,int>maxoccur)
    {
         unordered_map<char,int>temp; 
         for(int i=0;i<word.size();i++)
         {
            temp[word[i]]++;
         } 
        for(const auto& [ch, freq]:maxoccur) 
         {
            if(temp[ch] < freq)
            {
                return false;
            }
        }  
        return true;
         
    }
};