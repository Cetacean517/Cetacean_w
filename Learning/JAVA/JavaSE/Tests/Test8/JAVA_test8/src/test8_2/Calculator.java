package test8_2;

import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.WindowConstants;

public class Calculator extends JFrame implements ActionListener{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	private String operator=null; // 操作符
	private String firstInput=null; // 第一次输入的值
	private Double firstNum=0d; // 第一个操作数
	private Double secondNum=0d; // 第二个操作数
	private Double result=0d; // 结果
	private String error = "错误";
	JTextArea jTextArea = new JTextArea(8, 24);

	public void init() {
		// 获取容器
	    Container container = this.getContentPane();
	    JPanel jPanel1 = new JPanel();	//上面的输入式子组件
	    JPanel jPanel2 = new JPanel();	//下面的数字操作符

	    // 显示计算的结果,上面的面板
	    jTextArea.setFont(new Font("monospaced", Font.BOLD, 20));
	    jPanel1.add(jTextArea);

	    //显示数字和操作，下面的面板
	    jPanel2.setLayout(new GridLayout(4,4));
	    for (int i = 0; i < CConst.btnString.length(); i++) {
	    	String btnString=CConst.btnString.substring(i, i+1);
	        JButton jButton = new JButton();
	        jButton.setText(btnString);
	        jButton.setFont(new Font("微软雅黑",Font.PLAIN , 16));
	        if(btnString.matches(CConst.regex)){
	            jButton.setForeground(Color.RED);
	        }
	        jButton.addActionListener(this);
	        jPanel2.add(jButton);
	    }

	    container.setLayout(new GridLayout(2, 1));
	    container.add(jPanel1);
	    container.add(jPanel2);

	    setTitle(CConst.Title);
	    setResizable(false);
	    setSize(CConst.Frame_W, CConst.Frame_Y);
	    setLocation(CConst.frame_x, CConst.frame_y);
	    setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
	    setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
	    String clickStr = e.getActionCommand();
	    // 清空
	    if(clickStr.equals("C")){
	        this.jTextArea.setText("");
	    }
	    else if(".0123456789".indexOf(clickStr)!=-1){
	    	// 把监听到的值，连续显示到页面上去。故需要原本的值加上现在监听到的值
	        this.jTextArea.setText(jTextArea.getText()+clickStr);
	    }
	    // 当点到+-/*记录下面的值
	    else if(clickStr.matches("[\\+\\-*/]{1}")){
	    	// 记录操作符
	        operator=clickStr;
	        // 记录第一个输入的值
	        firstInput=this.jTextArea.getText();
	        // 清空
	        this.jTextArea.setText("");
	    }
	    // 当点到 等号的操作
	    else if(clickStr.equals("=")){
	        firstNum=Double.valueOf(firstInput);
	        secondNum=Double.valueOf(this.jTextArea.getText());
	        switch (operator){
	           	case "+":
	           		result=firstNum+secondNum;
	           		break;
	            case "-":
	                result = firstNum - secondNum;
	                break;
	            case "*":
	                result=firstNum*secondNum;
	                break;
	            case "/":
	                if (secondNum!=0) {
	                	result=firstNum/secondNum;
	                }else if(secondNum.equals(0.0)) {
	                	this.jTextArea.setText(error);
	                	return;
	                }
	                break;
	                
	        }
	        this.jTextArea.setText(result.toString());
	    }
	}
	
}
