class Solution {
public:
    int distributeCandies(vector<int>& candyType) 
    {
        int n=candyType.size()/2; 
        set<int>st(candyType.begin(),candyType.end()); 
        if(st.size()<n)
        {
            return st.size();
        } 
        return n;
    }
};