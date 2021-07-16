/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> v;
    int curr = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        v.clear();
        for(auto x: nestedList){
            helper(x);
        }
    }
    void helper(NestedInteger x){
        if(x.isInteger()){
            v.push_back(x.getInteger());
        }
        else{
            for(auto val: x.getList()){
                helper(val);
            }
        }
    }
    int next() {
        int ele = v[curr];
        curr++;
        return ele;
    }
    
    bool hasNext() {
        if(curr < v.size()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
