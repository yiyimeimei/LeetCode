class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        int i = 0;
        for(; i < len; ++i)
        {
            if(letters[i] > target)
                break;
        }
        if(i == len)
            i = 0;
        return letters[i];
    }
};