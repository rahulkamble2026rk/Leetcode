class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {  
        
         sort(intervals.begin(),intervals.end(),compare);  
         int count=1;
         int lasttime=intervals[0][1];   //this is the last occurance or the end of the itnercal
        for(int i=1;i<intervals.size();i++) 
        {
            if(intervals[i][0]>=lasttime)
            {
                lasttime=intervals[i][1];  
                count++;
            }
        } 
        return intervals.size()-count;
    } 

    static bool compare(vector<int>a,vector<int>b)
    {
        return a[1]<b[1];   //sort according to the ending or next term 
    }
};