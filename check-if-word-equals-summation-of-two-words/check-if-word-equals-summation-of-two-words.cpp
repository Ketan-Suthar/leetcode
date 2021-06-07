class Solution {
public:
    int helper(string word)
    {
        int sum = 0;
        for(char c:word)
            sum = (sum * 10) + (c-'a');
        return sum;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        return helper(firstWord) + helper(secondWord) == helper(targetWord);
    }
};