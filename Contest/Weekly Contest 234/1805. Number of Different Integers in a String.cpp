class Solution {
public:
    int numDifferentIntegers(string word) {
        
        for(int i = 0; i < word.size(); i++){
            
            if(!isdigit(word[i])){
                word[i] = ' ';
            }
        }
        
        stringstream X(word);
        
        string temp;
        
        int count = 0;
        
        set<string> s;
        
        while(X >> temp){
            
            int i = 0;
            while(temp[i] == '0' && i < temp.size()){
                i++;
            }
            s.insert(temp.substr(i,temp.size()-i));
        }
        
        return s.size();
    }
};
