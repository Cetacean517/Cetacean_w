package Reflect;

import Reflect.domain.Person;

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;

public class getMethods {
    /**
     * Class 对象功能：
     * 1. 获取成员变量们
     *      Field[] getFields(): 获取所有public修饰的成员变量
     *      Field getField(String name): 获取指定名称的 public 修饰的成员变量
     *
     *      Field[] getDeclaredFields(): 获取所有的成员变量，不考虑修饰
     *      Field getDeclaredFields(String name):
     * 2. 获取构造方法们
     *      Constructor<?>[] getConstructors()
     *      Constructor<T>[] getConstructors(类<?>... parameterTypes)
     *      Constructor<?>[] getDeclaredConstructors()
     *      Constructor<T>[] getDeclaredConstructors(类<?>... parameterTypes)
     * 3. 获取成员方法们
     *      Method[] getMethods()
     *      Method[] getMethods(String name,类<?>... parameterTypes)
     *      Method[] getDeclaredMethods()
     *      Method[] getDeclaredMethods(String name,类<?>... parameterTypes)
     * 4. 获取类名
     *      String getName()
     */
    public static void main(String[] args) throws Exception {
        /**
         * 3. 获取成员方法们
         *      Method[] getMethods()
         *      Method[] getMethods(String name,类<?>... parameterTypes)
         *      Method[] getDeclaredMethods()
         *      Method[] getDeclaredMethods(String name,类<?>... parameterTypes)
         *
         */
    //  0. 获取Person的Class对象
        Class personClass = Person.class;
        Person p = new Person();

        // 1. 获取指定名称的成员方法
        Method flower = personClass.getMethod("flower");
        // 执行方法（无参）
        flower.invoke(p);
        // 执行方法（有参）
        Method flower1 = personClass.getMethod("flower", String.class);
        flower1.invoke(p,"Roses");
        // 获取方法的名称
        System.out.println(flower1.getName());

        // 2. 获取所有的成员方法
        Method[] methods = personClass.getMethods();
        for (Method method:
             methods) {
            System.out.println(method);
        }

        // 3. 获取类名
        String name = personClass.getName();
        System.out.println(name);


    }

}
