#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque {
    private:
    int *deque = nullptr;
    int front, back;
    int size;
    int k;
public:
    MyCircularDeque(int k) {
        deque = new int[k]();
        front = 0;
        back = k - 1;
        size = 0;
        this->k = k;
    }
   /*  void out()
    {
        for(int i = 0; i < k; ++i)
        {
            cout<<deque[i]<<" ";
        }
        cout<<endl;
    } */
    bool insertFront(int value) {
        if(size == k)
            return false;
        deque[front] = value;
        front = (front + 1) % k;
        ++size;
        return true;
    }
    
    bool insertLast(int value) {
        if(size == k)
            return false;
        deque[back] = value;
        back = (back + k - 1) % k;
        ++size;
        return true;
    }
    
    bool deleteFront() {
        if(size == 0)
            return false;
        front = (front + k - 1) % k;
        --size;
        return true;
    }
    
    bool deleteLast() {
        if(size == 0)
            return false;
        back = (back + 1) % k;
        --size;
        return true;
    }
    
    int getFront() {
        if(size == 0)
            return -1;
        else
            return deque[(front + k - 1) % k];
    }
    
    int getRear() {
        if(size == 0)
            return -1;
        else
            return deque[(back + 1) % k];
    }
    
    bool isEmpty() {
        if(size == 0)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if(size == k)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
int main()
{
    MyCircularDeque de(3);
    de.insertLast(1);
    de.insertLast(2);
    de.insertFront(3);
    de.insertFront(4);
    cout<<de.getRear();
}