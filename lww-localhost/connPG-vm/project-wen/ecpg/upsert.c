/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "upsert.pgc"
#include <stdlib.h>

int main()
{
  void print_sqlca();
  /* exec sql whenever sqlerror  call print_sqlca ( ) ; */
#line 6 "upsert.pgc"


  /* exec sql begin declare section */
     
     
     
     
  
#line 9 "upsert.pgc"
 int caID ;
 
#line 10 "upsert.pgc"
  struct varchar_1  { int len; char arr[ 20 ]; }  caName [ 5 ] ;
 
#line 11 "upsert.pgc"
  struct varchar_2  { int len; char arr[ 30 ]; }  caExplain [ 5 ] ;
 
#line 12 "upsert.pgc"
 int i ;
/* exec sql end declare section */
#line 13 "upsert.pgc"

 
  { ECPGconnect(__LINE__, 0, "test@10.136.1.143:5432" , "lww" , "lww" , NULL, 0); 
#line 15 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 15 "upsert.pgc"

  if(sqlca.sqlcode) 
    printf("Connect database error! sqlcode=%s\n", sqlca.sqlcode);
  
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "drop table test_upsert", ECPGt_EOIT, ECPGt_EORT);
#line 19 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 19 "upsert.pgc"
 //multi-test
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "create table test_upsert ( id int primary key , name varchar ( 20 ) not null , explain varchar ( 30 ) )", ECPGt_EOIT, ECPGt_EORT);
#line 20 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 20 "upsert.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_upsert values ( 1 , 'PSBC' , 'insert1' )", ECPGt_EOIT, ECPGt_EORT);
#line 21 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 21 "upsert.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_upsert values ( 2 , 'CBANK' , 'insert2' )", ECPGt_EOIT, ECPGt_EORT);
#line 22 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 22 "upsert.pgc"

  { ECPGtrans(__LINE__, NULL, "commit");
#line 23 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 23 "upsert.pgc"


  /* declare upsert_cursor cursor with hold for select id , name , explain from test_upsert order by id */
#line 27 "upsert.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare upsert_cursor cursor with hold for select id , name , explain from test_upsert order by id", ECPGt_EOIT, ECPGt_EORT);
#line 28 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 28 "upsert.pgc"

  while(1)
  { 
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch upsert_cursor", ECPGt_EOIT, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caName),(long)20,(long)5,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caExplain),(long)30,(long)5,sizeof(struct varchar_2), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 31 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 31 "upsert.pgc"

    if(sqlca.sqlcode == 100) break;
    for(i=0;i<sqlca.sqlerrd[2];i++)
      printf("id = %d, name = %*s, explain = %*s \n", caID, caName[i].len, caName[i].arr, caExplain[i].len, caExplain[i].arr);
  }
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close upsert_cursor", ECPGt_EOIT, ECPGt_EORT);
#line 36 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 36 "upsert.pgc"

  { ECPGtrans(__LINE__, NULL, "commit");
#line 37 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 37 "upsert.pgc"


  printf("==========insert on conflict do update==========\n");
  
  //更新某一字段的值！
  //EXEC SQL insert into test_upsert(id, name, explain) values(2, 'replaceCBANK', 'replaceinsert2') ON CONFLICT(id) DO UPDATE set name=EXCLUDED.name;
  //EXEC SQL insert into test_upsert(id, name, explain) values(2,'replaceCBANK', 'replaceinsert2') ON CONFLICT(id) DO UPDATE set explain=EXCLUDED.explain;

  //更新多个字段的值！update many column one time!--存在则更新，不存在则插入！
  //EXEC SQL insert into test_upsert(id, name, explain) values(2,'replaceCBANK', 'replaceinsert2') ON CONFLICT(id) DO UPDATE set (name, explain)=(EXCLUDED.name, EXCLUDED.explain);
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_upsert ( id , name , explain ) values ( 2 , 'replaceCBANK' , 'replaceinsert2' ) on conflict ( id ) do update set name = EXCLUDED . name , explain = EXCLUDED . explain", ECPGt_EOIT, ECPGt_EORT);
#line 47 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 47 "upsert.pgc"


  //不存在则插入，存在则直接返回（不做任何处理）
  //EXEC SQL insert into test_upsert values(3, 'newBANK', 'newInsert') ON CONFLICT(id) DO NOTHING;

  { ECPGtrans(__LINE__, NULL, "commit");
#line 52 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 52 "upsert.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare upsert_cursor cursor with hold for select id , name , explain from test_upsert order by id", ECPGt_EOIT, ECPGt_EORT);
#line 53 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 53 "upsert.pgc"

  while(1)
  {
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch upsert_cursor", ECPGt_EOIT, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caName),(long)20,(long)5,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caExplain),(long)30,(long)5,sizeof(struct varchar_2), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 56 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 56 "upsert.pgc"

    if(sqlca.sqlcode == 100) break;
    for(i=0;i<sqlca.sqlerrd[2];i++)
      printf("id = %d, name = %*s, explain = %*s \n", caID, caName[i].len, caName[i].arr, caExplain[i].len, caExplain[i].arr);
  }
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close upsert_cursor", ECPGt_EOIT, ECPGt_EORT);
#line 61 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 61 "upsert.pgc"

  { ECPGtrans(__LINE__, NULL, "commit");
#line 62 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 62 "upsert.pgc"

  
  { ECPGdisconnect(__LINE__, "ALL");
#line 64 "upsert.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 64 "upsert.pgc"

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
