# Chapter 8 Exercise

## 例1

<img src="https://api2.mubu.com/v3/document_image/4fa66af8-db33-4024-8810-1a6791c0c1d4-5285609.jpg" alt="image" style="zoom: 50%;" />

1. 断言实现

   ```sql
   CREATE ASSERTION ASSE1 CHECK(
       5 >= ALL(SELECT COUNT(DISTINCT (TYPE) 
                FROM EC
                GROUP BY ENO, DATE));
   
   CREATE ASSERTION ASSE2 CHECHK(
       (NOT EXISTS (SELECT * FROM EC
                    GROUP BY ENO,DATE
                    HAVING COUNT(DISTINCT (TYPE) > 5)));
   
   ```
   
2. SQL3触发器

   ```sql
   CREATE TRIGGER TRIG1
   AFTER INSERT ON EC
   REFERENCING
   	NEW AS NEWTUPLE
   WHEN (NEWTUPLE.ENO IS NOT NULL)
   BEGIN ATOMIC
   	UPDATE E	# 未超支1000，且小于单笔最大支出时，执行更新
   	SET BALANCE = BALANCE - NEWTUPLE.EXPAND,
   	CALSCORE = CALSCORE + NEWTUPLE.EXPEND * 0.1 
   	WHERE (NEWTUPLE.ENO = E.ENO) AND 
   		 (E.BALANCE - NEWTUPLE.EXPEND > -1000) AND
   		 (MAXEXPEND >= NEWTUPLE.EXPEND)
   	DELETE FROM EC	# 超支1000，或者单笔支出大于单笔时，撤销更新
   		WHERE CNO = NEWTUPLE.CNO AND
   			NEWTUPLE.EXPEND >= (SELECT MAXEXPEND FROM E 
                                     WHERE E.ENO = NEWTUPLE.ENO) OR
   			(-1000 > (SELECT BALANCE - NEWTUPLE.EXPEND FROM E 
                         	WHERE E.ENO=NEWTUPLE.ENO))
   END
   FROM EACH ROW;
   ```

## 例2

<img src="https://api2.mubu.com/v3/document_image/9dbf512c-e667-4029-890c-f79e455d7281-5285609.jpg" alt="image" style="zoom:50%;"/>

1. 表约束

   ```sql
   UNIQUE(BNAME,AUTHOR,PUBLISHER) # 利用UNIQUE实现
   ```

2. 断言

   ```sql
   CREATE ASSERTION MAX_AMOUNT CHECK(
   	NOT EXISTS (SELECT * FROM BOOK
       				WHERE AMOUNT < SELECT COUNT(*) FROM BORROW
                   					WHERE BORROW.BNO = BOOK.BNO
       									AND R_DATE IS NULL))	# 注意要未还书
   ```

3. SQL3

   ```sql
   CREATE TRIGGER TRIG1
   AFTER UPDATE OF R_DATE ON BORROW
   REFERENCING
   	OLD AS OLDTUPLE
   	NEW AS NEWTUPLE
   WHEN (NEWTUPLE.R_DATE - NEWTUPLE.B_DATE > 20)
   	UPDATE BORROW
   		SET FINE = (NEWTUPLE.R_DATE-NEWTUPLE.B_DATE-20)*0.5
   		WHERE CNO = NEWTUPLE.CNO AND	# 要加全
   			BNO = NEWTUPLE.BNO AND
   			B_DATE = NEWTUPLE.B_DATE
   FOR EACH ROW;
   ```

