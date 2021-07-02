class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        map<int,int> m;
        int s=nums.size(), i=0;
        for(; i<k && i<s;++i)
        {
            if(m[nums[i]] > 0)
            {
                cout<<"found: "<<nums[i]<<'\n';
                return true;
            }
            m[nums[i]]++;
        }
        cout<<"out";
        int start=0;
        while(i<s)
        {
            if(m[nums[i]] > 0)
                return true;
            m[nums[start++]]--;
            m[nums[i++]]++;
        }
        return false;
    }
};