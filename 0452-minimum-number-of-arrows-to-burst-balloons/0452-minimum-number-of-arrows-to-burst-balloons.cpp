class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)  
    {
        sort(points.begin(),points.end(),compare);  
        int minarrow=1;
        int lastarrow=points[0][1]; 
        for(int i=1;i<points.size();i++)
        {
            if(lastarrow<points[i][0]) //if the point is greater than the last point then we have to use the anther arrow
            {
                minarrow++; 
                lastarrow=points[i][1];
            }
        } 
        return minarrow;
    }
    static bool compare(vector<int>a,vector<int>b)
    {
        return a[1]<b[1];    //sort acc. to end 
    }
};