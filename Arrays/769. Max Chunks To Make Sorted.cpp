//Method - 1
class Solution {
public:
    void solve(int ind, int &maxCount, int count, vector<int> &arr, vector<int> &sorted, vector<vector<int>> &temp){
        
        if(ind == sorted.size()){
            int idx = 0;
            for(int i = 0; i < temp.size(); i++){
                vector<int> v = temp[i];
                sort(v.begin(),v.end());
                for(int j = 0; j < v.size(); j++){
                    if(v[j] != sorted[idx]){
                        return;
                    }
                    else{
                        idx++;
                    }
                }
            }
            maxCount = max(maxCount, count);
        }
        vector<int> vec;
        for(int i = ind; i < sorted.size(); i++){
            vec.push_back(arr[i]);
            temp.push_back(vec);
            solve(i + 1, maxCount, count + 1, arr, sorted, temp);
            temp.pop_back();
        }
    }
    int maxChunksToSorted(vector<int>& arr) {
        
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        
        vector<vector<int>> temp;
        
        int maxCount = 0, count = 0;
        
        solve(0, maxCount, count, arr, sorted, temp);
        
        return maxCount;
    }
};

//Method - 2
//Optimal
//Ref: https://www.youtube.com/watch?v=XZueXHOhO5E
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int count = 0, maxVal = 0;
        
        for(int i = 0; i < arr.size(); i++){
            maxVal = max(maxVal, arr[i]);
            if(i == maxVal) count++;
        }
        return count;
    }
};
