class Solution {
public:
    bool isValid(string s)
    {
        stack<char> stk;
        map<char, char> op;
        op['('] = ')';
        op['{'] = '}';
        op['['] = ']';
        bool res = 1;
        for(int i=0;i<s.size();++i)
        {
            char ch = s[i];
            if(ch=='(' || ch=='{' || ch=='[')
                stk.push(ch);
            else
            {
                if(stk.size() == 0 || op[stk.top()] != ch)
                    return false;
                stk.pop();
            }
        }
        if(stk.size() > 0)
            return false;
        return true;
    }
};