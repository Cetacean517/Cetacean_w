import java.util.Scanner;

public class E3 {
    public static int recursionBinarySearch(int[] arr,int key,int low,int high){

        if(key < arr[low] || key > arr[high] || low > high){
            return -1;
        }

        int middle = (low + high) / 2;			//初始中间位置
        if(arr[middle] > key){
            //比关键字大则关键字在左区域
            return recursionBinarySearch(arr, key, low, middle - 1);
        }else if(arr[middle] < key){
            //比关键字小则关键字在右区域
            return recursionBinarySearch(arr, key, middle + 1, high);
        }else {
            return middle;
        }

    }

    public void E3() {
        // 1. 读入一个任意长度的数组，用空格分割
        Scanner s1 = new Scanner(System.in);
        System.out.println("请输入一个数组,以回车结束：(示例：1 2 3 4 5 6 7 8 9...)");
        String str = s1.nextLine();                   // 读入一行string
        String[] str_split = str.split("\\s+"); // 根据空格进行分割
        int[] arr = new int[str_split.length];
        for(int i =0;i< str_split.length;i++){
            arr[i] = Integer.parseInt(str_split[i]);    // 将string 类型转换为int类型
        }
        // 2. bubble sort
        for(int i =1;i< str_split.length;i++) {
            boolean flag = true;
            for (int j = 0; j < str_split.length - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                    flag = false;
                }
            }
            if (flag) {
                break;
            }
        }
        // 3. 二分查找
        Scanner s2 = new Scanner(System.in);
        System.out.println("请输入一个需要查找的整数：");
        int key = s2.nextInt();
        int pos = recursionBinarySearch(arr, key,0, str_split.length-1) + 1;
        if(pos>-1) {
            System.out.println("在数组中，位置：" + pos);
        }else{
            System.out.println("没有找到");
        }
    }
}


