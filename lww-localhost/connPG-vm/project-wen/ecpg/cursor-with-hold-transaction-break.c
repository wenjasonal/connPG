/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "cursor-with-hold-transaction-break.pgc"
#include <stdlib.h>
#include <string.h>
 
int main(){
  void print_sqlca();

  /* exec sql begin declare section */ 
      
      
  
#line 8 "cursor-with-hold-transaction-break.pgc"
 char caCode [ 10 ] ;
 
#line 9 "cursor-with-hold-transaction-break.pgc"
 char caName [ 10 ] [ 30 ] ;
/* exec sql end declare section */
#line 10 "cursor-with-hold-transaction-break.pgc"


  { ECPGconnect(__LINE__, 0, "test@10.136.1.143:5432" , "lww" , "lww" , NULL, 0); }
#line 12 "cursor-with-hold-transaction-break.pgc"


  if(sqlca.sqlcode) 
  {
    printf("Connect database ERROR! sqlcode=%s\n", sqlca.sqlcode);
  }
  else
    printf("Connect database OK!\n");

  //删除表内记录
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from organ", ECPGt_EOIT, ECPGt_EORT);}
#line 22 "cursor-with-hold-transaction-break.pgc"

  //插入多条记录
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 1 , '机构1' )", ECPGt_EOIT, ECPGt_EORT);}
#line 24 "cursor-with-hold-transaction-break.pgc"
 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 2 , '机构2' )", ECPGt_EOIT, ECPGt_EORT);}
#line 25 "cursor-with-hold-transaction-break.pgc"
 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 3 , '机构3' )", ECPGt_EOIT, ECPGt_EORT);}
#line 26 "cursor-with-hold-transaction-break.pgc"
 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 4 , '机构4' )", ECPGt_EOIT, ECPGt_EORT);}
#line 27 "cursor-with-hold-transaction-break.pgc"
 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 5 , '机构5' )", ECPGt_EOIT, ECPGt_EORT);}
#line 28 "cursor-with-hold-transaction-break.pgc"
 
  
  if(sqlca.sqlcode)
  {
    print_sqlca();
  }

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 35 "cursor-with-hold-transaction-break.pgc"
 //ecpg编译时不加-t参数，此处需要显示提交,否则数据库内数据未更新！
  

  { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 38 "cursor-with-hold-transaction-break.pgc"
 //先begin transaction后declare cursor！
  //预备语句定义游标--注意最后释放
  { ECPGprepare(__LINE__, NULL, 0, "myselect", "select organcode, organname from organ order by organcode");}
#line 40 "cursor-with-hold-transaction-break.pgc"

  /* declare organ_cursor cursor with hold for $1 */
#line 41 "cursor-with-hold-transaction-break.pgc"


  //EXEC SQL BEGIN TRANSACTION; //先declare cursor 后begin transaction！
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare organ_cursor cursor with hold for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "myselect", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 44 "cursor-with-hold-transaction-break.pgc"


  memset(caCode, 0x00, sizeof(caCode));
  memset(caName, 0x00, sizeof(caName));

  /* exec sql whenever not found  break ; */
#line 49 "cursor-with-hold-transaction-break.pgc"
 //while里还有for循环？--报错break语句未在loop或while内？
  /* exec sql whenever sqlerror  stop ; */
#line 50 "cursor-with-hold-transaction-break.pgc"

   while(1)
   {
     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from organ_cursor", ECPGt_EOIT, 
	ECPGt_char,(caCode),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caName),(long)30,(long)10,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 53 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;
#line 53 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 53 "cursor-with-hold-transaction-break.pgc"

       printf("organcode = %s, organname = %s\n", caCode, caName); 
   }
  
  /* exec sql whenever not found  continue ; */
#line 57 "cursor-with-hold-transaction-break.pgc"
 //出循环后必须复位break设置，否则添加后续操作时break报错（within out loop...）
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update organ set organname = '易联达' where organcode = 3", ECPGt_EOIT, ECPGt_EORT);
#line 58 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 58 "cursor-with-hold-transaction-break.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close organ_cursor", ECPGt_EOIT, ECPGt_EORT);
#line 59 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 59 "cursor-with-hold-transaction-break.pgc"

  //EXEC SQL ROLLBACK;
  { ECPGtrans(__LINE__, NULL, "commit");
#line 61 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 61 "cursor-with-hold-transaction-break.pgc"

  
  printf("==========================================\n");

  //EXEC SQL DEALLOCATE PREPARE myselect; //释放预备语句
  
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( '88' , '游标取后新插入值' )", ECPGt_EOIT, ECPGt_EORT);
#line 67 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 67 "cursor-with-hold-transaction-break.pgc"

  { ECPGtrans(__LINE__, NULL, "commit");
#line 68 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 68 "cursor-with-hold-transaction-break.pgc"


  { ECPGtrans(__LINE__, NULL, "begin transaction");
#line 70 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 70 "cursor-with-hold-transaction-break.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare organ_cursor cursor with hold for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "myselect", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 71 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 71 "cursor-with-hold-transaction-break.pgc"

  /* exec sql whenever not found  break ; */
#line 72 "cursor-with-hold-transaction-break.pgc"

  while(1)
  {
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from organ_cursor", ECPGt_EOIT, 
	ECPGt_char,(caCode),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caName),(long)30,(long)10,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 75 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;
#line 75 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 75 "cursor-with-hold-transaction-break.pgc"

    printf("organcode = %s, organname = %s\n", caCode, caName);
  }

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close organ_cursor", ECPGt_EOIT, ECPGt_EORT);
#line 79 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 79 "cursor-with-hold-transaction-break.pgc"

  { ECPGtrans(__LINE__, NULL, "commit");
#line 80 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 80 "cursor-with-hold-transaction-break.pgc"


  { ECPGdeallocate(__LINE__, 0, NULL, "myselect");
#line 82 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 82 "cursor-with-hold-transaction-break.pgc"
 //释放预备语句--最后断开连接之前
  { ECPGdisconnect(__LINE__, "ALL");
#line 83 "cursor-with-hold-transaction-break.pgc"

if (sqlca.sqlcode < 0) exit (1);}
#line 83 "cursor-with-hold-transaction-break.pgc"

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
