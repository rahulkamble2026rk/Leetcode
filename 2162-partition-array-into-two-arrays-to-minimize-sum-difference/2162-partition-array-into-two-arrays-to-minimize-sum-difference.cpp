// class Solution {
// public:
//     int minimumDifference(vector<int>& arr) {   
//         int totSum = accumulate(arr.begin(), arr.end(), 0);
//         int n = arr.size();
//         int half = totSum / 2;  // ✅ Only need to check up to half sum

//         vector<vector<bool>> dp(n, vector<bool>(half + 1, false));

//         // Base case: sum = 0 is always possible
//         for (int i = 0; i < n; i++) {
//             dp[i][0] = true;
//         }

//         // Initialize first row correctly
//         if (arr[0] <= half) {
//             dp[0][arr[0]] = true;
//         }

//         for (int ind = 1; ind < n; ind++) {
//             for (int target = half; target >= arr[ind]; target--) {  // ✅ Iterate backwards
//                 bool notTaken = dp[ind - 1][target];
//                 bool taken = (arr[ind] <= target) ? dp[ind - 1][target - arr[ind]] : false;
//                 dp[ind][target] = notTaken || taken;
//             }
//         }

//         int mini = 1e9;
//         for (int sum1 = 0; sum1 <= half; sum1++) {
//             if (dp[n - 1][sum1]) {
//                 int sum2 = totSum - sum1;
//                 mini = min(mini, abs(sum1 - sum2));
//             }
//         }
//         return mini;
//     }
// };
 
 class Solution {
public:
int minimumDifference(vector<int>& nums) {
    int n = nums.size(),  sum = 0;
    sum = accumulate(nums.begin(), nums.end(),0);  // To find the total sum of the array 
    
    int N = n/2; // Divide it into two equals parts as length is even
    vector<vector<int>> left(N+1), right(N+1); // left array and right array
    
	//All possible sum in left and right part (Generating and storing using BIT-Masking)
    for(int mask = 0; mask<(1<<N); ++mask){  // (1<<n) means 2^n i.e we'll iterate through 0 to 2^n
        int idx = 0, l_sum = 0, r_sum = 0;
        for(int i=0; i<N; ++i){
            if(mask&(1<<i)){  // To check if the bit is set or not 
                idx++;
                l_sum += nums[i];
                r_sum += nums[i+N];
            }
        }
        left[idx].push_back(l_sum);
        right[idx].push_back(r_sum);   // storing
    }

    for(int idx=0; idx<=N; ++idx){
        sort(right[idx].begin(), right[idx].end());   // as we'll perform binary search on right so we have to sort it first
    }

 int res = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0]));  // To get the minimum answer from the max sum from both array
		//iterating over left part
		for(int idx=1; idx<N; ++idx){ // iterate from 1 so we dont have to include 0 and check for all value except last as we have alr considered it
			for(auto &a : left[idx]){ // check the sum at each number position
				int b = (sum - 2*a)/2; // find the value to be minimized 
				int rightidx = N-idx; // find the number value in right array
				auto &v = right[rightidx]; // store the vector in v at right number position
				auto itr = lower_bound(v.begin(), v.end(),b); //binary search over right part

				if(itr!=v.end()) res = min(res, abs(sum-2*(a+(*itr)))); // if found in vector then only update otherwise continue

				}                
			}
		return res;

	}
};