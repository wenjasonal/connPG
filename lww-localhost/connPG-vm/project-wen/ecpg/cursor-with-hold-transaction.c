/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "cursor-with-hold-transaction.pgc"
#include <stdlib.h>
#include <string.h>
 
int main(){
  void print_sqlca();

  /* exec sql begin declare section */ 
      
      
  
#line 8 "cursor-with-hold-transaction.pgc"
 int caCode [ 10 ] ;
 
#line 9 "cursor-with-hold-transaction.pgc"
  struct varchar_1  { int len; char arr[ 30 ]; }  caName [ 10 ] ;
/* exec sql end declare section */
#line 10 "cursor-with-hold-transaction.pgc"


  { ECPGconnect(__LINE__, 0, "test@10.136.1.3:5432" , "lww" , "lww" , NULL, 0); }
#line 12 "cursor-with-hold-transaction.pgc"


  if(sqlca.sqlcode) 
  {
    printf("Connect database ERROR! sqlcode=%s\n", sqlca.sqlcode);
  }
  else
    printf("Connect database OK!\n");

  //删除表内记录
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from organ", ECPGt_EOIT, ECPGt_EORT);}
#line 22 "cursor-with-hold-transaction.pgc"

  //插入多条记录
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 1 , '机构1' )", ECPGt_EOIT, ECPGt_EORT);}
#line 24 "cursor-with-hold-transaction.pgc"
 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 2 , '机构2' )", ECPGt_EOIT, ECPGt_EORT);}
#line 25 "cursor-with-hold-transaction.pgc"
 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 3 , '机构3' )", ECPGt_EOIT, ECPGt_EORT);}
#line 26 "cursor-with-hold-transaction.pgc"
 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 4 , '机构4' )", ECPGt_EOIT, ECPGt_EORT);}
#line 27 "cursor-with-hold-transaction.pgc"
 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 5 , '机构5' )", ECPGt_EOIT, ECPGt_EORT);}
#line 28 "cursor-with-hold-transaction.pgc"
 
  
  if(sqlca.sqlcode)
  {
    print_sqlca();
  }

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 35 "cursor-with-hold-transaction.pgc"
 //ecpg编译时不加-t参数，此处需要显示提交,否则数据库内数据未更新！
  

  { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 38 "cursor-with-hold-transaction.pgc"
 //先begin transaction后declare cursor！
  //定义游标读取表内所有记录--with hold保持游标
  /*EXEC SQL DECLARE organ_cursor CURSOR WITH HOLD
       FOR
       SELECT organcode, organname FROM organ
       ORDER BY organcode;
  */
  //预备语句定义游标--注意最后释放
  { ECPGprepare(__LINE__, NULL, 0, "myselect", "select organcode, organname from organ order by organcode");}
#line 46 "cursor-with-hold-transaction.pgc"

  /* declare organ_cursor cursor with hold for $1 */
#line 47 "cursor-with-hold-transaction.pgc"


  //EXEC SQL BEGIN TRANSACTION; //先declare cursor 后begin transaction！
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare organ_cursor cursor with hold for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "myselect", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 50 "cursor-with-hold-transaction.pgc"


  //EXEC SQL WHENEVER NOT FOUND DO BREAK; //while里还有for循环？--报错break语句未在loop或while内？
  //EXEC SQL WHENEVER SQLERROR STOP;
  while(1)
  {
     memset(caName, 0x00, sizeof(caName));
     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch 1 from organ_cursor", ECPGt_EOIT, 
	ECPGt_int,(caCode),(long)1,(long)10,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caName),(long)30,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 57 "cursor-with-hold-transaction.pgc"

     printf("%d\n", sqlca.sqlerrd[2]);
     //if(sqlca.sqlerrd[2]==0) break; //no with hold时第二次fetch取不到值，跳出while
      //可由whenever not found do break代替此功能--数据取完结束循环
     if(sqlca.sqlcode==100)
          {
           //print_sqlca();
           break;
          }
      
     int j=0;
     for( j=0; j<sqlca.sqlerrd[2]; j++)
     {
       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update organ set organname = '易联达' where organcode = $1 ", 
	ECPGt_int,&(caCode[j]),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 70 "cursor-with-hold-transaction.pgc"

       //EXEC SQL COMMIT;
       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select organcode , organname from organ where organcode = $1 ", 
	ECPGt_int,&(caCode[j]),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(caCode[j]),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName[j]),(long)30,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 72 "cursor-with-hold-transaction.pgc"

       printf("organcode = %d, organname = %*s\n", caCode[j], caName[j].len, caName[j].arr);  
     }
   }
  //EXEC SQL WHENEVER NOT FOUND CONTINUE; //与上面break成对出现可成功编译？

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close organ_cursor", ECPGt_EOIT, ECPGt_EORT);}
#line 78 "cursor-with-hold-transaction.pgc"

  //EXEC SQL ROLLBACK;
  { ECPGtrans(__LINE__, NULL, "commit");}
#line 80 "cursor-with-hold-transaction.pgc"


  
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( '88' , '游标取后新插入值' )", ECPGt_EOIT, ECPGt_EORT);}
#line 83 "cursor-with-hold-transaction.pgc"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 84 "cursor-with-hold-transaction.pgc"

  
  printf("==========================================\n");

  { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 88 "cursor-with-hold-transaction.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update organ set organname = '易联达' where organcode = 88", ECPGt_EOIT, ECPGt_EORT);}
#line 89 "cursor-with-hold-transaction.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare organ_cursor cursor with hold for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "myselect", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 90 "cursor-with-hold-transaction.pgc"

  while(1)
  {
     memset(caName, 0x00, sizeof(caName));
     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch 2 from organ_cursor", ECPGt_EOIT, 
	ECPGt_int,(caCode),(long)1,(long)10,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caName),(long)30,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 94 "cursor-with-hold-transaction.pgc"

     printf("%d\n", sqlca.sqlerrd[2]);
     if(sqlca.sqlcode==100)
     {
         break;
     }
 
     int i=0;
     for( i=0; i<sqlca.sqlerrd[2]; i++ )
     {
        printf("organcode = %d, organname = %*s\n", caCode[i], caName[i].len, caName[i].arr);
     }
  }

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close organ_cursor", ECPGt_EOIT, ECPGt_EORT);}
#line 108 "cursor-with-hold-transaction.pgc"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 109 "cursor-with-hold-transaction.pgc"

  //EXEC SQL ROLLBACK;
 

  { ECPGdeallocate(__LINE__, 0, NULL, "myselect");}
#line 113 "cursor-with-hold-transaction.pgc"
 //释放预备语句
  { ECPGdisconnect(__LINE__, "ALL");}
#line 114 "cursor-with-hold-transaction.pgc"

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
