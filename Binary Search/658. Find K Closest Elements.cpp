//Method - 1
//Priority Queue
class Solution {
public:
    #define pii pair<int,int>
    struct cmp{
      bool operator()(pii &p1, pii &p2){
          if(p1.second == p2.second){
              return p1.first < p2.first;
          }
          return p1.second < p2.second;
      }  
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pii,vector<pii>,cmp> pq;
        
        for(int i = 0; i < arr.size(); i++){
            pq.push({arr[i], abs(arr[i] - x)});
            
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> res;
        
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=6AackEaa0Qs
//Binary Search
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        
        int lo = 0, hi = n - 1, ans = n - 1, diff = INT_MAX;
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(arr[mid] == x){
                ans = mid;
                diff = 0;
                break;
            }
            else if(arr[mid] > x){
                if(arr[mid] - x < diff){
                    ans = mid;
                    diff = arr[mid] - x;
                }
                hi = mid - 1;
            }
            else{
                if(x - arr[mid] < diff){
                    ans = mid;
                    diff = x - arr[mid];
                }
                lo = mid + 1;
            }
        }
  
        int ptr1 = ans - 1, ptr2 = ans;
        
        vector<int> res;
        
        while(k--){
            if(ptr1 >= 0 && ptr2 < n){
                if(abs(arr[ptr1] - x) <= abs(arr[ptr2] - x)){
                    res.push_back(arr[ptr1]);
                    ptr1--;
                } 
                else{
                    res.push_back(arr[ptr2]);
                    ptr2++;
                }
            }
            else if(ptr1 >= 0){
                res.push_back(arr[ptr1]);
                ptr1--;
            }
            else{
                res.push_back(arr[ptr2]);
                ptr2++;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
