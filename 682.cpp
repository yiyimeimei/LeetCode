class Solution {
public:
    int calPoints(vector<string>& ops) {
        int len = ops.size();
        vector<int> score;
        for(int i = 0; i < len; ++i)
        {
            if(ops[i] == "+")
            {
                int s = score.size();
                score.push_back(score[s - 1] + score[s - 2]);
            }
            else if(ops[i] == "D")
            {
                int s = score.size();
                score.push_back(score[s - 1] * 2);
            }
            else if(ops[i] == "C")
            {
                score.pop_back();
            }
            else
            {
                int s = stoi(ops[i]);
                score.push_back(s);
            }
        }
        len = score.size();
        int sum = 0;
        for(int i = 0; i < len; ++i)
        {
            sum += score[i];
        }
        score.clear();
        return sum;
    }
};