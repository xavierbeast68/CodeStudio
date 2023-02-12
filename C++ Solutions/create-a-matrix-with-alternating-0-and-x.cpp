//* https://www.geeksforgeeks.org/create-a-matrix-with-alternating-rectangles-of-0-and-x/
//* https://www.codingninjas.com/codestudio/problems/create-a-matrix-with-alternating-x-and-0_981321


#include <bits/stdc++.h> 
vector<vector<char>> constructMatrix(int n, int m)
{
    //    Write your code here.

    vector<vector<char>> ans(n, vector<char> (m));

    int startRow = 0, endRow = n-1;
    int startCol = 0, endCol = m-1;
    int levels = 1;
    char ch = 'X';
    while(startRow <= endRow && startCol <= endCol){
        // Top
        for(int col = startCol; col <= endCol; col++){
            ans[startRow][col] = ch;
        }

        // Right
        for(int row = startRow+1; row <= endRow; row++){
            ans[row][endCol] = ch;
        }
        
        // Bottom
        for(int col = endCol-1; col >= startCol; col--){
            if(startRow == endRow){
                break;
            }
            ans[endRow][col] = ch;
        }

        // Left
        for(int row = endRow-1; row > startRow; row--){
            if(startCol == endCol){
                break;
            }
            ans[row][startCol] = ch;
        }
        
        // Updations->
        startRow++, endRow--;
        startCol++, endCol--;
        if(levels%2 == 1){
            ch = '0';
            levels++;
        } else{
            ch = 'X';
            levels++;
        }
    }

        return ans;
}