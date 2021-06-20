class AuthenticationManager {
public:
    map<string,int> m;
    int n;
    AuthenticationManager(int timeToLive) {
        n = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        m[tokenId] = currentTime + n;
    }
    
    void renew(string tokenId, int currentTime) {
        
        if(m.find(tokenId) != m.end() && m[tokenId] > currentTime){
            m[tokenId] = currentTime + n;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        
        int count = 0;
        
        for(auto x: m){
            if(x.second > currentTime){
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
