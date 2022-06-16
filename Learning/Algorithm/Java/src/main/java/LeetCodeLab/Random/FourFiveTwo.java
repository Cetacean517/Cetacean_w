package LeetCodeLab.Random;

/*
* 思路：
* 1. 对二维数组排序
* 2. 统计交叉的个数
* */

import java.util.Arrays;
import java.util.Comparator;

public class FourFiveTwo {
    public static int findMinArrowShots(int[][] points) {
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[1] < o2[1]){
                    return -1;
                }else if(o1[1] > o2[1]){
                    return 1;
                } else{
                    return 0;
                }
            }
        });
        int min = points[0][1], count = 1;
        for(int i = 1;i<points.length;i++){
            if(min < points[i][0]){
                ++count;
                min = points[i][1];
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[][] points = new int[][]{{-2147483646,-2147483645},{2147483646,2147483647}};
        int[][] points1 = new int[][]{{10,16},{2,8},{1,6},{7,12}};
        int[][] points2 = new int[][]{{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
        FourFiveTwo.findMinArrowShots(points2);
    }
}
