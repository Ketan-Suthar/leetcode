class Solution {
public:
    string addBinary(string a, string b)
    {
        int s1 = a.size(), s2 = b.size();
        string res;
        while(s1 < s2)
        {
            a = "0" + a;
            ++s1;
        }
        while(s2 < s1)
        {
            b = "0" + b;
            ++s2;
        }
        int carry = 0;
        cout << a << ' ' << b;
        for(int i=s1-1; i>=0; --i)
        {
            if(a[i] == b[i] && a[i] == '1')
            {
                if(carry)
                    res.push_back('1');
                else
                    res.push_back('0');
                carry = 1;
            }
            else if(a[i] == b[i] && a[i] != '1')
            {
                if(carry)
                {
                    res.push_back('1');
                    carry=0;
                }
                else
                    res.push_back('0');
            }
            else
            {
                if(carry)
                {
                    res.push_back('0');
                    carry=1;
                }
                else
                    res.push_back('1');
            }
        }
        if(carry)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};