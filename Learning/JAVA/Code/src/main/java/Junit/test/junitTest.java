package Junit.test;

import Junit.calculator.calculator;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class junitTest {
    /**
     * 初始化方法
     * 在所有测试前都会被执行。
     */
    @Before
    public void init(){
        System.out.println("I am init");
    }

    /**
     * 结束后方法
     * 在所有测试结束后，都会被执行。
     */
    @After
    public void close(){
        System.out.println("I am close");
    }
    /*
    * 测试add方法
    * */
    @Test
    public void addTest(){
        System.out.println("I am add");
        calculator j = new calculator();
        int result = j.add(1,2);
        Assert.assertEquals(3,result);
    }
}
