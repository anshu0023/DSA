class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
       int n = nums.size();
       
       int diff1 = abs(nums[0]-nums[n-1]);
       int maxi = INT_MIN;
       maxi = max(diff1,maxi);
       for(int i=1;i<n;i++){
       int diff2 = abs(nums[i]-nums[i-1]);
       maxi = max(maxi,diff2) ;
       }
       return maxi;
    }
};