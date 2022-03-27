class MyHashMap {
private:
    vector<pair<int, int>> map[100000];
    int hash(int key)
    {
        return key % 100000;
    }
    int getPos(int key, int mi)
    {
        int len = map[mi].size();
        for(int i = 0; i < len; ++i)
        {
            if(map[mi][i].first == key)
                return i;
        }
        return -1;
    }
public:
    MyHashMap() {

    }
    
    void put(int key, int value) {
        int h = hash(key);
        int pos = getPos(key, h);
        if(pos == -1)
        {
            map[h].push_back(pair<int, int>(key, value));
        }
        else
        {
            map[h][pos].second = value;
        }
    }
    
    int get(int key) {
        int h = hash(key);
        int pos = getPos(key, h);
        if(pos == -1)
            return -1;
        else
            return map[h][pos].second;
    }
    
    void remove(int key) {
        int h = hash(key);
        int pos = getPos(key, h);
        if(pos != -1)
        {
            map[h].erase(map[h].begin() + pos);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */