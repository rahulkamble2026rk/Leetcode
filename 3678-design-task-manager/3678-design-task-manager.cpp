// class TaskManager {
// public: 
//     vector<vector<int>>vct;
//     TaskManager(vector<vector<int>>& tasks) 
//     {
//         vct=tasks;
//     }
    
//     void add(int userId, int taskId, int priority) 
//     {
//         vector<int>temp; 
//         temp.push_back(userId); 
//         temp.push_back(taskId); 
//         temp.push_back(priority); 
//         vct.push_back(temp);
//     }
    
//     void edit(int taskId, int newPriority) 
//     {
//         for(int i=0;i<vct.size();i++)
//             {
//                if(vct[i][1]==taskId)
//                {
//                    vct[i][2]=newPriority;
//                }
//             }
//     }
    
//     void rmv(int taskId) {
//         vct.erase(remove_if(vct.begin(), vct.end(),
//                             [taskId](const vector<int>& task) {
//                                 return task[1] == taskId;
//                             }),
//                   vct.end());
//     }

//     int execTop() {
//         if (vct.empty()) return -1;

       
//         auto it = max_element(vct.begin(), vct.end(),
//                               [](const vector<int>& a, const vector<int>& b) {
//                                   if (a[2] == b[2]) {
//                                       return a[1] < b[1]; 
//                                   }
//                                   return a[2] < b[2]; 
//                               });

//         int userId = (*it)[0];
//         int taskId = (*it)[1];
//         rmv(taskId); 
//         return userId;
//     }
// };

// /**
//  * Your TaskManager object will be instantiated and called as such:
//  * TaskManager* obj = new TaskManager(tasks);
//  * obj->add(userId,taskId,priority);
//  * obj->edit(taskId,newPriority);
//  * obj->rmv(taskId);
//  * int param_4 = obj->execTop();
//  */



class TaskManager {
private:
    unordered_map<int, vector<int>> taskMap;
    priority_queue<vector<int>> pq;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            taskMap[task[1]] = {task[0], task[2]};
            pq.push({task[2], task[1], task[0]});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        if (taskMap.find(taskId) != taskMap.end()) {
            int userId = taskMap[taskId][0];
            taskMap[taskId][1] = newPriority;
            pq.push({newPriority, taskId, userId});
        }
    }

    void rmv(int taskId) {
        if (taskMap.find(taskId) != taskMap.end()) {
            taskMap.erase(taskId);
        }
    }

    int execTop() {
        while (!pq.empty()) {
            vector<int> topTask = pq.top();
            pq.pop();
            int priority = topTask[0];
            int taskId = topTask[1];
            int userId = topTask[2];
            if (taskMap.find(taskId) != taskMap.end() && taskMap[taskId][1] == priority) {
                taskMap.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};