class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int s=0, e=size-1;
        while(s <= e)
        {
            int mid = (s+e)/2;
            if(mid > 0 && nums[mid] == nums[mid-1])
                return nums[mid];
            if(mid < size-1 && nums[mid] == nums[mid+1])
                return nums[mid];
            if(nums[mid] >= mid+1)
                s = mid+1;
            else
                e = mid-1;
            cout<<s<<' '<<e<<'\n';
        }
        
        return nums[s];
    }
};