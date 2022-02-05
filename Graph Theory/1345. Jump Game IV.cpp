//Ref: https://www.youtube.com/watch?v=JYbU8RH1OSQ
class Solution {
public:
    int minJumps(vector<int>& arr) {
       
        unordered_map<int,vector<int>> mp;
        
        for(int i = arr.size() - 1; i >= 0; i--){
            mp[arr[i]].push_back(i);
        }
        
        int level = 0;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();

                if(curr == arr.size() - 1){
                    return level;
                }
                
                if(curr + 1 < arr.size() && mp.find(arr[curr + 1]) != mp.end()){
                    q.push(curr + 1);
                }
                if(curr - 1 >= 0 && mp.find(arr[curr - 1]) != mp.end()){
                    q.push(curr - 1);
                }
                for(auto &x: mp[arr[curr]]){
                    if(curr != x){
                        q.push(x);
                    }
                }
                mp.erase(arr[curr]);
            }
            level++;
            
        }
        return -1;
    }
};
