class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        
        int n = rolls.size();
        unordered_set<int> us;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(us.find(rolls[i]) == us.end()){
                us.insert(rolls[i]);
                if(us.size() == k){
                    us.clear();
                    ans++;
                }
            }
        }
        return 1 + ans;
    }
};
