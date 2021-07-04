class Solution {
public:
    static bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
        // if(v1[0] != v1[0])
            return v1[0] > v2[0];
        // return v1[1] < v2[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(), in.end(), sortcol);
        
        stack<pair<int,int>> s;
        for(int i=0;i<in.size();++i)
            s.push({in[i][0], in[i][1]});
        
        vector<vector<int>> res;
        
        pair<int,int> first = s.top();
        s.pop();
        while(!s.empty())
        {
            pair<int,int> sec = s.top();
            s.pop();
            cout<<first.first<<' '<<first.second<<' '<<sec.first<<' '<<sec.second<<'\n';
            if(first.second >= sec.first)
            {
                s.push({first.first, max(first.second, sec.second)});
                first = s.top();
                s.pop();
            }
            else
            {
                vector<int> temp;
                temp.push_back(first.first);
                temp.push_back(first.second);
                res.push_back(temp);
                first = sec;
            }
        }
        vector<int> temp;
        temp.push_back(first.first);
        temp.push_back(first.second);
        res.push_back(temp);
        return res;
    }
};