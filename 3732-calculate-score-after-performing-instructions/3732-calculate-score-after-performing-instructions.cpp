class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) 
    {
        long long initial_score=0;  
        int n=values.size(); 
        vector<bool>visited(n,false);
        for(int i=0;i<instructions.size();)
        {  
            if(i<0 || i>=n|| visited[i]==true)
            { 
                break; 
            }  
            visited[i] = true;
                if(instructions[i]=="jump")
                {
                    i=(i + values[i]);
                } 
                else if(instructions[i]=="add") 
                {
                    initial_score+=values[i]; 
                    i++;
                }   
            
        } 
        return initial_score;
    }
};