//* https://www.codingninjas.com/codestudio/problems/longest-route_1170525?leftPanelTab=1
//* https://www.youtube.com/watch?v=X1cWKI83tZo


#include <bits/stdc++.h> 

void dfs(int& answer, int temp_ans, vector<vector<int>>& m, int xs, int ys, int xd, int yd){
    if(xs == xd && ys == yd){
        answer = max(answer, temp_ans); 
        return;
    }
    
    // down
    if(xs+1 < m.size() && m[xs+1][ys] == 1){
        m[xs][ys] = 0; // marked visited
        dfs(answer, temp_ans + 1, m, xs+1, ys, xd, yd);
        m[xs][ys] = 1;
    }
    
    // up
    if(xs-1 >= 0 && m[xs-1][ys] == 1){
        m[xs][ys] = 0; // marked visited
        dfs(answer, temp_ans + 1, m, xs-1, ys, xd, yd);
        m[xs][ys] = 1;
    }
    
    // right
    if(ys+1 < m[0].size() && m[xs][ys+1] == 1){
        m[xs][ys] = 0; // marked visited
        dfs(answer, temp_ans + 1, m, xs, ys+1, xd, yd);
        m[xs][ys] = 1;
    }
    
    // left
    if(ys-1 >= 0 && m[xs][ys-1] == 1){
        m[xs][ys] = 0; // marked visited
        dfs(answer, temp_ans + 1, m, xs, ys-1, xd, yd);
        m[xs][ys] = 1;
    }
}

int longestPath(int n, int m, vector<vector<int>> &matrix, int xs, int ys, int xd, int yd) {
	// Write your code here

	if(matrix[xs][ys] == 0 || matrix[xd][yd] == 0){
            return -1;
        }
        
        int answer = 0;
        dfs(answer, 0, matrix, xs, ys, xd, yd);
        
        return (answer == 0? -1 : answer);
}