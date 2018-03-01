/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "ins-test.pgc"
#include <stdlib.h>

//EXEC SQL INCLUDE sqlca;

/* exec sql whenever sqlerror  do sql_error ( ) ; */
#line 5 "ins-test.pgc"


void sql_error()
{
    printf( "错误原因为:%.*s\n",sqlca.sqlerrm.sqlerrml,sqlca.sqlerrm.sqlerrmc);
}

int main( int argc, char **argv )
{
    /* exec sql begin declare section */
           
    
#line 15 "ins-test.pgc"
 int count = 0 ;
/* exec sql end declare section */
#line 16 "ins-test.pgc"


    { ECPGconnect(__LINE__, 0, "lwwtest@10.136.1.61:5432" , "lww" , "lww" , NULL, 0); 
#line 18 "ins-test.pgc"

if (sqlca.sqlcode < 0) sql_error ( );}
#line 18 "ins-test.pgc"


    int i;
    while(1) {
        { ECPGtrans(__LINE__, NULL, "begin");
#line 22 "ins-test.pgc"

if (sqlca.sqlcode < 0) sql_error ( );}
#line 22 "ins-test.pgc"

        count++;
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_ecpg values ( $1  )", 
	ECPGt_int,&(count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 24 "ins-test.pgc"

if (sqlca.sqlcode < 0) sql_error ( );}
#line 24 "ins-test.pgc"

        if(sqlca.sqlcode) {
            printf("insert error\n");
            break;
        }
        { ECPGtrans(__LINE__, NULL, "commit");
#line 29 "ins-test.pgc"

if (sqlca.sqlcode < 0) sql_error ( );}
#line 29 "ins-test.pgc"

        if(sqlca.sqlcode) {
            printf("commit error\n");
            break;
        }
    }
    printf("count=%d\n", count);
    return 0;
}


