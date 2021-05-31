class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, size = digits.size();
        vector<int> res;
        // if(digits[size-1] == 9)
        //     carry = 1;
        for(int i=size-1; i>=0; --i)
        {
            int num = carry + digits[i];
            
            if(num >= 10)
            {
                carry = 1;
                num = 0;
            }
            else
                carry = 0;
            res.push_back(num);
        }
        if(carry)
            res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};