class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int voter, vote=0, size=nums.size();
        int majority = size/2;
        for(int i=0;i<size;i++)
        {
            if(!vote)
            {
                vote=1;
                voter = nums[i];
            }
            else
            {
                if(nums[i]==voter)
                    ++vote;
                else
                    --vote;
            }
        }
        if(vote<=0) return -1;
        int count=0;
        for(int i=0;i<size;i++)
            if(nums[i]==voter) 
                ++count;
        if(count>=majority) return voter;
        return -1;
    }
};