// // class Solution {
// // public:
// //     int search(vector<int>& nums, int target)  
// //     {
// //         int n=nums.size(); 
// //         int low=0; 
// //         int high=n-1; 

// //         while(high>=low)
// //         {
// //             int mid=(low+high)/2; 
// //             if(target==nums[mid])
// //             {
// //                 return mid;
// //             } 
// //             else if(target>nums[mid]) //if the target is present at the right side of the mid
// //             {
// //                 low=mid+1;
// //             } 
// //             else                 //if the target value is present at the left side of the mid
// //             {
// //                 high=mid-1;
// //             }
// //         }
// //         return -1;
// //     }
// // }; 


// class Solution {
// public:
//     int search(vector<int>& nums, int target)  
//     {
//         int n=nums.size(); 
//         int low=0; 
//         int high=n-1; 
        
//         while(high>=low)
//         {
//             int mid=(low+high)/2; 
//             if(target==nums[mid])
//             {
//                 return mid;
//             } 
//             else if(target>nums[mid]) //if the target is present at the right side of the mid
//             {
//                 low=mid+1;
//             } 
//             else                 //if the target value is present at the left side of the mid
//             {
//                 high=mid-1;
//             }
//         }
//         return -1;
//     } 

   
// }; 


// class Solution {
// public:
//     int search(vector<int>& nums, int target)  
//     {
//         int n=nums.size(); 
//         int low=0; 
//         int high=n-1; 

//         while(high>=low)
//         {
//             int mid=(low+high)/2; 
//             if(target==nums[mid])
//             {
//                 return mid;
//             } 
//             else if(target>nums[mid]) //if the target is present at the right side of the mid
//             {
//                 low=mid+1;
//             } 
//             else                 //if the target value is present at the left side of the mid
//             {
//                 high=mid-1;
//             }
//         }
//         return -1;
//     }
// }; 


class Solution {
public:
    int search(vector<int>& nums, int target)  
    {
        int n=nums.size(); 
        int low=0; 
        int high=n-1; 
        return ans(nums,low,high,target);
    } 

    int ans(vector<int>&nums,int low,int high,int target)
    {   
        
        int mid=(low+high)/2;
        if(low>high)
        {
            return -1;
        } 

        if(nums[mid]==target)
        {
            return mid;
        }  
        else if(target>nums[mid])
        {
            return ans(nums,mid+1,high,target);
        } 
        else 
        {
            return ans(nums,low,mid-1,target);
        }
        
    }
};