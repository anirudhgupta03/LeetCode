//DSU
class Solution {
public:
    char findp(char ch, unordered_map<char,char> &par){
        if(par[ch] == ch){
            return ch;
        }
        return par[ch] = findp(par[ch], par);
    }
    void unionp(char ch1, char ch2, unordered_map<char,char> &par){
        par[ch2] = ch1;
    }
    bool equationsPossible(vector<string>& equations) {
        
        unordered_map<char,char> par;
        
        for(int i = 0; i < equations.size(); i++){
            par[equations[i][0]] = equations[i][0];
            par[equations[i][3]] = equations[i][3];
        }
        
        for(int i = 0; i < equations.size(); i++){
            if(equations[i][1] == '='){
                char ch1 = equations[i][0];
                char ch2 = equations[i][3];
                
                char par1 = findp(ch1, par);
                char par2 = findp(ch2, par);
                
                if(par1 != par2){
                    unionp(par1, par2, par);
                }
            }
        }
        
        for(int i = 0; i < equations.size(); i++){
            if(equations[i][1] == '!'){
                char ch1 = equations[i][0];
                char ch2 = equations[i][3];
                
                char par1 = findp(ch1, par);
                char par2 = findp(ch2, par);
                
                if(par1 == par2){
                    return false;
                }
            }
        }
        return true;
    }
};
