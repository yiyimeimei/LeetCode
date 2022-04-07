class Solution {

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 总人数
     * @param m int整型 最大报数值
     * @return int整型
     */
    int playNum(int n, int m) {
        if(n == 1)//唯一的幸存者 别玩了
        {
            return 1;
        }
        return (helper(n - 1, m) + m) % n + 1;
        
    }
    int helper(int n, int m)
    {
        if(n == 1)
        {
            return 0;
        }
        return (helper(n - 1, m) + m) % n;
    }
};