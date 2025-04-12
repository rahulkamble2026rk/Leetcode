class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.rbegin(),citations.rend());  //sort on the basis of the citation : 
         
         int maxi=0;
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]>=i+1)
            {
                maxi=i+1;
                cout<<"herre for "<<citations[i]<<" "<<i+1<<" "<<"maxi"<<maxi<<endl;
            } 
            else break;
        } 
        return maxi;
    }
};