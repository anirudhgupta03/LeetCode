//Ref: https://www.youtube.com/watch?v=4GoOcyybPww
class Solution {
public:
    vector<string> findNextStates(string &s){
        vector<string> res;
        //Button 1;
        string temp = s;
        for(int i = 0; i < temp.size(); i++){
            temp[i] = temp[i] == '0' ? '1' : '0';
        }
        res.push_back(temp);
        temp = s;
        //Button 2
        for(int i = 1; i < temp.size(); i += 2){
            temp[i] = temp[i] == '0' ? '1' : '0';
        }
        res.push_back(temp);
        temp = s;
        //Button 3
        for(int i = 0; i < temp.size(); i += 2){
            temp[i] = temp[i] == '0' ? '1' : '0';
        }
        res.push_back(temp);
        temp = s;
        //Button 4
        for(int i = 0; i < temp.size(); i += 3){
            temp[i] = temp[i] == '0' ? '1' : '0';
        }
        res.push_back(temp);
        return res;
    }
    int flipLights(int n, int presses) {
        
        if(presses == 0){
            return 1;
        }
        string s;
        
        char on = '1', off = '0';
        
        for(int i = 0; i < n; i++){
            s.push_back(on);
        }
        
        
        queue<string> q;
        q.push(s);
        
        int count = 0;
        unordered_set<string> vis;
        while(presses){
            presses--;
            int sz = q.size();
            vis.clear();
            while(sz--){
                s = q.front();
                q.pop();
                count++;
                vector<string> v = findNextStates(s);
                for(int i = 0; i < v.size(); i++){
                    if(vis.find(v[i]) == vis.end()) {
                        q.push(v[i]);
                        vis.insert(v[i]);
                    }
                }
            }
        }
        return vis.size();
    }
};
