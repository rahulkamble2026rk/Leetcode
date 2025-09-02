// class Solution {
// public:
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
//     {
//         //classes where , classes[i]=[passi , totali] -> the student actual will get pass and total number of students in that ith class 
//         //extraStudents are brillent students that are gurranted pass , we have to assign each brillent to class , so the maximize the average pass ratio across all classes
//         //pass ratio=no. of pass student / total number of students  
//         // average pass ratio = sum of pass ratios of all classes/no.of classes:  

//         //step1: sort the array , according to teh lowest diff, if teh diff is the same then  


//         vector<pair<int,int>>store; 
//         for(int i=0;i<classes.size();i++)
//         {
//             store.push_back({classes[i][1]-classes[i][0],i});
//         } 

//         sort(store.begin(),store.end(),cmp);

//         for(int )

//     } 

//     static bool cmp(pair<int,int>One,pair<int,int>Two)
//     {  
//         int diff1=One.second-One.first; 
//         int diff2=Two.second-Two.first;
//         if(diff1>diff2)
//         {
//             return false;
//         } 
//         else if(diff1==diff2)
//         {
//             if(One.first>Two.first || One.second>Two.second)
//             {
//                 return false;
//             }
//         } 
//         return true;
//     }
// }; 

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda to calculate the gain of adding an extra student
        auto calculateGain = [](int passes, int totalStudents) {
            return (double)(passes + 1) / (totalStudents + 1) -
                   (double)passes / totalStudents;
        };

        // Max heap to store (-gain, passes, totalStudents)
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto& singleClass : classes) {
            maxHeap.push({calculateGain(singleClass[0], singleClass[1]),
                          {singleClass[0], singleClass[1]}});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto [currentGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            int passes = classInfo.first;
            int totalStudents = classInfo.second;
            maxHeap.push({calculateGain(passes + 1, totalStudents + 1),
                          {passes + 1, totalStudents + 1}});
        }

        // Calculate the final average pass ratio
        double totalPassRatio = 0;
        while (!maxHeap.empty()) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            totalPassRatio += (double)classInfo.first / classInfo.second;
        }

        return totalPassRatio / classes.size();
    }
};