/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "all_err.pgc"
#include <stdlib.h>    
//#include <sqlca.h>
    
//EXEC SQL INCLUDE sqlca;    
    
int main() {  
    void print_sqlca();

    /* exec sql begin declare section */
          
          
    
#line 10 "all_err.pgc"
 int caID ;
 
#line 11 "all_err.pgc"
  struct varchar_1  { int len; char arr[ 10 ]; }  caName ;
/* exec sql end declare section */
#line 12 "all_err.pgc"

	
    { ECPGconnect(__LINE__, 0, "lwwtest@10.136.2.133:5432" , "lww" , "lww" , NULL, 0); }
#line 14 "all_err.pgc"

    if(sqlca.sqlcode)
    {
      printf("Connect DB error! sqlcode=%d!\n", sqlca.sqlcode);
    }
	//EXEC SQL BEGIN TRANSACTION;
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "drop table test_ecpg_tbl", ECPGt_EOIT, ECPGt_EORT);}
#line 20 "all_err.pgc"
//testing
        { ECPGtrans(__LINE__, NULL, "commit");}
#line 21 "all_err.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "create table test_ecpg_tbl ( id int , name varchar ( 10 ) )", ECPGt_EOIT, ECPGt_EORT);}
#line 22 "all_err.pgc"

        { ECPGtrans(__LINE__, NULL, "commit");}
#line 23 "all_err.pgc"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "create unique index idx1 on test_ecpg_tbl ( id )", ECPGt_EOIT, ECPGt_EORT);}
#line 24 "all_err.pgc"

       	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 25 "all_err.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_ecpg_tbl values ( 1 , 'varchar123' )", ECPGt_EOIT, ECPGt_EORT);}
#line 26 "all_err.pgc"

        if(sqlca.sqlcode)
           {
             print_sqlca();
           }
        { ECPGtrans(__LINE__, NULL, "commit");}
#line 31 "all_err.pgc"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_ecpg_tbl values ( 2 , '一二三四五六七八九十多' )", ECPGt_EOIT, ECPGt_EORT);}
#line 32 "all_err.pgc"

          if(sqlca.sqlcode)
           {
             print_sqlca();
           }
	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 37 "all_err.pgc"


        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update test_ecpg_tbl set id = 100 where id = 1", ECPGt_EOIT, ECPGt_EORT);}
#line 39 "all_err.pgc"

        { ECPGtrans(__LINE__, NULL, "commit");}
#line 40 "all_err.pgc"

//      EXEC SQL delete from test_ecpg_tbl where id=100;
  //    EXEC SQL COMMIT;
	
     { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 44 "all_err.pgc"
 
	ECPGset_var( 0, &( caName ), __LINE__);\
 ECPGset_var( 1, &( caID ), __LINE__);\
 /* declare tb_cur cursor for select id , name from test_ecpg_tbl */
#line 46 "all_err.pgc"

	//if(sqlca.sqlcode){}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare tb_cur cursor for select id , name from test_ecpg_tbl", ECPGt_EOIT, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)10,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 48 "all_err.pgc"

	//if(sqlca.sqlcode){}
        /* exec sql whenever not found  break ; */
#line 50 "all_err.pgc"

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
#line 53 "all_err.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 53 "all_err.pgc"

         //printf("id=%d, name=%s\n", caID, caName); //char name
         printf("id=%d, name=%*s\n", caID,caName.len, caName.arr);//varchar name
         //if(sqlca.sqlcode==100) break;
         if(sqlca.sqlcode)
          {
         //  print_sqlca();
           break;
          }
        }

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close tb_cur", ECPGt_EOIT, ECPGt_EORT);}
#line 64 "all_err.pgc"

     { ECPGtrans(__LINE__, NULL, "commit");}
#line 65 "all_err.pgc"


      //EXEC SQL delete from test_ecpg_tbl where id=100;
      //EXEC SQL COMMIT;

      //EXEC SQL WHENEVER SQLERROR CALL print_sqlca();
	
     { ECPGdisconnect(__LINE__, "ALL");}
#line 72 "all_err.pgc"

    
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
