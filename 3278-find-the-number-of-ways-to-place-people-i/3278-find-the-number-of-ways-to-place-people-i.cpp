// class Solution {
// public:
//     int numberOfPairs(vector<vector<int>>& points)  
//     {
//         int count=0; 

//          sort(points.begin(),points.end(),cmp);
//         for(int i=0;i<points.size();i++)
//         {
//             for(int j=i+1;j<points.size();j++)
//             {
//                 if(upper_left(i,j,points))
//                 {
//                     if(check_all(i,j,points)==true)
//                     {
//                         count++;
//                     }
//                 }
//             }
//         } 
//         return count;
//     } 

   
//     bool upper_left(int o,int s,vector<vector<int>>&points)
//     {
//          //now check whether one[0] is smaller or equal  than second[0]
//         vector<int>second=points[s]; 
//         vector<int>one=points[o];
//          if(second[0]>=one[0] && second[1]<=one[1])
//          {
//             return true;
//          } 
//          return false;
//     } 


//     static bool cmp(vector<int>one,vector<int>two)
//     {
//         if(one[0]>two[0])
//         {
//             return false;
//         } 
//         else if(one[0]==two[0])
//         {
//             if(one[1] > two[1])
//             {
//                 return false;
//             }
//         } 
//         return true;
//     } 

//      bool check_all(int i, int j, vector<vector<int>>& points)
//     {
//         for(int k = 0; k < points.size(); k++)
//         {
//             if(k == i || k == j) continue;

//             vector<int> middle = points[k];

          
//             if( (middle[0] > points[i][0] && middle[0] < points[j][0]) &&
//                 (middle[1] < points[i][1] && middle[1] > points[j][1]) )
//             {
//                 return false;
//             } 
//         } 
//         return true;
//     }
// };


class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count = 0;
        for (int i = 0; i < points.size(); i++)  
        {
            for (int j = 0; j < points.size(); j++)  
            {
                if (i == j) continue;
                if (upper_left(i, j, points) && check_all(i, j, points))  
                {
                    count++;
                }
            }
        }
        return count;
    }

    bool upper_left(int i, int j, vector<vector<int>>& points)  
    {
        vector<int> one = points[i]; 
        vector<int> second = points[j]; 
        return one[0] <= second[0] && one[1] >= second[1];
    }

    bool check_all(int i, int j, vector<vector<int>>& points)  
    {
        for (int k = 0; k < points.size(); k++)  
        {
            if (k == i || k == j) continue;
            vector<int> middle = points[k];
           
            if (middle[0] >= points[i][0] && middle[0] <= points[j][0] &&
                middle[1] <= points[i][1] && middle[1] >= points[j][1]) {
                return false;
            }
        }
        return true;
    }
};