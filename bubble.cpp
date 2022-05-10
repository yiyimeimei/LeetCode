#include <iostream>
#include <vector>
using namespace std;


void bubble(vector<int> &array)
{
    int len = array.size();
    bool flag;
    for(int i = 0; i < len - 1; ++i)
    {
        flag = false;
        for(int j = 0; j < len - 1; ++j)
        {
            if(array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = true;
            }
        }
        if(!flag)
        {
            break;
        }
    }
    return;
}

int main()
{
    vector<int> arr{8,5,9,4,3,7};
    bubble(arr);
    int len = arr.size();
    for(int i = 0; i < len; ++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}