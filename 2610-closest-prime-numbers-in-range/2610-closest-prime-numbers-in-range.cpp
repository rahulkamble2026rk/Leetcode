class Solution {
public:
    vector<int> closestPrimes(int left, int right)  
    {
        vector<int> vct;
        for (int i = left; i <= right; i++)  
        {
            if (is_prime(i) == true)  
            {
                vct.push_back(i);
            }
        }

        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1); 
        if(left==right||vct.empty())
        {
            return ans;
        }
        int mini = 1e9;
        for (int i = 0; i < vct.size() - 1; i++)  
        {
            if ((vct[i + 1] - vct[i]) < mini) 
            {
                mini = vct[i + 1] - vct[i];
                ans[0] = vct[i];
                ans[1] = vct[i + 1];
            }
        }
        return ans;
    }
    bool is_prime(int num)  
    {
        if (num <= 1)  
        {
            return false;
        }
        if (num == 2 || num == 3) 
        {
            return true;
        }
           
        if (num % 2 == 0 || num % 3 == 0) 
        {
            return false;
        }
            
        for (int i = 5; i * i <= num; i += 6)  
        {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }
};