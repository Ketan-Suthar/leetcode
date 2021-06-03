class Solution {
public:
    bool isPalindrome(string str)
    {
        int s = 0, e = str.size() - 1;
        while(s <= e)
        {
            char c1 = str[s];
            char c2 = str[e];
            cout << '\n' << c1 << ' ' << c2 << ' ';
            if(!((c1 >= 'a' && c1 <= 'z') || (c1 >= 'A' && c1<= 'Z') || (c1 >= '0' && c1 <= '9')))
            {
                ++s;
                continue;
            }
            if(!((c2 >= 'a' && c2 <= 'z') || (c2 >= 'A' && c2<= 'Z') || (c2 >= '0' && c2 <= '9')))
            {
                --e;
                continue;
            }
            
            if(c1 >= 'A' && c1 <= 'Z')
                c1 = c1 + 32;
            if(c2 >= 'A' && c2 <= 'Z')
                c2 = c2 + 32;
            cout << c1 << ' ' << c2;
            if(c1 != c2)
                return false;
            ++s;
            --e;
        }
        
        return true;
    }
};