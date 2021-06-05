class Solution {
public:
    int numberOfMatches(int n)
    {
        if(n == 0 || n == 1) return 0; 
        if(n == 2) return 1;
        if(n % 2)
            return ((n - 1) / 2) + numberOfMatches((n - 1) / 2 + 1);
        return (n / 2) + numberOfMatches(n / 2);
    }
};