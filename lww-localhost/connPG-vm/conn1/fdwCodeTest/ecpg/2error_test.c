/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "2error_test.pgc"
#include <stdlib.h>    
//#include <sqlca.h>
    
//EXEC SQL INCLUDE sqlca;    
    
int main() {  
    /* exec sql begin declare section */
          
          
          
    
#line 8 "2error_test.pgc"
 int caID ;
 
#line 9 "2error_test.pgc"
  struct varchar_1  { int len; char arr[ 30 ]; }  caName ;
 
#line 10 "2error_test.pgc"
 char caName1 [ 30 ] ;
/* exec sql end declare section */
#line 11 "2error_test.pgc"

	
    //EXEC SQL CONNECT TO "lwwtest@10.136.1.32:5432" USER "lww" IDENTIFIED BY "lww";
    { ECPGconnect(__LINE__, 0, "test@10.50.6.83:5432" , "lww" , "lww" , NULL, 0); }
#line 14 "2error_test.pgc"

    if(sqlca.sqlcode)
    {
      printf("Connect DB error! sqlcode=%d!\n", sqlca.sqlcode);
    }
	//EXEC SQL BEGIN TRANSACTION;
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 5 , 'testfenku' )", ECPGt_EOIT, ECPGt_EORT);}
#line 20 "2error_test.pgc"

        if(sqlca.sqlcode)
    {
      printf("insert error! sqlcode=%d!\n", sqlca.sqlcode);
    }

//        EXEC SQL COMMIT;

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( 6 , '中文测试一二三四五六' )", ECPGt_EOIT, ECPGt_EORT);}
#line 28 "2error_test.pgc"

 if(sqlca.sqlcode)
    {
      printf("insert error! sqlcode=%d!\n", sqlca.sqlcode);
    }
  //      EXEC SQL COMMIT;
/*
        EXEC SQL UPDATE organ SET organcode=100 WHERE organcode=5;
if(sqlca.sqlcode)
    {
      printf("update error! sqlcode=%d!\n", sqlca.sqlcode);
    }

    //    EXEC SQL COMMIT;
      EXEC SQL delete from organ where organcode=1;
if(sqlca.sqlcode)
    {
      printf("delete error! sqlcode=%d!\n", sqlca.sqlcode);
    }
*/
  //    EXEC SQL COMMIT;
	//exit (1);
        { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 50 "2error_test.pgc"

	ECPGset_var( 0, &( caName ), __LINE__);\
 ECPGset_var( 1, &( caID ), __LINE__);\
 /* declare tb_cur cursor for select organcode , organname from organ */
#line 52 "2error_test.pgc"

	//if(sqlca.sqlcode){}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare tb_cur cursor for select organcode , organname from organ", ECPGt_EOIT, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)30,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 54 "2error_test.pgc"

	//if(sqlca.sqlcode){}
        /* exec sql whenever not found  break ; */
#line 56 "2error_test.pgc"


//testing--        printf("immmm\n"); 
//exit(1);
       while(1)
        {
//memset(caName, 0x00, sizeof(caName1));
      //    EXEC SQL FETCH tb_cur INTO :caID, :caName1;
      //    printf("id=%d, name=%s\n", caID, caName1); //char name
          { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch tb_cur", ECPGt_EOIT, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)30,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)30,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 65 "2error_test.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 65 "2error_test.pgc"

          printf("id=%d, name=%*s\n", caID,caName.len, caName.arr);//varchar name
//testing--   break;//just one result!
//          sleep (5);
          if(sqlca.sqlcode)
           {
              printf("select error! sqlcode=%d!\n", sqlca.sqlcode);
              break;
            }
         }

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close tb_cur", ECPGt_EOIT, ECPGt_EORT);}
#line 76 "2error_test.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 77 "2error_test.pgc"


  //    EXEC SQL delete from test_ecpg_tbl where id=100;
  //    EXEC SQL COMMIT;
	
        { ECPGdisconnect(__LINE__, "ALL");}
#line 82 "2error_test.pgc"

    
        return 0;    
}
