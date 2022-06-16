/**
 * @time 2022/6/16 14:41
 * @version 1.00
 * @author Cetacean Wang
 * @title 695. 岛屿的最大面积
 * @type  排序
 * @question:
 * 给你一个大小为 m x n 的二进制矩阵 grid 。
 *
 * 岛屿是由一些相邻的1(代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。
 * 你可以假设grid 的四个边缘都被 0（代表水）包围着。
 *
 * 岛屿的面积是岛上值为 1 的单元格的数目。
 *
 * 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/max-area-of-island
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
package LeetCodeLab.Search;

import javafx.util.Pair;

import java.util.Stack;

public class _695_DFS1_EASY {
    public int maxAreaOfIsland(int[][] grid) {
        // 1. 获取矩阵的长宽
        int height = grid.length, width = height > 0 ? grid[0].length : 0;

        // 2. 初始化变量
        int max_area = 0, local_area = 0;                       // 最大面积, 局部面积
        int x,y;                                                // 新产生的位置坐标(x , y)
        int[] direction = {-1, 0, 1, 0, -1};                    // 位置向量，用于推导新位置
        Stack<Pair<Integer,Integer>> area = new Stack<>();

        // 3. 利用栈求算局部面积，擂台比较大小。
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] == 1){                            // 格子有面积时，设置局部面积为1.
                    local_area = 1;
                    grid[i][j] = 0;                             // 走过的格子置零，避免重复计算
                    area.push(new Pair<>(i,j));
                    while (!area.isEmpty()){                    // 栈非空时，不断读入新的格子计算面积大小。
                        Pair<Integer, Integer> pos = area.pop();
                        Integer i1 = pos.getKey();
                        Integer j1 = pos.getValue();
                        for (int k = 0; k < 4; k++) {
                            x = i1 + direction[k];
                            y = j1 + direction[k+1];
                            if( x >= 0 && x < height &&
                                y >= 0 && y < width && grid[x][y] == 1){
                                grid[x][y] = 0;
                                local_area++;
                                area.push(new Pair<>(x,y));
                            }
                        }
                    }
                    max_area = Math.max(local_area,max_area);
                }
            }
        }
        return max_area;
    }
}
















