class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        vector<string> v1,v2;
        
        stringstream X1(sentence1);
        
        string temp;
        
        while(X1 >> temp){
            v1.push_back(temp);
        }
        
        stringstream X2(sentence2);
        
        while(X2 >> temp){
            v2.push_back(temp);
        }
      
        int p1 = 0, p2 = 0;
        
        bool flag = false;
        
        while(p1 < v1.size() && p2 < v2.size()){
            
            if(v1[p1] == v2[p2]){
                p1++;
                p2++;
            }
            else{
                
                if(v1.size() > v2.size()){
                    
                    int ind = v1.size();
                    
                    while(p1 < v1.size()){
                        
                        if(v1[p1] == v2[p2]){
                            ind = p1;
                        }
                        
                        p1++;
                    }
                    
                    p1 = ind;
                    
                    if(p1 == v1.size()){
                        return false;
                    }
                    else if(p1 < v1.size() && v1[p1] == v2[p2] && flag == false){
                        
                        flag = true;
                    }
                    else if(p1 < v1.size() && v1[p1] == v2[p2] && flag == true){
                        return false;
                    }
                }
                else{
                    
                    int ind = v2.size();
                    
                    while(p2 < v2.size()){
                        if(v1[p1] == v2[p2]){
                             ind = p2;
                        }
                        p2++;
                    }
                    //cout << p2 << endl;
                    p2 = ind; 
                    
                    if(p2 == v2.size()){
                        return false;
                    }
                    else if(p2 < v2.size() && v1[p1] == v2[p2] && flag == false){
                        flag = true;
                    }
                    else if(p2 < v2.size() && v1[p1] == v2[p2] && flag == true){
                        return false;
                    }
                }
            }
        }
        
        if(p1 < v1.size()){
            if(flag == false){
                return true;
            }
            else{
                return false;
            }
        }
        
        if(p2 < v2.size()){
            if(flag == false){
                return true;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};
