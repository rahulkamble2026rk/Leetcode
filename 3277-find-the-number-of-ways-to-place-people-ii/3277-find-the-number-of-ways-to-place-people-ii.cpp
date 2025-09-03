// class Solution {
// public:
  
//     int numberOfPairs(vector<vector<int>>& points) {
//        int count = 0;
//         for (int i = 0; i < points.size(); i++)  
//         {
//             for (int j = 0; j < points.size(); j++)  
//             {
//                 if (i == j) continue;
//                 if (upper_left(i, j, points) && check_all(i, j, points))  
//                 {
//                     count++;
//                 } 
              
//             }
//         }
//         return count;
//     }

//     bool upper_left(int i, int j, vector<vector<int>>& points)  
//     {
//         vector<int> one = points[i]; 
//         vector<int> second = points[j]; 
//         return one[0] <= second[0] && one[1] >= second[1];
//     }

//     bool check_all(int i, int j, vector<vector<int>>& points)  
//     {
//         for (int k = 0; k < points.size(); k++)  
//         {
//             if (k == i || k == j) continue;
//             vector<int> middle = points[k];
           
//             if (middle[0] >= points[i][0] && middle[0] <= points[j][0] &&
//                 middle[1] <= points[i][1] && middle[1] >= points[j][1])  
//                 {
//                    return false;
//                 }
//         }
//         return true;
//     }
// }; 

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int count = 0;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                if (upper_left(i, j, points) && check_all(i, j, points)) {
                    ++count;
                }
            }
        }
        return count;
    }

private:
    bool upper_left(int i, int j, const vector<vector<int>>& points) {
        return points[i][1] >= points[j][1];
    }

    bool check_all(int i, int j, const vector<vector<int>>& points) {
        for (int k = i + 1; k < j; ++k) {
            const vector<int>& middle = points[k];
            if (middle[0] >= points[i][0] && middle[0] <= points[j][0] &&
                middle[1] <= points[i][1] && middle[1] >= points[j][1]) {
                return false;
            }
        }
        return true;
    }
};