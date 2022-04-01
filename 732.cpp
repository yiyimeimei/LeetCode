//虚构一条timeline 遇到start，次数加，遇到end，次数减

class MyCalendarThree {
private:
    /* struct ListNode
    {
        int time;
        int num;
        bool type;//true代表开始，false代表结束
        ListNode *next;
        ListNode(int t, int n, bool type):time(t), num(n), type(type), next(nullptr){}
    }; */
    //vector<vector<int>> schedule;
    //ListNode *head;
    map<int, int> m;
public:
    MyCalendarThree() {
        m.clear();
    }
    
    int book(int start, int end) {
        if(m.count(start) == 0)
        {
            m[start] = 1;
        }
        else
        {
            ++m[start];
        }
        if(m.count(end) == 0)
        {
            m[end] = -1;
        }
        else
        {
            --m[end];
        }
        int maxCnt = 0;
        int sum = 0;
        for(auto iter = m.begin(); iter != m.end(); ++iter)
        {
            sum += iter->second;
            maxCnt = max(maxCnt, sum);
        }
        return maxCnt;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */