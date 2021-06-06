class Solution {
public:
    vector<int> findAnagrams(string str1, string str2)
    {
        int s1 = str1.size(), s2 = str2.size();
        // cout<<s1<<' '<<s2<<'\n';
        if(s1 < s2)
            return {};
        
        map<char,int> m;
        int count=0;
        for(char c: str2)
        {
            if(m.find(c) == m.end())
            {
                ++count;
                m[c] = 1;
            }
            else
                ++m[c];
        }
        // cout << "count: " << count << "\n";
        vector<int> res;
        
        int s = 0, e = s2-1;
        for(int i=0;i<=e;++i)
        {
            char c = str1[i];
            if(m.find(c) != m.end())
            {
                --m[c];
                if(m[c] == 0)
                    --count;
            }
        }
        // cout<<"before loop s: "<<s<<" e:"<<e<<' '<<str1<<"\n";
        while(e < s1)
        {
            if(count == 0)
            {
                cout<<"count zero for s: "<< s << ' ';
                res.push_back(s);
            }
            char c = str1[s];
            cout<<c<<' ';
            if(m.find(c) != m.end())
            {
                m[c]++;
                cout<<m[c]<<' ';
                if(m[c] == 1)
                    ++count;
            }
            ++s;
            ++e;
            if(e < s1) cout<<str1[e]<<' ';
            if(e < s1 && m.find(str1[e]) != m.end())
            {
                c = str1[e];
                --m[c];
                if(m[c] == 0)
                    --count;
                cout<<m[c]<<' ';
            }
            cout<<count<<'\n';
        }
        return res;
    }
};