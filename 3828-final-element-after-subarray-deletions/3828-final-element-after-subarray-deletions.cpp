class Solution {
public:
    int finalElement(vector<int>& nums) 
    {
        // Alice and Bob , play a game in turns with alice is playing first 
        // in each turn a player choose a subarray . such that r-l+1<m , where m , is the current length of the array

        // selected subarray is remmoved and remaining are get concancated to new array ,

        // game continue untill only one elment remains 

        // alice aim is maximize the final , Bob is minimize , return the final remaining single element

            return max(nums[0], nums[nums.size()- 1]);
    }
};