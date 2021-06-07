class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if(k==1) return nums;
        
        int size = nums.size();
        
        deque<int> q;
        vector<int> res;
        
        q.push_back(0);
        for(int i=1;i<k;++i)
        {
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
        }
        
        int s = 0, e = k-1;
        
        while(e < size)
        {
            res.push_back(nums[q.front()]);
            
            if(s == q.front())
                q.pop_front();
            ++s;
            ++e;
            while(e < size && !q.empty() && nums[q.back()] < nums[e])
                q.pop_back();
            q.push_back(e);
        }
        
        return res;
    }
};