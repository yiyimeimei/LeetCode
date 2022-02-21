#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int length = arr.size();
        if(length == 1)
            return 0;
        unordered_map<int, vector<int>> map;
        for(int i = 0; i < length; ++i)
        {
            map[arr[i]].push_back(i);
        }
    }
};

int main()
{

}