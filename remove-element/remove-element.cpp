class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int size = nums.size();
        if(size == 0)
            return 0;
        int start = 0, end = size - 1;
        
        int count = 0;
        while(start <= end)
        {
            if(nums[start] == val)
            {
                nums[start] = nums[start] ^ nums[end];
                nums[end] = nums[start] ^ nums[end];
                nums[start] = nums[start] ^ nums[end];
                --end;
                ++count;
            }
            else
                ++start;
        }
        return size - count;
    }
};