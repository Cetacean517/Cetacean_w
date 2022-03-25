package Reflect;

import Reflect.domain.Person;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;

public class getConstructor {
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
         * 2. 获取构造方法们
         *      Constructor<?>[] getConstructors()
         *      Constructor<T>[] getConstructors(类<?>... parameterTypes)
         *      Constructor<?>[] getDeclaredConstructors()
         *      Constructor<T>[] getDeclaredConstructors(类<?>... parameterTypes)
         *
         */
    //  0. 获取Person的Class对象
        Class personClass = Person.class;
        Constructor[] constructors = personClass.getConstructors();
        for (Constructor con:
             constructors) {
            System.out.println(con);
        }
        Constructor constructor = personClass.getConstructor(String.class,int.class);
        // 创建对象
        // 有参构造
        Object wendy = constructor.newInstance("Wendy",18);
        System.out.println(wendy);
        // 空参构造(2个结果一样）
        Constructor constructor1 = personClass.getConstructor();
        Object o1 = constructor1.newInstance();
        Object o2 = personClass.newInstance();
        System.out.println(o1);
        System.out.println(o2);

    }

}
