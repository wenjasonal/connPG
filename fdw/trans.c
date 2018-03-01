/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "trans.pgc"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
  void print_sqlca();

  /* exec sql begin declare section */ 
      
      
  
#line 9 "trans.pgc"
 int caCode [ 10 ] ;
 
#line 10 "trans.pgc"
  struct varchar_1  { int len; char arr[ 30 ]; }  caName [ 10 ] ;
/* exec sql end declare section */
#line 11 "trans.pgc"


  { ECPGconnect(__LINE__, 0, "lwwtest@10.136.1.32:5432" , "lww" , "lww" , NULL, 0); }
#line 13 "trans.pgc"


  if(sqlca.sqlcode) 
  {
    printf("Connect database ERROR! sqlcode=%ld\n", sqlca.sqlcode);
  }
  else
    printf("Connect database OK!\n");

  //测试前--删除表内记录
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from organ_ecpg", ECPGt_EOIT, ECPGt_EORT);}
#line 23 "trans.pgc"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 24 "trans.pgc"

  printf("Delete data OK!\n");

  { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 27 "trans.pgc"

  //插入多条记录
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ_ecpg values ( 1 , '机构1' )", ECPGt_EOIT, ECPGt_EORT);}
#line 29 "trans.pgc"

    printf("11 Insert into organ_ecpg_1 data!\n");
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ_ecpg values ( 2 , '机构2' )", ECPGt_EOIT, ECPGt_EORT);}
#line 31 "trans.pgc"
 
    printf("01 Insert into organ_ecpg_0 data!\n");
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ_ecpg values ( 3 , '机构3' )", ECPGt_EOIT, ECPGt_EORT);}
#line 33 "trans.pgc"

    printf("12 Insert into organ_ecpg_1 data!\n");
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ_ecpg values ( 4 , '机构4' )", ECPGt_EOIT, ECPGt_EORT);}
#line 35 "trans.pgc"
 
    printf("02 Insert into organ_ecpg_0 data!\n");
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ_ecpg values ( 5 , '机构5' )", ECPGt_EOIT, ECPGt_EORT);}
#line 37 "trans.pgc"
 
    printf("13 Insert into organ_ecpg_1 data!\n");
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update organ_ecpg set orgname = '机构更名' where orgname = '机构5'", ECPGt_EOIT, ECPGt_EORT);}
#line 39 "trans.pgc"

    printf("Update organ_ecpg_1 data!\n");
    sleep (5); 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update organ_ecpg set orgname = '机构更名' where orgname = '机构2'", ECPGt_EOIT, ECPGt_EORT);}
#line 42 "trans.pgc"

    printf("Update organ_ecpg_0 data!\n");
    sleep (5);

  sleep (20);
  { ECPGtrans(__LINE__, NULL, "commit");}
#line 47 "trans.pgc"

  //EXEC SQL ROLLBACK;

  if(sqlca.sqlcode) 
  {
    printf("Some ERROR happened! sqlca.sqlcode=%ld\n", sqlca.sqlcode);
    print_sqlca();
   // EXEC SQL ROLLBACK;
   // printf("Rollback sqlca.sqlcode=%ld\n", sqlca.sqlcode);
    return -1;
  }

  //定义游标读取表内所有记录
  /* declare organ_ecpg_cursor cursor for select orgcode , orgname from organ_ecpg order by orgcode */
#line 62 "trans.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare organ_ecpg_cursor cursor for select orgcode , orgname from organ_ecpg order by orgcode", ECPGt_EOIT, ECPGt_EORT);}
#line 63 "trans.pgc"

 
  while(1)
  {
     memset(caName, 0x00, sizeof(caName));
     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch 2 organ_ecpg_cursor", ECPGt_EOIT, 
	ECPGt_int,(caCode),(long)1,(long)10,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caName),(long)30,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 68 "trans.pgc"

     printf("%ld\n", sqlca.sqlerrd[2]);
     if(sqlca.sqlcode==100)
          {
           //print_sqlca();
           break;
          }
     
     int i=0;
     for( i=0; i<sqlca.sqlerrd[2]; i++)
           printf("orgcode = %d, orgname = %*s\n", caCode[i], caName[i].len, caName[i].arr); //NOTE: varchar type
  }
  
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close organ_ecpg_cursor", ECPGt_EOIT, ECPGt_EORT);}
#line 81 "trans.pgc"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 82 "trans.pgc"


  { ECPGdisconnect(__LINE__, "ALL");}
#line 84 "trans.pgc"

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
