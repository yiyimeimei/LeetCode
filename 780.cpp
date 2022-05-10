class Solution
{
private:
    int targetX, targetY;

public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        targetX = sx;
        targetY = sy;
        return helper(tx, ty);
    }
    bool helper(int x, int y)
    {
        if (x < targetX || y < targetY)
            return false;
        if (x == targetX && y == targetY)
            return true;
        if (x > y)
        {
            int difference = x - targetX;
            int n = difference / y;
            if (n == 0)
                return false;
            else
                return helper(x - n * y, y);
        }
        else
        {
            int difference = y - targetY;
            int n = difference / x;
            if (n == 0)
                return false;
            else
                return helper(x, y - n * x);
        }
    }
};