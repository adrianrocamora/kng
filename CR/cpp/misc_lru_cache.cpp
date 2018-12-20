#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache{
private:
    list<pair<int,int>> cache_vals_;
    unordered_map<int, list<int>::iterator> cache_;
    int capacity_;
    void evict_if_needed() {
        if (cache_.size() >= capacity_) {
            auto p = cache_.find(cache_vals_.front().first);
            cache_vals_.pop_front();
            cache_.erase(p);
        }
    }
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto found = cache_.find(key);
        if (found == cache_.end()) {
            return -1;
        }
        int val = found->second->value;
        cache_vals_.erase(p->second);
        cache_vals_.push_back(val);
        
        // Update cache key with iterator of last element in list
        cache_[key] = cache_vals_.back();
        
        return val;
    }
    
    void set(int key, int value) {
        auto p = cache_.find(key);
        if (p != cache_.end()) {
            cache_vals_.erase(p->second);
        } else {
            evict_if_needed();
        }
        cache_vals_.push_back(value);
        cache_[key] = cache_vals_.get_tail();
    }
};

int main() {
}
