class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int a=0,b=0,c=1;
        int size = nums.size();
        if(size == 0 || size ==1)
            return size;
        
        while(c < size)
        {
            if(nums[c] == nums[b])
            {
                nums[a++] = nums[b];
                nums[a++] = nums[c];
                while(b < size && c < size && nums[b] == nums[c])
                {
                    ++b;
                    ++c;
                }
                ++b;    
                ++c;
            }
            else
            {
                nums[a++] = nums[b];
                ++b;
                ++c;
            }
        }
        if(b < size && nums[b] != nums[b-1])
        {
            nums[a++] = nums[b];
        }
        return a;
    }
};