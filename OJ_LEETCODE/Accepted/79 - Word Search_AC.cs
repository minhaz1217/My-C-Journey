/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 79. Word Search
Problem Link: https://leetcode.com/problems/word-search/
Complexity: O(k * m * n)
Date : 12 / Jul / 2022

Comment: Just run BFS from the first letter of the word. Careful about visiting the first location when calling dfs.
*/

public class Solution {

    bool wordFound = false;
    int[] dx = {0,0,1,-1};
    int[] dy = {1,-1,0,0};
    int m,n;

    public bool IsInBound(int x, int y){
        if(x < 0 || y < 0 || x >= m || y>=n){
            return false;
        }
        return true;
    }
    public void DFS(char[][] board, string word, bool[,]visited, int x, int y, int pos){
        if(wordFound || pos >= word.Length){
            return;
        }

        if(pos == word.Length-1){
            wordFound = true;
            return;
        }

        for(int i=0;i<dx.Length;i++){
            var vx = x + dx[i];
            var vy = y + dy[i];

            if(!wordFound && IsInBound(vx,vy) && !visited[vx,vy] && board[vx][vy] == word[pos+1]){
                visited[vx,vy] = true;
                DFS(board, word, visited, vx,vy, pos+1);
                visited[vx,vy] = false;
            }
        }
    }

    public bool Exist(char[][] board, string word) {
        m = board.Length;
        n = board[0].Length;


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!wordFound && board[i][j] == word[0]){
                    bool[,] visited = new bool[m+4,n+4];
                    visited[i,j] = true;
                    DFS(board, word,visited, i,j,0);
                }
            }
        }
        return wordFound;
    }
}
