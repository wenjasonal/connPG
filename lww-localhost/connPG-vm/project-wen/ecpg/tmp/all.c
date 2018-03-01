/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "all.pgc"
#include <stdlib.h>    
//#include <sqlca.h>
    
//EXEC SQL INCLUDE sqlca;    
    
int main() {  
    /* exec sql begin declare section */
          
         //char caName[10];
          
    
#line 8 "all.pgc"
 int caID ;
 
#line 10 "all.pgc"
  struct varchar_1  { int len; char arr[ 10 ]; }  caName ;
/* exec sql end declare section */
#line 11 "all.pgc"


    //connection	
    { ECPGconnect(__LINE__, 0, "test@10.136.1.3:5432" , "lww" , "lww" , NULL, 0); }
#line 14 "all.pgc"

    
    if(sqlca.sqlcode)
    {
      printf("Connect DB error! sqlcode=%d!\n", sqlca.sqlcode);
    }
	//EXEC SQL BEGIN TRANSACTION;
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "drop table test_ecpg_tbl", ECPGt_EOIT, ECPGt_EORT);}
#line 21 "all.pgc"
//testing
        //EXEC SQL COMMIT;
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "create table test_ecpg_tbl ( id int , name varchar ( 10 ) )", ECPGt_EOIT, ECPGt_EORT);}
#line 23 "all.pgc"

        //EXEC SQL COMMIT;
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "create unique index idx1 on test_ecpg_tbl ( id )", ECPGt_EOIT, ECPGt_EORT);}
#line 25 "all.pgc"

       	//EXEC SQL COMMIT;
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_ecpg_tbl values ( 1 , 'varchar123' )", ECPGt_EOIT, ECPGt_EORT);}
#line 27 "all.pgc"

        //EXEC SQL COMMIT;
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_ecpg_tbl values ( 2 , '中文测试一二三四五六' )", ECPGt_EOIT, ECPGt_EORT);}
#line 29 "all.pgc"

	//EXEC SQL COMMIT;

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update test_ecpg_tbl set id = 100 where id = 1", ECPGt_EOIT, ECPGt_EORT);}
#line 32 "all.pgc"

        //EXEC SQL COMMIT;
  //    EXEC SQL delete from test_ecpg_tbl where id=100;
  //    EXEC SQL COMMIT;
	
        //EXEC SQL BEGIN TRANSACTION;
	ECPGset_var( 0, &( caName ), __LINE__);\
 ECPGset_var( 1, &( caID ), __LINE__);\
 /* declare tb_cur cursor for select id , name from test_ecpg_tbl */
#line 39 "all.pgc"

	//if(sqlca.sqlcode){}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare tb_cur cursor for select id , name from test_ecpg_tbl", ECPGt_EOIT, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)10,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 41 "all.pgc"

	//if(sqlca.sqlcode){}
        /* exec sql whenever not found  break ; */
#line 43 "all.pgc"

        while(1)
        {
          { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch tb_cur", ECPGt_EOIT, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)10,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)10,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 46 "all.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 46 "all.pgc"

          //printf("id=%d, name=%s\n", caID, caName); //char name
          printf("id=%d, name=%*s\n", caID, caName.len, caName.arr);//varchar name
          //if(sqlca.sqlcode) break; //调试--1次
         }

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close tb_cur", ECPGt_EOIT, ECPGt_EORT);}
#line 52 "all.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 53 "all.pgc"


      //EXEC SQL WHENEVER NOT FOUND CONTINUE;
      //EXEC SQL delete from test_ecpg_tbl where id=100;
      //EXEC SQL COMMIT;
	
        { ECPGdisconnect(__LINE__, "ALL");}
#line 59 "all.pgc"

    
        return 0;    
}
