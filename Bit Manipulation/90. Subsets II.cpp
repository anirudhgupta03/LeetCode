class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> v;
        
        map<vector<int>,int> m;
        
        for(int i = 0; i < (1 << n); i++){
            
            vector<int> p;
            
            for(int j = 0; j < n; j++){
                
                int k = 1 << j;
                
                if((i & k) != 0){
                    p.push_back(nums[j]);
                }
            }
            
            sort(p.begin(),p.end());
            if(m[p] == 0){
                v.push_back(p);
                m[p]++;
            }
        }
        return v;
    }
};
