class Solution {
public:
    int myAtoi(string str) {
        int size = str.size();
        if(size==0) return 0;
        
        int s = 0;
        while(s < size && str[s]==' ')
            ++s;
        
        int sign = 1;
        int res = 0;
        
        if(str[s] == '-' || str[s] == '+')
        {
            if(str[s] == '-') sign = -1;
            ++s;
        }
        
        while(s < size && str[s]=='0')
            ++s;
        cout<<str[s]<<' ';
        while(s < size)
        {
            if(str[s] == ' ') break;
            if(str[s] == '.') return res;
            
            if((!(str[s] >= '0' && str[s] <= '9')))
                return res * sign;
            
            if (res >  INT_MAX / 10 || (res == INT_MAX / 10 && str[s] - '0' > 7))
                return sign == 1 ? INT_MAX : INT_MIN;
            
            res = (res * 10) + (str[s] - '0');
            ++s;
        }
        
        return res * sign;
    }
};