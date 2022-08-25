/**
 * @time 2022/8/21 18:45
 * @version 1.00
 * @author Cetacean Wang
 */
package LeetCodeLab.Search;

import java.util.ArrayList;
import java.util.List;

public class _417_DFS_Medium {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] test1 = {{2,1},{1,2}};
        int[][] test2 = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
        int[][] test3 = {{1,1},{1,1},{1,1}};
        System.out.println(solution.pacificAtlantic(test3));
    }
}

class Solution{
    static int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int[][] heights;        // array
    int m,n;                // m: height, n: width

    public void dfs(boolean[][] result, int row, int col){
        if(result[row][col]){
            return;
        }
        result[row][col] = true;
        for(int[] dir:dirs){
            int newRow = row+dir[0];
            int newCol = col+dir[1];
            if(newRow >=0 && newRow < m && newCol >= 0 && newCol < n && heights[row][col] <= heights[newRow][newCol]){
                dfs(result,newRow,newCol);
            }
        }

    }
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        this.heights = heights;         // array
        this.m = heights.length;        // rows of array
        this.n = heights[0].length;     // cols of array
        boolean[][] atlantic = new boolean[m][n];
        boolean[][] pacific = new boolean[m][n];

        for (int i = 0; i < n; i++) {   // top row
            dfs(pacific,0,i);
        }
        for (int j = 0; j < m; j++) {   // left col
            dfs(pacific,j,0);
        }
        for (int i = 0; i < n; i++) {   // bottom row
            dfs(atlantic,m-1,i);
        }
        for (int j = 0; j < m; j++) {   // right col
            dfs(atlantic,j,n-1);
        }

        ArrayList<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(pacific[i][j]&&atlantic[i][j]){
                    ArrayList<Integer> position = new ArrayList<>();
                    position.add(i);
                    position.add(j);
                    result.add(position);
                }
            }
        }
        return result;
    }
}