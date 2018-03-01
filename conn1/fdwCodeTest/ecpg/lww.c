/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "lww.pgc"
#include <stdlib.h>    
//#include <sqlca.h>
    
//EXEC SQL INCLUDE sqlca;    
    
int main() {  
    void print_sqlca();

    /* exec sql begin declare section */
          
          
          
    
#line 10 "lww.pgc"
 char caSignno [ 45 ] ;
 
#line 11 "lww.pgc"
 char caBusinesstypecode [ 10 ] ;
 
#line 12 "lww.pgc"
 char caEmail [ 40 ] ;
/* exec sql end declare section */
#line 13 "lww.pgc"

	
    { ECPGconnect(__LINE__, 0, "paydev@10.136.2.133:5432" , "paydev" , "paydev" , NULL, 0); }
#line 15 "lww.pgc"

    //EXEC SQL CONNECT TO "paydb6@10.136.2.131:5432" USER "paydev" IDENTIFIED BY "paydev";
    if(sqlca.sqlcode)
    {
      printf("Connect DB error! sqlcode=%d!\n", sqlca.sqlcode);
    }
//更改记录
int i=0;
while(1)
//while(i<2)
{
  memset(caEmail, '\0', sizeof(caEmail));
  sleep(1);
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select email from tb_addconsign where signno = '6221887900000461019'", ECPGt_EOIT, 
	ECPGt_char,(caEmail),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 28 "lww.pgc"

  //printf("email=%s\n", caEmail);//testing
  if(sqlca.sqlcode)
  {
     return -1;
    }
  printf("sqlcode = %ld  sqlstate=[%s]\n", sqlca.sqlcode, sqlca.sqlstate);
  printf("email=%s\n", caEmail);
  if(i==0) {
       { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 37 "lww.pgc"

       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update tb_addconsign set email = 'lww-testecpg11@qq.com' where signno = '6221887900000461019'", ECPGt_EOIT, ECPGt_EORT);}
#line 38 "lww.pgc"

    // EXEC SQL update tb_addconsign SET email='' where signno='6221887900000461019'; //恢复表原数据
       { ECPGtrans(__LINE__, NULL, "commit");}
#line 40 "lww.pgc"
 //默认必须加此项才会完成提交操作，否则数据库内部不会更新，或者不加此句但ecpg执行时加-t选项
   }
  i++;
 }    

/* //查询更改后数据
        EXEC SQL BEGIN TRANSACTION;
        EXEC SQL DECLARE tb_cur_1 CURSOR FOR
             select signno, businesstypecode, email INTO :caSignno, :caBusinesstypecode, :caEmail from tb_addconsign where signno='6221887900000461019';
        //if(sqlca.sqlcode){}
        EXEC SQL OPEN tb_cur_1;
        //if(sqlca.sqlcode){}
        //EXEC SQL WHENEVER NOT FOUND DO BREAK;
        while(1)
        {
         memset( caSignno, 0x00, sizeof(caSignno));
         memset( caBusinesstypecode, 0x00, sizeof(caBusinesstypecode));
         memset( caEmail, 0x00, sizeof(caEmail));
         EXEC SQL FETCH 1 tb_cur_1 INTO :caSignno, :caBusinesstypecode, :caEmail;//cursor select mutli-column
         printf("%d\n", sqlca.sqlerrd[2]);
//break; //testing
         if(sqlca.sqlcode==100)
          {
           //print_sqlca();
           break;
          }
         int i=0;
        for( i=0 ; i<sqlca.sqlerrd[2]; i++)
         {
          printf("signno=%s, businesstypecode=%s, email=%s\n", caSignno, caBusinesstypecode, caEmail); //char name
         //printf("signno=%*s, businesstypecode=%*s,  email=%*s\n", caSignno[i].len, caSignno[i].arr, caBusinesstypecode[i].len, caBusinesstypecode[i].arr, caEmail[i].len, caEmail[i].arr);//varchar name
         //break; //testing
         }
         //if(sqlca.sqlcode==100) break;
//break; //testing
        }
        EXEC SQL CLOSE tb_cur_1;
     EXEC SQL COMMIT;
*/
      //EXEC SQL WHENEVER SQLERROR CALL print_sqlca();
	
     { ECPGdisconnect(__LINE__, "ALL");}
#line 81 "lww.pgc"

    
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
