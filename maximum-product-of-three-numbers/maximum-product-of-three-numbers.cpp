class Solution {
public:
    int maximumProduct(vector<int>& nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int n1 = nums[0] * nums[1] * nums[size-1];
        int n2 = nums[size-3] * nums[size-2] * nums[size-1];
        return max(n1, n2);
    }
};