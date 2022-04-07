/** 
 * 由至少 6 个，至多 20 个字符组成。
至少包含 一个小写 字母，一个大写 字母，和 一个数字 。
同一字符 不能 连续出现三次 (比如 "...aaa..." 是不允许的, 但是 "...aa...a..." 如果满足其他条件也可以算是强密码

缺少类型和连续重复可以合并操作，需要计算有效最小操作，删除优先级最高，但是可以用来解决连续重复，删除时优先删除 长度n%3 === 0 的连续序列1个字符，然后是%3=1删2个，然后%3=2删3个。删到长度合适之后再用替换操作解决剩下的问题。如果不需要删除操作基本没啥复杂的逻辑
*/
class Solution {
public:
    int strongPasswordChecker(string password) {
        int len = password.length();
        bool lower = false, upper = false, number = false;


    }
};