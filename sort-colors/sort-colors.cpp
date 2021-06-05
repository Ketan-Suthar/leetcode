class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int size = nums.size();
        int s = 0, e = size - 1;
        int ind = 0;
        while(ind <= e)
        {
            switch(nums[ind])
            {
                case 0:
                {
                    swap(nums[s], nums[ind]);
                    ++s;
                    ++ind;
                    break;
                }
                case 1:
                {
                    ++ind;
                    break;
                }
                case 2:
                {
                    swap(nums[e], nums[ind]);
                    --e;
                    break;
                }
            }
        }
    }
};