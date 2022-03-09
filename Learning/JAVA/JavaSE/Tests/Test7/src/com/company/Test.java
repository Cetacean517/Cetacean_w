package com.company;

import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        RegexChk test = new RegexChk();

        boolean a = true;
        while (a) {
            int choice = 0;
            System.out.println("请输入您要验证的类型:1.整数 2.手机号码 3.电子邮箱 4.邮政编码 5.身份证号码 0.退出");
            Scanner x = new Scanner(System.in);
            if (x.hasNextInt())
                choice = x.nextInt();
            else
                System.out.println("请做出有效选择");
            switch (choice) {
                case 0:
                    a = false;
                    break;
                case 1:
                    Scanner zheng = new Scanner(System.in);
                    System.out.println("请输入需要验证的整数：");
                    test.zheng = zheng.nextLine();
                    test.IfZheng();
                    break;
                case 2:
                    Scanner phone = new Scanner(System.in);
                    System.out.println("请输入需要验证的手机号码：");
                    test.phone = phone.nextLine();
                    if (test.IfPhone())
                        System.out.println("是手机号码。");
                    else
                        System.out.println("不是手机号码。");
                    break;
                case 3:
                    Scanner email = new Scanner(System.in);
                    System.out.println("请输入需要验证的电子邮箱：");
                    test.email = email.nextLine();
                    if (test.IfEmail())
                        System.out.println("是电子邮箱。");
                    else
                        System.out.println("不是电子邮箱。");
                    break;
                case 4:
                    Scanner post = new Scanner(System.in);
                    System.out.println("请输入需要验证的邮政编码：");
                    test.post = post.nextLine();
                    if (test.IfPost())
                        System.out.println("是邮政编码。");
                    else
                        System.out.println("不是邮政编码。");
                    break;
                case 5:
                    Scanner identification = new Scanner(System.in);
                    System.out.println("请输入需要验证的身份证号码：");
                    test.indentification = identification.nextLine();
                    if (test.IfIndentification())
                        System.out.println("是身份证号码。");
                    else
                        System.out.println("不是身份证号码。");
                    break;
                default:
                    break;
            }
        }
    }
}
