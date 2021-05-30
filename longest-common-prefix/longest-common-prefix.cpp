class Solution {
public:
    int min(int a, int b)
    {
        if(a < b)
            return a;
        return b;
    }
    string longestCommonPrefix(vector<string>& strs)
    {
        string res = "";
        char prev;
        int ind = 0;
        int s = strs.size();
        int min_len = INT_MAX;
        int i = 0;
        for(i=0; i<s; ++i)
            min_len = min(min_len, strs[i].size());
        int start = 0;
        while(ind < min_len)
        {
            prev = strs[0][ind];
            
            for(i=1; i<s; ++i)
            {
                if(ind >= strs[i].size())
                    return res;
                else
                {
                    if(strs[i][ind] != prev)
                        return res;
                }
            }
            res = res + strs[i-1][ind];
            ++ind;
        }
        return res;
    }
};