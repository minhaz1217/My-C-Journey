/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 54. Spiral Matrix
Problem Link: https://leetcode.com/problems/spiral-matrix/
Date :

Comment: I've solved it using direction function. Another way to solve is closing the box.
            Like at first the maxRowSize is = maxRow and start from 0, after first row iteration, the startRow will be +1
            same way after we finish going to Top to bottom, we'll decrease the maxCol to -1.
*/

public class Solution {

    enum Direction{
        Right = 5,
        Down = 10,
        Left = 15,
        Up = 20

    }

    Direction d = Direction.Right;


    Direction NextDirection(Direction currentDirection){
        switch(currentDirection){
            case Direction.Right:
                return Direction.Down;
            case Direction.Down:
                return Direction.Left;
            case Direction.Left:
                return Direction.Up;
            case Direction.Up:
                return Direction.Right;
            default:
                return Direction.Left;
        }

    }

    int NextRow(Direction currentDirection, int currentRow){

        switch(currentDirection){
            case Direction.Down:
                return currentRow + 1;
            case Direction.Up:
                return currentRow - 1;
            default:
                return currentRow;
        }
    }



    int NextCol(Direction currentDirection, int currentCol){
        switch(currentDirection){
            case Direction.Right:
                return currentCol + 1;
            case Direction.Left:
                return currentCol - 1;
            default:
                return currentCol;
        }
    }

    public IList<int> SpiralOrder(int[][] matrix) {
        int maxRow = matrix.Length, maxCol = matrix[0].Length;
        d = Direction.Right;
        bool [,] visited = new bool[maxRow,maxCol];
        int i=0,j=0;
        var output = new List<int>();

        i=0;
        j=0;
        while(true){
            if(output.Count >= maxRow*maxCol){
                break;
            }

            if(visited[i,j] == false){
                visited[i,j] = true;
                output.Add(matrix[i][j]);
            }
            if(d == Direction.Right){
                if(j+1 >=maxCol || visited[i,j+1] ){
                    d = NextDirection(d);
                }
            }else if(d == Direction.Down){
                if(i+1 >=maxRow || visited[i+1,j]){
                    d = NextDirection(d);
                }
            }else if(d == Direction.Left){
                if(j-1 < 0 || visited[i,j-1]){
                    d = NextDirection(d);
                }
            }else if(d == Direction.Up){
                if(i-1 < 0 || visited[i-1,j]){
                    d = NextDirection(d);
                }
            }

            i  = NextRow(d,i);
            j = NextCol(d,j);
        }

        return output;
    }
}
