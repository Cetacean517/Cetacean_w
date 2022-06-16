/**
 * @time 2022/6/16 14:44
 * @version 1.00
 * @author Cetacean Wang
 */
package LeetCodeLab.Search;

public class Main {
    public static void main(String[] args) {
        // 695 岛屿的最大面积 （简单）
        int[][] grid1 = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                        {0,1,1,0,1,0,0,0,0,0,0,0,0},
                        {0,1,0,0,1,1,0,0,1,0,1,0,0},
                        {0,1,0,0,1,1,0,0,1,1,1,0,0},
                        {0,0,0,0,0,0,0,0,0,0,1,0,0},
                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                        {0,0,0,0,0,0,0,1,1,0,0,0,0}};
        int[][] grid =
                {{1,1,1,0},
                {0,1,0,0},
                {0,1,0,0},
                {0,1,1,1}};
        _695_DFS1_EASY dfs1_easy = new _695_DFS1_EASY();
        dfs1_easy.maxAreaOfIsland(grid);

    }
}
