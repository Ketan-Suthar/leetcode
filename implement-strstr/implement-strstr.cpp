class Solution {
public:
    int strStr(string a, string b) 
    {
        int s1 = a.size(), s2 = b.size();
        if(s1 < s2)
            return -1;
        if(!s1 && !s2) return 0;
        if(!s2) return 0;
        for(int i=0;i<(s1-s2+1); ++i)
        {
            if(a[i]==b[0])
            {
                bool found = true;
                for(int j=1;j<s2;++j)
                    if(a[i+j] != b[j])
                    {
                        found = false;
                        break;
                    }
                if(found)
                    return i;
            }
            
        }
        return -1;
    }
};