//Method - 1
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] < st.top() && (st.size() + (n - i)) > k){
                st.pop();
            }
            st.push(nums[i]);
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        while(res.size() > k) res.pop_back();
        return res;
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=wuwE7g8VvgQ
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] < st.top() && (st.size() + (n - i)) > k){
                st.pop();
            }
            if(st.size() < k){
                st.push(nums[i]);
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
