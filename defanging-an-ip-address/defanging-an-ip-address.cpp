class Solution {
public:
    string defangIPaddr(string address) {
        string s;
        for(char c: address)
        {
            if(c == '.')
                s.append("[.]");
            else
                s.push_back(c);
        }
        return s;
    }
};