/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "cursor.pgc"
#include <stdlib.h>
#include <string.h>
 
int main(){
  void print_sqlca();

  /* exec sql begin declare section */ 
      
      
  
#line 8 "cursor.pgc"
 int caCode [ 10 ] ;
 
#line 9 "cursor.pgc"
  struct varchar_1  { int len; char arr[ 30 ]; }  caName [ 10 ] ;
/* exec sql end declare section */
#line 10 "cursor.pgc"


  { ECPGconnect(__LINE__, 0, "test@10.136.1.143:5432" , "lww" , "lww" , NULL, 0); }
#line 12 "cursor.pgc"


  if(sqlca.sqlcode) 
  {
    printf("Connect database ERROR! sqlcode=%s\n", sqlca.sqlcode);
  }
  else
    printf("Connect database OK!\n");

  //删除表内记录
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from organ", ECPGt_EOIT, ECPGt_EORT);}
#line 22 "cursor.pgc"

  //插入多条记录
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 1 , '机构1' )", ECPGt_EOIT, ECPGt_EORT);}
#line 24 "cursor.pgc"
 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 2 , '机构2' )", ECPGt_EOIT, ECPGt_EORT);}
#line 25 "cursor.pgc"
 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 3 , '机构3' )", ECPGt_EOIT, ECPGt_EORT);}
#line 26 "cursor.pgc"
 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 4 , '机构4' )", ECPGt_EOIT, ECPGt_EORT);}
#line 27 "cursor.pgc"
 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 5 , '机构5' )", ECPGt_EOIT, ECPGt_EORT);}
#line 28 "cursor.pgc"
 
  
  if(sqlca.sqlcode)
  {
    print_sqlca();
  }

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 35 "cursor.pgc"
 //ecpg编译时不加-t参数，此处需要显示提交,否则数据库内数据未更新！
  //定义游标读取表内所有记录
  /* declare organ_cursor cursor for select organcode , organname from organ order by organcode */
#line 39 "cursor.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare organ_cursor cursor for select organcode , organname from organ order by organcode", ECPGt_EOIT, ECPGt_EORT);}
#line 40 "cursor.pgc"

 
  while(1)
  {
     memset(caName, 0x00, sizeof(caName));
     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch 2 organ_cursor", ECPGt_EOIT, 
	ECPGt_int,(caCode),(long)1,(long)10,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caName),(long)30,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 45 "cursor.pgc"

     printf("%d\n", sqlca.sqlerrd[2]);
     if(sqlca.sqlcode==100)
          {
           //print_sqlca();
           break;
          }
     
     int i=0;
     for( i=0; i<sqlca.sqlerrd[2]; i++)
           printf("organcode = %d, organname = %*s\n", caCode[i], caName[i].len, caName[i].arr); //NOTE: varchar type
  }
  
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close organ_cursor", ECPGt_EOIT, ECPGt_EORT);}
#line 58 "cursor.pgc"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 59 "cursor.pgc"


  { ECPGdisconnect(__LINE__, "ALL");}
#line 61 "cursor.pgc"

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
