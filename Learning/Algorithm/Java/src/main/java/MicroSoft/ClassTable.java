package MicroSoft;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * 你这个学期必须选修 numCourses 门课程，记为0到numCourses - 1 。
 *
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组prerequisites 给出，其中prerequisites[i] = [ai, bi] ，表示如果要学习课程ai 则 必须 先学习课程 bi 。
 *
 * 例如，先修课程对[0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/course-schedule
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

public class ClassTable {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] inDegrees = new int[numCourses];
        List<List<Integer>> adjTable = new ArrayList<>();   // List<List<Integer>> 整数列表中套列表
        Queue<Integer> queue = new LinkedList<>();
//        创建邻接表的空表
        for(int i=0;i<numCourses;i++){
            adjTable.add(new ArrayList<>());
        }
//      统计入读，并创建领接表
        for (int[] item:prerequisites
             ) {
            inDegrees[item[1]]++;
            adjTable.get(item[0]).add(item[1]);
        }
//        根节点（入度=0的节点，入队）
        for(int i=0;i<numCourses;i++){
            if (inDegrees[i] ==0) queue.add(i);
        }
        while (!queue.isEmpty()){
            int preCourse = queue.poll();   // poll 返回第一个元素，并且从队列中删除
            numCourses--;                   // 执行次数和所需课程数一致，表示可以
            if(numCourses == 0) {return true;}
            for(int cur : adjTable.get(preCourse))  // 给每个边减1，如果这条边的入读=0，入队
                if(--inDegrees[cur] == 0) queue.add(cur);
        }
        return false;
    }
}
