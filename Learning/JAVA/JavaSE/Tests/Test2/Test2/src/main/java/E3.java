import java.util.Random;
import java.util.Scanner;

/*请按照下图剪刀石头布的游戏规则，采用 switch 分支结构实现人
与机器进行剪刀石头布游戏。游戏规则和信息提示如下：
（1）每次游戏时，程序ᨀ示从命令行输入 1、2 或 3，分别作为
剪刀、石头和布；
（2）机器由程序随机生成剪刀、石头或布等三种中的一种；
（3）根据下图游戏规则，输出人与机器游戏的结果；*/
public class E3 {
    public static void e3() {
        int out = 0;
        while(true){
            System.out.println("====== 石头剪刀布 ======");
            System.out.println("选项：\n 1.剪刀  2.石头 3.布 ");
            System.out.println("请输入您的选项");
            Scanner scanner = new Scanner(System.in);
            int option = scanner.nextInt();
            if (option < 1 || option > 3)
            {
                System.out.println("请输入正确的选项。");
                continue;
            }
            Random r = new Random();
            int machine = r.nextInt(3) + 1; // 利用Random随机数生成0-2的整数
            switch (machine) {
                case 1:
                    System.out.println("machine: 剪刀");
                    break;
                case 2:
                    System.out.println("machine: 石头");
                    break;
                case 3:
                    System.out.println("machine: 布");
                    break;
            }
            out = machine - option;


            switch (out) {
                case -1:
                case 2:
                    System.out.println("You win!");
                    break;
                case 0:
                    System.out.println("Even!");
                    break;
                case 1:
                case -2:
                    System.out.println("You fail!");
                    break;
            }
//            break;
        }

    }
}
