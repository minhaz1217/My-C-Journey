/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 417. Pacific Atlantic Water Flow
Problem Link: https://leetcode.com/problems/pacific-atlantic-water-flow/
Complexity: O(m*n)
Date : 12 / Jul / 2022

Comment: Just run bfs from the ocean and travel only to higher locations. Then check where both ocean was visited.
*/

public class Solution {
    public class Pair{
        public int first {get;set;}
        public int second {get;set;}
        public Pair(int a, int b){
            this.first = a;
            this.second = b;
        }
    }

    public void Print(int[,] arr){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                Console.Write($"{arr[i,j]} ");
            }
            Console.WriteLine("");
        }
    }

    public bool IsInBound(int r, int c){
        if(r < 0 || r>=m || c <0 || c>=n){
            return false;
        }
        return true;
    }

    public void Print(string s){
        Console.WriteLine(s);
    }


    int m,n;
    int[] dx = {0,0,1,-1};
    int[] dy = {1,-1,0,0};

    // Normal BFS
    public void Calculate(int[][] heights, bool[,]visited, int isAtlanticCalculation){
        var q = new Queue<Pair>();

        if(isAtlanticCalculation == 0){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(j==0 || i==0){
                        var startX = i;
                        var startY = j;
                        q.Enqueue(new Pair(startX,startY));
                    }

                }
            }
        }else{
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i == m-1 || j==n-1){
                        var startX = i;
                        var startY = j;
                        q.Enqueue(new Pair(startX,startY));
                    }
                }
            }
        }

        while(q.Count > 0){
            var p = q.Dequeue();

            if(visited[p.first,p.second]){
                continue;
            }

            visited[p.first, p.second] = true;
            for(int i=0;i<dx.Length;i++){
                var vx = p.first + dx[i];
                var vy = p.second + dy[i];

                if(IsInBound(vx,vy)){
                    if(!visited[vx,vy] && heights[vx][vy] >= heights[p.first][p.second]){
                        q.Enqueue(new Pair(vx,vy));
                    }
                }
            }
        }
    }


    public IList<IList<int>> PacificAtlantic(int[][] heights) {
        m = heights.Length;
        n = heights[0].Length;

        var outputs = new List<IList<int>>();
        bool[,] pacificOceanCost = new bool[m+2,n+2];
        bool[,] atlanticOceanCost = new bool[m+2,n+2];


        Calculate(heights, pacificOceanCost, 0);
        Calculate(heights, atlanticOceanCost, 1);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atlanticOceanCost[i,j] && pacificOceanCost[i,j]){
                    var point = new List<int>();
                    point.Add(i);
                    point.Add(j);
                    outputs.Add(point);
                }
            }
        }

        return outputs;
    }
}
