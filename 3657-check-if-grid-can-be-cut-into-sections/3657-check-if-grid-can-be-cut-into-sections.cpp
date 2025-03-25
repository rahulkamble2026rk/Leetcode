class Solution { 
    #define pii pair<int,int>
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) 
    {
        vector<pii>ypoints,xpoints; 
        for(auto & rect:rectangles)
        {
            ypoints.push_back(make_pair(rect[1],1));  //start:1  
            ypoints.push_back(make_pair(rect[3],0));   //end : 0
            xpoints.push_back(make_pair(rect[0],1)); 
            xpoints.push_back(make_pair(rect[2],0));
        } 

        //sort 
        sort(xpoints.begin(),xpoints.end()); 
        sort(ypoints.begin(),ypoints.end()); 

        return (validatecuts(ypoints) || validatecuts(xpoints));
    }

    bool validatecuts(vector<pii>&points)
    {
       int lines=0; 
       int overlap=0; 
       for(int i=0;i<points.size();i++)
       {
        if(points[i].second==0) //if end comes 
        {
            overlap--;
        } 
        else 
        {  
            overlap++;
        } 

        if(overlap==0)
        {
            lines++;
        }
       } 
       return lines>=3;
    }
};
 

//  Algorithm: Sweep-line algorithm

// Entering a Rectangle: Increment overlap by +1

// Exiting a Rectangle: Decrement overlap by -1

// Same Coordinate Rule: If two points share the same coordinate, process the end point before the start point

// Valid Gap: When overlap becomes 0, a gap (potential cut) is identified