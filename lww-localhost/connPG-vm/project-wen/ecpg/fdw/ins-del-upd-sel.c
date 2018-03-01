/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "ins-del-upd-sel.pgc"
#include <stdlib.h>
#include <string.h>
 
int main(){
  void print_sqlca();

  /* exec sql begin declare section */ 
      
      
  
#line 8 "ins-del-upd-sel.pgc"
 int caCode ;
 
#line 9 "ins-del-upd-sel.pgc"
  struct varchar_1  { int len; char arr[ 30 ]; }  caName ;
/* exec sql end declare section */
#line 10 "ins-del-upd-sel.pgc"


  { ECPGconnect(__LINE__, 0, "lwwtest@10.136.1.32:5432" , "lww" , "lww" , "myconn", 0); }
#line 12 "ins-del-upd-sel.pgc"


  if(sqlca.sqlcode) 
  {
    printf("Connect database ERROR! sqlcode=%s\n", sqlca.sqlcode);
  }
  else
    printf("Connect database OK!\n");

    /*验证当前连接隔离级别*/
    /* exec sql begin declare section */
     
    
#line 23 "ins-del-upd-sel.pgc"
 char level [ 30 ] ;
/* exec sql end declare section */
#line 24 "ins-del-upd-sel.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "show default_transaction_isolation", ECPGt_EOIT, 
	ECPGt_char,(level),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 25 "ins-del-upd-sel.pgc"

    printf("Current transaction isolation level is \"%s\"\n", level);
    //更改隔离级别
    //EXEC SQL set default_transaction_isolation to "repeatable read"; //level:read committed; repeatable read; serializable; read uncommitted
    //EXEC SQL SHOW default_transaction_isolation into :level;
    //printf("Update transaction isolation level is \"%s\"\n", level);


  //drop表organ_ecpg
  //EXEC SQL DROP TABLE organ_ecpg;
  //新建表organ_ecpg
  //EXEC SQL CREATE TABLE organ_ecpg (orgcode int primary key not null, orgname varchar(30));

  //清空表--多程序复用表
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from organ_ecpg", ECPGt_EOIT, ECPGt_EORT);}
#line 39 "ins-del-upd-sel.pgc"


  //插入记录
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ_ecpg values ( 1 , '机构' )", ECPGt_EOIT, ECPGt_EORT);}
#line 42 "ins-del-upd-sel.pgc"

  //EXEC SQL COMMIT;
  //printf("insert success, sqlca.sqlcode = %s \n", sqlca.sqlcode);

  //EXEC SQL INSERT INTO organ_ecpg values (111, 'psbc'); 
  { ECPGtrans(__LINE__, NULL, "commit");}
#line 47 "ins-del-upd-sel.pgc"
 //ecpg编译时不加-t参数，此处需要显示提交,否则数据库内数据未更新！若此处未写后续只要出现commit均可提交成功！

 
  if(sqlca.sqlcode)
  {
    print_sqlca();
  }

  
  //读取插入的单条记录
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select orgcode , orgname from organ_ecpg", ECPGt_EOIT, 
	ECPGt_int,&(caCode),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)30,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 57 "ins-del-upd-sel.pgc"

  printf("insert one record:\n orgcode = %d, orgname = %*s\n", caCode, caName.len, caName.arr); //NOTE: varchar type

  //sleep (5); //just test

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update organ_ecpg set orgname = '机构更名'", ECPGt_EOIT, ECPGt_EORT);}
#line 62 "ins-del-upd-sel.pgc"

  //EXEC SQL UPDATE organ_ecpg SET orgname = 'psbc rename';
  { ECPGtrans(__LINE__, NULL, "commit");}
#line 64 "ins-del-upd-sel.pgc"
 //ecpg编译时不加-t参数，此处需要显示提交,否则数据库内数据未更新！
  //读取update后记录
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select orgcode , orgname from organ_ecpg", ECPGt_EOIT, 
	ECPGt_int,&(caCode),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)30,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 66 "ins-del-upd-sel.pgc"

  printf("after update orgname:\n orgcode = %d, orgname = %*s\n", caCode, caName.len, caName.arr); //NOTE: varchar type

  //sleep (5); //just test

  //删除表内记录
  //EXEC SQL DELETE FROM organ_ecpg;
  //EXEC SQL COMMIT; 
  //sleep (5); //just test
  //重连DB
  /*EXEC SQL DISCONNECT myconn;
  EXEC SQL CONNECT TO test@10.136.1.143:5432 USER lww/lww;
  if(sqlca.sqlcode)
  {
    printf("Connect database ERROR! sqlcode=%s\n", sqlca.sqlcode);
  }
  else
    printf("Connect database OK!\n");
 */
  

  //验证是否删除
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select orgcode , orgname from organ_ecpg", ECPGt_EOIT, 
	ECPGt_int,&(caCode),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)30,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 88 "ins-del-upd-sel.pgc"

  printf("after delete:\n orgcode = %d, orgname = %*s\n", caCode, caName.len, caName.arr); //NOTE: varchar type
 
  { ECPGdisconnect(__LINE__, "ALL");}
#line 91 "ins-del-upd-sel.pgc"

  return 0;
}

void print_sqlca()
{
  fprintf(stderr, "==== sqlca ====\n");
  fprintf(stderr, "sqlcode: %ld\n", sqlca.sqlcode);
  fprintf(stderr, "sqlerrm.sqlerrml: %d\n", sqlca.sqlerrm.sqlerrml);
  fprintf(stderr, "sqlerrm.sqlerrmc: %s\n", sqlca.sqlerrm.sqlerrmc);
  fprintf(stderr, "sqlerrd: %ld %ld %ld %ld %ld %ld\n", sqlca.sqlerrd[0],sqlca.sqlerrd[1],sqlca.sqlerrd[2],
  sqlca.sqlerrd[3],sqlca.sqlerrd[4],sqlca.sqlerrd[5]);
  fprintf(stderr, "sqlwarn: %d %d %d %d %d %d %d %d\n", sqlca.sqlwarn[0], sqlca.sqlwarn[1], sqlca.sqlwarn[2],
  sqlca.sqlwarn[3], sqlca.sqlwarn[4], sqlca.sqlwarn[5],
  sqlca.sqlwarn[6], sqlca.sqlwarn[7]);
  fprintf(stderr, "sqlstate: %5s\n", sqlca.sqlstate);
  fprintf(stderr, "===============\n");
}
