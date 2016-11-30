class RandomizedSet {
unordered_map<int, int> uomap;
vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        this->uomap.clear();
        this->v.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // add val into this->uomap
        if (!(this->uomap.insert(unordered_map<int, int>::value_type(val, v.size()))).second) return false;
        else {
            // add val into this->v
            this->v.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // try removing it from this->uomap first
        unordered_map<int, int>::iterator it = this->uomap.find(val);
        if (it == this->uomap.end()) return false;
        else {
            // save its index
            int index = it->second;
            // remove it from this->uomap
            this->uomap.erase(val);
            // remove it from this->v
            if (index < this->v.size() - 1) {
                this->uomap[this->v[index] = this->v[this->v.size()-1]] = index;
            }
            this->v.pop_back();
            // return
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return (this->v[rand() % this->v.size()]);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
