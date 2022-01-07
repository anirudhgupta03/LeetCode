//https://www.codingninjas.com/codestudio/problems/leftmost-column-with-at-least-a-one_1199183?leftPanelTab=0
/************************************************************

    You can't access the binary matrix directly.
    
    The method dimensions() takes no arguments and returns an array of two integers.
    so, vector<int> res = dimensions(), where res[0] = The number of rows and res[1] = The number of columns.
	Calling the dimensions() more than once will be judged as the wrong answer and the program stops instantly.

	The method get() two takes arguments say x and y and return the binaryMatrix[x][y].
	So, int element = get(x, y).
	Calling the get() more than 2000 times will be judged as the wrong answer and the program stops instantly. 


************************************************************/

int leftmostColumn(){
	
    vector<int> dim = dimensions();
    
    int result = -1;
    int x = dim[0] - 1;
    int y = dim[1] - 1;
    
    while(x >= 0 && y >= 0){
        if(get(x,y) == 1){
            result = y;
            y--;
        }
        else{
            x--;
        }
    }
    return result;
}
