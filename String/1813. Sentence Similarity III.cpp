class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        vector<string> v1,v2;
        
        stringstream X1(sentence1);
        stringstream X2(sentence2);
        string temp;
        
        while(X1 >> temp) v1.push_back(temp);
 
        while(X2 >> temp) v2.push_back(temp);
        
        if(v1.size() == v2.size()){
            if(v1 == v2){
                return true;
            }
            else{
                return false;
            }
        }
        
        if(v2.size() > v1.size()){
            swap(v1,v2);
        }
        
        int p1 = 0, p2 = 0;
        
        bool flag = false;
        
        while(p1 < v1.size() && p2 < v2.size()){
            
            if(v1[p1] == v2[p2]){
                p1++;
                p2++;
            }
            else if(v1[p1] != v2[p2]){
                
                if(flag){
                    return false;
                }
                int ind = v1.size();
                
                for(int i = p1 + 1;i < v1.size(); i++){     //Find the rightmost match for the present string 
                    if(v1[i] == v2[p2]){
                        ind = i;
                    }
                }
                
                p1 = ind;
                if(p1 == v1.size()){
                    return false;
                }
                
                flag = true;
            }
        }
        
        if(p2 != v2.size() || p2 == v2.size() && p1 != v1.size() && flag){
            return false;
        }
        return true;
    }
};
