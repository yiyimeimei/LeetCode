class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;//初始化为cur = 1，k需要自减1
        while (k > 0) {
            long long step = 0, first = cur, last = cur + 1;//字树的开头first和结尾last
            //统计这棵子树下所有节点数（step）
            while (first <= n) {
                step += min((long long)n + 1, last) - first;//不能超过n的值，并不是所有节点都有十个子节点
                first *= 10;
                last *= 10;
            }
            if (step <= k) {//不在子树中，统计下一棵树
                ++cur;
                k -= step;
            } 
            else {//在子树中，进入子树
                cur *= 10;
                --k; 
            }
        }
        return cur;
    }
};