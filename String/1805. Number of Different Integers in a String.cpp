class Solution {
public:
    int numDifferentIntegers(string word) {
        
        for(int i = 0; i < word.size(); i++){
            
            if(!(word[i] >= '0' && word[i] <= '9')){
                word[i] = ' ';
            }
        }
        
        stringstream X(word);
        
        string temp;
        
        unordered_map<string,int> umap;
        
        while(X >> temp){
            
            int i = 0;
            while(temp[i] == '0' && i < temp.size() - 1){     
                i++;
            }
            
            temp = temp.substr(i,temp.size()-i);
            umap[temp]++;

        }
        
        for(auto x: umap){
            cout << x.first << " ";
        }
        cout << endl;
        return umap.size();
    }
};
