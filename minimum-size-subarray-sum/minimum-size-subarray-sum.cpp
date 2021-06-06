class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int s = 0, e = 0, size = nums.size();
        int res = INT_MAX;
        int sum = 0;
        while(e < size)
        {
            sum += nums[e++];
            while (sum >= target) {
                res = min(res, e - s);
                sum -= nums[s++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};