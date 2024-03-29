//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/#
//Method - 1
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            q.push(i);
        }
        
        while(q.size() != 1){
            
            int p1 = q.front();
            q.pop();
            int p2 = q.front();
            q.pop();
            
            if(M[p1][p2]){
                q.push(p2);
            }
            else{
                q.push(p1);
            }
        }
        int celeb = q.front();
        
        for(int j = 0; j < n; j++){
            if(j != celeb){
                if(M[celeb][j] == 1){
                    return -1;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(i != celeb){
                if(M[i][celeb] == 0){
                    return -1;
                }
            }
        }
        return celeb;
    }
};

//Method - 2
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        if(n == 1){
            return 0;
        }

        int possibleCelebrity = -1;

        for(int i = 0; i < n; i++){
            if(possibleCelebrity == -1){
                possibleCelebrity = i;
                continue;
            }
            if(M[possibleCelebrity][i] && M[i][possibleCelebrity]){
                possibleCelebrity = -1;
            }
            else if(M[possibleCelebrity][i]){
                possibleCelebrity = i;
            }
        }
        if(possibleCelebrity == -1) return -1;
        
        for(int i = 0; i < n; i++){
            if(i == possibleCelebrity) continue;
            if(M[possibleCelebrity][i] || !M[i][possibleCelebrity]){
                return -1;
            }
        }
        return possibleCelebrity;
    }
};
