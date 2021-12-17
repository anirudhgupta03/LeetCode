class Solution {
public:
    #define pci pair<char,int>
    struct cmp{
      bool operator()(pci p1, pci p2){
          return p1.second < p2.second;
      }  
    };
    string reorganizeString(string s) {
        
        priority_queue<pci,vector<pci>,cmp> pq;
        
        int alpha[26] = {0};
        
        for(int i = 0; i < s.size(); i++){
            alpha[s[i] - 97]++;
        }
        
        for(int i = 0; i < 26; i++){
            if(alpha[i] != 0){
                pq.push({i + 'a', alpha[i]});
            }
        }
        
        string res;
        
        while(!pq.empty()){
            
            pci p1 = pq.top();
            pq.pop();
            
            if(pq.empty()){
                if(p1.second != 1){
                    return "";
                }
                else{
                    res.push_back(p1.first);
                    return res;
                }
            }
            
            pci p2 = pq.top();
            pq.pop();
            
            res.push_back(p1.first);
            p1.second--;
            
            res.push_back(p2.first);
            p2.second--;
            
            if(p1.second != 0) pq.push({p1.first,p1.second});
            if(p2.second != 0) pq.push({p2.first,p2.second});
        }
        
        return res;
    }
};
