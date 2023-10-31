class MyHashSet {
public:
    vector<int> vec;
    MyHashSet() {
        vec.resize(1e6+5,0);
    } 
    
    void add(int key) {
       vec[key]=1;
    }
    
    void remove(int key) {
       vec[key]=0;
    }
    
    bool contains(int key) {
        return vec[key];
    }
};