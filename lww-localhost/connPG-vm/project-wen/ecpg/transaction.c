/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "transaction.pgc"
#include <stdlib.h>

int main()
{
    /* exec sql begin declare section */
          
          
    
#line 6 "transaction.pgc"
 int caID ;
 
#line 7 "transaction.pgc"
  struct varchar_1  { int len; char arr[ 20 ]; }  caName ;
/* exec sql end declare section */
#line 8 "transaction.pgc"
 

    { ECPGconnect(__LINE__, 0, "test@10.136.1.143:5432" , "lww" , "lww" , NULL, 0); }
#line 10 "transaction.pgc"

    if(sqlca.sqlcode)
    {
       printf("CONNECT DATABASE error! sqlcode=%s\n", sqlca.sqlcode);
    }
    else 
       printf("CONNECT DATABASE OK!\n");
 
    { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 18 "transaction.pgc"

    
    //EXEC SQL CREATE TABLE test_transaction(id int not null, name varchar(20)); //first time
    
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from test_transaction", ECPGt_EOIT, ECPGt_EORT);}
#line 22 "transaction.pgc"
  //repeat test
    
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_transaction values ( 1 , '易联达' )", ECPGt_EOIT, ECPGt_EORT);}
#line 24 "transaction.pgc"

    
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select id , name from test_transaction", ECPGt_EOIT, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)20,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 26 "transaction.pgc"

    printf("insert one result: id=%d, name=%*s\n", caID, caName.len, caName.arr);
    
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update test_transaction set name = '北京易联达'", ECPGt_EOIT, ECPGt_EORT);}
#line 29 "transaction.pgc"

    
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select id , name from test_transaction", ECPGt_EOIT, 
	ECPGt_int,&(caID),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(caName),(long)20,(long)1,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 31 "transaction.pgc"

    printf("update the result: id=%d, name=%*s\n", caID, caName.len, caName.arr);
    
    //EXEC SQL ROLLBACK;
    { ECPGtrans(__LINE__, NULL, "commit");}
#line 35 "transaction.pgc"


    { ECPGdisconnect(__LINE__, "ALL");}
#line 37 "transaction.pgc"

    return 0;
}
