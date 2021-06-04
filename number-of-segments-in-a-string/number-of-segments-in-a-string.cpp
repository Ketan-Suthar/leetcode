class Solution {
public:
    int countSegments(string s)
    {
        int i = 0;
        int ind = 0;
        int size = s.size();
        while(ind < size)
        {
            while(ind < size && s[ind] == ' ')
                ++ind;
            if(ind == size) break;
            while(ind < size && s[ind] != ' ')
                ++ind;
                ++i;
        }
        return i;
    }
};