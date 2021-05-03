### 计组实验九

```java
// 主程序
MOV R0, #32H
LOOP1:  MOV A, #11H
        OUT
        //50次判断
        MOV A, R0
        SUB A, #01H
        JZ EXIT
        MOV R0, A
        CALL DELAY
        MOV A, #55H
        OUT
        // 50次判断
        MOV A, R0
        SUB A, #01H
        JZ EXIT
        MOV R0, A
        CALL DELAY
        JMP LOOP1
// 延时1秒的子程序
DELAY:  MOV A, #11H  /*十进制17，即114.8/7≈17*/
LOOP:   SUB A, #01H  /*三个时钟周期*/
        JZ EXIT      /*二个时钟周期*/
        JMP LOOP     /*二个时钟周期*/
EXIT:   RET
        END
```

```java
MOV A, #02H //给出列表的第一个数值
MOV R0, A   //将A中的数值存入A寄存器，便于后续基于A的数列输出
OUT 
CALL DELAY
MOV A, #02H 
ADD A, #01H 
OUT         //输出3
CALL DELAY

// 进入循环
BEGIN:  MOV A, R0   //将R0寄存器中存入的数据02 输入给寄存器A
        ADD A, #04H //给A加上公差4
        JC END      //若出现进位，说明数值超过FFH结束循环
        MOV R0, A   //将更新后的数值存入R0寄存器
        OUT
        CALL DELAY  //延时
        MOV A, R0   //取更新后的数值，输出另一个数列的数据
        ADD A, #01H
        JC END
        OUT CALL DELAY
        JMP BEGIN

// 延时1秒的子程序
DELAY:  MOV A, #11H  /*十进制17，即114.8/7≈17*/
LOOP:   SUB A, #01H  /*三个时钟周期*/
        JZ EXIT      /*二个时钟周期*/
        JMP LOOP     /*二个时钟周期*/

EXIT:   RET
END:    MOV A, #00H
        OUT 
        END

```