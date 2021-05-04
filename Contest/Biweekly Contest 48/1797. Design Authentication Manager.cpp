class AuthenticationManager {
public:
    
    map<string,int> token;
    int n;
    
    AuthenticationManager(int timeToLive) {
        n = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        
        token[tokenId] = currentTime + n;
    }
    
    void renew(string tokenId, int currentTime) {
        
        map<string,int> :: iterator it;
        
        for(it = token.begin(); it != token.end(); it++){
            
            if(it->first == tokenId && it->second > currentTime){
                token[it->first] = currentTime + n;
            }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {

        map<string,int> :: iterator it;
        int count = 0;
        for(it = token.begin(); it != token.end(); it++){
            
            if(it->second > currentTime){
                count++;
            }
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
