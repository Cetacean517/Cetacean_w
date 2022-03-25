package Annotation.MyAnnotation;

public @interface MyAnnotation {
    /**
     * 自定义注解
     *  格式
     *      元注解
     *      public @interface 注解名称
     *  本质：接口，该接口默认继承Annotation接口
     *
     *  属性：接口中的抽象方法
     *      要求：
     *          1. 属性的返回类型：
     *              基本数据类型
     *              String
     *              枚举
     *              注解
     *              以上类型的数组
     *          2. 定义了属性，要给属性赋值
     *              2.1 如果定义属性时，使用default关键字给属性默认初始化值，则使用注解时，可以不进行属性的赋值
     *              2.2 如果只有一个属性需要赋值，并且属性名为value,则value可以省略, 直接定义值。
     *              2.3 数组赋值，用{}包裹。如果单值，则可以省略
     */
    int age();
    int value();
    String name() default "Winnie";
    Flower f1();
    MyAnno2 anno();
    String[] str();

    

}
