//https://www.lintcode.com/problem/551/
//Ref: https://www.youtube.com/watch?v=B2i_AfmZBgk
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        
        int lv = 1, sum = 0;

        while(nestedList.size() != 0){
            vector<NestedInteger> v;
            for(auto x: nestedList){
                if(x.isInteger()){
                    sum += x.getInteger()*lv;
                }
                else{
                    vector<NestedInteger> temp = x.getList();
                    for(auto y: temp){
                        if(y.isInteger()){
                            v.push_back(y);
                        }
                        else{
                            v.push_back(y);
                        }
                    }
                }
            }
            lv++;
            nestedList = v;
        }
        return sum;
    }
};
