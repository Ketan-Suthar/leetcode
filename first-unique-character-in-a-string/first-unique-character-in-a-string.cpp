class Solution {
public:
    int firstUniqChar(string s)
    {
        map<char,pair<int,int>> map;
        for(int i=0;i<s.size(); ++i)
        {
            char c = s[i];
            //if(map.find(c) != map.end())
                map[c] =  {i, map[c].second+1};
            // else
            // {
            //     cout << "first time: ";
            //     map[c] = {i, 1};
            // }
            
            // cout << c << ' ' << i << ' ' << map[c].second << '\n';
        }
        // cout << '\n';
        int res = INT_MAX;
        for(auto p: map)
        {
            // cout << p.first << ' ' << p.second.first << ' ' << p.second.second << '\n';
            if(p.second.second == 1)
                 res = min(res, p.second.first);
        }
        return res == INT_MAX ? -1 : res;
    }
};