class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int size = nums.size();
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int ind = 0; ind < size-2; ++ind)
        {
            if(ind == 0 || (nums[ind] != nums[ind-1]))
            {
                int low = ind + 1, end = size -1;
                int op = 0 - nums[ind];
                while(low < end)
                {
                    int sum = nums[low] + nums[end];
                    if(sum == op)
                    {
                        vector<int> r;
                        r.push_back(nums[ind]);
                        r.push_back(nums[low]);
                        r.push_back(nums[end]);
                        res.push_back(r);
                        
                        while(low < end && nums[low] == nums[low+1]) ++low;
                        while(low < end && nums[end] == nums[end-1]) --end;
                        ++low;
                        --end;
                    }
                    else if(sum > op)
                        --end;
                    else
                        ++low;
                }
            }
        }
        return res;
    }
};