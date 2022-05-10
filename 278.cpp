// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 1, r = n;
        long mid;
        int wrongVersion = n;
        int rightVersion = -1;
        while(l <= r)
        {
            if(rightVersion + 1 == wrongVersion)
                break;
            mid = (l + r) / 2;
            bool flag = isBadVersion(mid);
            if(!flag)
            {
                rightVersion = mid;
                l = mid + 1;
            }
            else
            {
                wrongVersion = mid;
                r = mid - 1;
            }
            
        }
        return wrongVersion;
    }
};