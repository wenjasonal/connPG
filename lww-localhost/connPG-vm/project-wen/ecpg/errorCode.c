/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "errorCode.pgc"
#include <stdlib.h>

int main()
{
  void print_sqlca();
  /* exec sql begin declare section */
       
       
       
       
  
#line 7 "errorCode.pgc"
 int caID ;
 
#line 8 "errorCode.pgc"
  struct varchar_1  { int len; char arr[ 10 ]; }  caName ;
 
#line 9 "errorCode.pgc"
 char caOther [ 30 ] ;
 
#line 10 "errorCode.pgc"
 int mm ;
/* exec sql end declare section */
#line 11 "errorCode.pgc"


  /* exec sql whenever sqlerror  call print_sqlca ( ) ; */
#line 13 "errorCode.pgc"
 //sqlprint;
  { ECPGconnect(__LINE__, 0, "tcp:postgresql://10.136.1.3:5432/test" , "lww" , "lww" , "myconn", 0); 
#line 14 "errorCode.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 14 "errorCode.pgc"

  //EXEC SQL CONNECT TO tcp:postgresql://10.136.1.3:5432/test AS myconn USER lww/lww123;
  if(sqlca.sqlcode)
    exit(-1);
  else
    printf("Connect database OK!\n");

  //建表！
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "drop table test_errorcode", ECPGt_EOIT, ECPGt_EORT);
#line 22 "errorCode.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 22 "errorCode.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "create table test_errorcode ( id int primary key , name varchar ( 10 ) not null , other char ( 30 ) )", ECPGt_EOIT, ECPGt_EORT);
#line 23 "errorCode.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 23 "errorCode.pgc"

  if(sqlca.sqlcode)  exit(-1);

  //插入正常记录！
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_errorcode values ( 1 , 'varchar10' , '正常输入记录' )", ECPGt_EOIT, ECPGt_EORT);
#line 27 "errorCode.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 27 "errorCode.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select id , name , other from test_errorcode", ECPGt_EOIT, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)10,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caOther),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 28 "errorCode.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 28 "errorCode.pgc"

  printf("insert value: id = %d, name = %*s, other = %s \n", caID, caName.len, caName.arr, caOther);
  if(sqlca.sqlcode)  exit(-1);
  /*
  //1.表名错误
  EXEC SQL insert into test_errorcode12 values(11, 'test', '表名错误');
  if(sqlca.sqlcode) 
  {
     exit(-1);
  }
  //2.表字段名错误
  EXEC SQL insert into test_errorcode(id, name, otherlww) values(11, 'test', '表字段名错误');
  if(sqlca.sqlcode)
  {
     exit(-1);
  }
  //3.字段长度超出范围！ 
  EXEC SQL insert into test_errorcode values(2, '超过varchar值10', 'name超过定义长度');
  if(sqlca.sqlcode)  
  {
     exit(-1);
  }
  
  //4.主键冲突！
  EXEC SQL insert into test_errorcode values(1, 'test', 'id主键冲突');
  if(sqlca.sqlcode)  
  {
     exit(-1);
  }
  
  //5.不满足非空！
  //EXEC SQL insert into test_errorcode values(3, '', '''插入空值到字段name');
  EXEC SQL insert into test_errorcode values(3, NULL, 'NULL不满足非空限定');
  //EXEC SQL insert into test_errorcode(id, other) values(3, 'name不满足非空限定');
  if(sqlca.sqlcode)  
  {
     exit(-1);
  }
  
  //6.表未加指示变量或指示变量少于读取表变量，内容无法读取；表宿主变量多于待读取表变量。
  EXEC SQL select id, name, other INTO :caID, :caName from test_errorcode;
  //EXEC SQL select id, name, other INTO :caID, :caName, :caOther, :mm from test_errorcode;
  if(sqlca.sqlcode)
  {
    exit(-1);
  }
  */
  //7.select多条记录数据返回报错
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_errorcode values ( 123 , 'test' , '多条记录select报错' )", ECPGt_EOIT, ECPGt_EORT);
#line 76 "errorCode.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 76 "errorCode.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select id , name , other from test_errorcode", ECPGt_EOIT, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)10,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caOther),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 77 "errorCode.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 77 "errorCode.pgc"

  if(sqlca.sqlcode)
  {
    exit(-1);
  }

  { ECPGtrans(__LINE__, NULL, "commit");
#line 83 "errorCode.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 83 "errorCode.pgc"


  { ECPGdisconnect(__LINE__, "ALL");
#line 85 "errorCode.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 85 "errorCode.pgc"

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
