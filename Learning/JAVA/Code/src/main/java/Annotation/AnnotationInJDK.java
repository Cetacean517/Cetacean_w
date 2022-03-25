package Annotation;

import Annotation.MyAnnotation.MyAnnotation;

/**
 * 注释：
 *
 * 概念描述：
 *      JDK1.5之后的新特性
 *      说明程序的
 * 作用分类：
 *      ①编写文档：通过代码里标识的元数据生成文档【生成文档doc文档】
 *      ② 代码分析：通过代码里标识的元数据对代码进行分析【使用反射】
 *      ③编译检查：通过代码里标识的元数据让编译器能够实现基本的编译检查【Override】
 *
 * JDK内置注解：
 *      @Override：检测该注解标注的方法是否是继承自父类（接口）
 *      @Deprecated:该注解标注的内容，表示已过时
 *      @SurpressWarnings:压制警告
 *          一般用all :  @SuppressWarnings("all")
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
 *  元注解：用于描述注解的注解
 *   @Target：描述注解能够作用的位置
 *      ElementType
 *          Type(类),Method(方法),FIELD(字段)
 *   @Retention：描述注解被保留的阶段
 *      RetentionPolicy.Runtime: 保留到class字节码文件中，并被JVM读取到
 *   @Documented:描述注解是否能被抽取到api文档
 *
 *   @Inherited:描述注解是否被子类继承
 */
@SuppressWarnings("all")
public class AnnotationInJDK {
    @Override
    public String toString() {
        return super.toString();
    }


    @Deprecated
    public void beRich(){

    }

    public void beRich2(){

    }
    public void demo(){
        beRich(); // 调用方法会被划掉
        beRich2();
    }
}
