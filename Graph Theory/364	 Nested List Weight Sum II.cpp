//Method - 1
class Solution {
public:
    /**
     * @param nestedList: a list of NestedInteger
     * @return: the sum
     */
    int depthSumInverse(vector<NestedInteger> nestedList) {
        
        int maxLevel = 1;
        int sum = 0;

        vector<NestedInteger> tmp = nestedList;

        while(nestedList.size() != 0){
            vector<NestedInteger> v;
            for(auto x: nestedList){
                if(!x.isInteger()){
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
            maxLevel++;
            nestedList = v;
        }

        maxLevel--;
        while(tmp.size() != 0){
            vector<NestedInteger> v;
            for(auto x: tmp){
                if(x.isInteger()){
                    sum += x.getInteger()*maxLevel;
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
            maxLevel--;
            tmp = v;
        }
        return sum;
    }
};

//Method - 2
//Alternate
class Solution {
public:
    /**
     * @param nestedList: a list of NestedInteger
     * @return: the sum
     */
    void solve(vector<NestedInteger> nestedList, int &lv, int &sum){

        if(nestedList.size() == 0){
            return;
        }
        
        vector<NestedInteger> v;
        int tsum = 0;

        for(auto x: nestedList){
            if(x.isInteger()){
                tsum += x.getInteger();
            }
            else{
                vector<NestedInteger> temp = x.getList();
                for(auto y: temp){
                    v.push_back(y);
                }
            }
        }
        solve(v, lv, sum);
        lv++;
        sum += lv*tsum;
    }
    int depthSumInverse(vector<NestedInteger> nestedList) {
        
        int lv = 0, sum = 0;
        solve(nestedList, lv, sum);
        return sum;
    }
};
