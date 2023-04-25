class SmallestInfiniteSet {
public:
    map<int,int> m;
    int smallest=0;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(m.size()==0)
        {
            smallest++;
            return smallest;
        }
        else{
            int ans;
            auto it=m.begin();
            ans = it->first;
            m.erase(it->first);
            return ans;
        }
    }
    
    void addBack(int num) {
        if(smallest>=num) m[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */