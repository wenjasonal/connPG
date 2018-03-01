/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "just-sel.pgc"
#include <stdlib.h>
#include <string.h>

int main(){
  void print_sqlca();

  /* exec sql begin declare section */
      
      
  
#line 8 "just-sel.pgc"
 int caCode [ 10 ] ;
 
#line 9 "just-sel.pgc"
  struct varchar_1  { int len; char arr[ 30 ]; }  caName [ 10 ] ;
/* exec sql end declare section */
#line 10 "just-sel.pgc"


  { ECPGconnect(__LINE__, 0, "test@10.136.1.143:5432" , "lww" , "lww" , NULL, 0); }
#line 12 "just-sel.pgc"


  if(sqlca.sqlcode)
  {
    printf("Connect database ERROR! sqlcode=%s\n", sqlca.sqlcode);
  }
  else
    printf("Connect database OK!\n");

  
//  EXEC SQL SELECT organcode, organname INTO :caCode, :caName FROM organ;
//  printf("select record:\n organcode = %d, organname = %*s\n", caCode, caName.len, caName.arr); //NOTE: varchar type
 
 /* declare organ_cursor cursor for select organcode , organname from organ order by organcode */
#line 27 "just-sel.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare organ_cursor cursor for select organcode , organname from organ order by organcode", ECPGt_EOIT, ECPGt_EORT);}
#line 28 "just-sel.pgc"


  while(1)
  {
     memset(caName, 0x00, sizeof(caName));
     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch organ_cursor", ECPGt_EOIT, 
	ECPGt_int,(caCode),(long)1,(long)10,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caName),(long)30,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 33 "just-sel.pgc"

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
#line 45 "just-sel.pgc"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 46 "just-sel.pgc"

 


  { ECPGdisconnect(__LINE__, "ALL");}
#line 50 "just-sel.pgc"

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

 
