package test8_2;

import java.awt.Toolkit;

//常量都放在这里，以后只需要修改这里即可。 并且该常量都要设置为静态变量，这样别人才能访问到
public class CConst {
	//获取屏幕的宽度和高度
	public static  int Screen_W= Toolkit.getDefaultToolkit().getScreenSize().width;
	public static  int Screen_Y=Toolkit.getDefaultToolkit().getScreenSize().height;
	
	//获取窗口的宽度和高度
	public static  int Frame_W=300;
	public static  int Frame_Y=300;
	
	//获取中心点位置
	public static int frame_x=(Screen_W-Frame_W)/2;
	public static int frame_y=(Screen_Y-Frame_Y)/2;
	
	//计算机标题
	public static String Title="Calculator";
	
	//面板按钮顺序，C是清屏
	public static String btnString="0123456789+-*/C=";
	
	//正则表达式
	public static String regex="[\\+\\-*/.=C]";
}
