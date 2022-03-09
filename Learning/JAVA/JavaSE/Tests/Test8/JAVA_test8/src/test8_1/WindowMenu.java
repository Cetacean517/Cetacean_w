package test8_1;

import javax.swing.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;

public class WindowMenu extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	JMenuBar menubar;	//创建菜单条
	JMenu menu1, menu2, menu3, menu4, subMenu;	//创建菜单
	JMenuItem  item1, item2, item3, item4, item5, item6;	//创建菜单项
	    
	public WindowMenu(){} 
	public WindowMenu(String s,int x,int y,int w,int h) {
	   init(s);
	   setLocation(x,y);
	   setSize(w,h);
	   setVisible(true);
	   setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); 
	}
	
	void init(String s){
	    setTitle(s);             //设置窗口的标题   
	    menubar=new JMenuBar(); 
	    menu1=new JMenu("文件");
	    menu2=new JMenu("编辑");
	    menu3=new JMenu("视图");
	    menu4=new JMenu("帮助");
	    subMenu=new JMenu("文件格式");  
	    item1=new JMenuItem("新建文件");
	    item2=new JMenuItem("打开文件");
	    item3=new JMenuItem("关闭文件");
	    item4=new JMenuItem("保存文件");
	    item5=new JMenuItem("文件另存为");
	    item6=new JMenuItem("退出");
	    item1.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_N,InputEvent.CTRL_MASK));	//快捷打开键组合
	    item2.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_O,InputEvent.CTRL_MASK));
	    item3.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_C,InputEvent.CTRL_MASK));
	    item4.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S,InputEvent.CTRL_MASK));
	    item6.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_E,InputEvent.CTRL_MASK));
	    
	    menu1.add(item1);
	    menu1.add(item2);
	    menu1.add(item3);
	    menu1.addSeparator();   //在菜单之间增加分隔线
	    menu1.add(subMenu);		//“文件格式”子菜单
	    //子菜单“文件格式”菜单项
	    subMenu.add(new JMenuItem("Java文件")); 
	    subMenu.add(new JMenuItem("Txt文件"));
	    subMenu.addSeparator();	//添加分隔线
	    subMenu.add(new JMenuItem("只读"));
	    subMenu.add(new JMenuItem("可写"));
	    menu1.add(item4);
	    menu1.add(item5);
	    menu1.addSeparator();   //在菜单之间增加分隔线
	    menu1.add(item6);

	    
	        
	    menubar.add(menu1);
	    menubar.add(menu2);
	    menubar.add(menu3);
	    menubar.add(menu4);
	    setJMenuBar(menubar);	//将菜单条添加到窗口
	
	} 
}
	

