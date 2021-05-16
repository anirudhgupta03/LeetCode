//Used binary search first but TLE!!!
class FindSumPairs {
public:
    
    //map<int,int> m1;
    map<int,int> m2;
    
    vector<int> v1;
    vector<int> v2;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i = 0; i < nums2.size(); i++)
        m2[nums2[i]]++;
        v1 = nums1;
        v2 = nums2;
    }
    
    void add(int index, int val) {
        
        m2[v2[index]]--;
        v2[index] += val;
        m2[v2[index]]++;
    }
    
    int count(int tot) {
        
        int count = 0;
        
        for(int i = 0;  i < v1.size(); i++){
            
            int t = v1[i];
            
            int req = tot - t;
            
            if(m2.find(req) != m2.end())
            count += m2[req];
        
        }
        return count;
    }
    
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
