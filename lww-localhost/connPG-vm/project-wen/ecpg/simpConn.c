/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "simpConn.pgc"
#include <stdlib.h>
//#include <sqlca.h>
//EXEC SQL INCLUDE sqlca;

int main(){
//*****************************建立数据库连接***********************************************//
    //不同连接文本方法：
    //EXEC SQL CONNECT TO test@10.136.1.143:5432 USER lww/lww;
    //EXEC SQL CONNECT TO test@10.136.1.143:5432 AS myconnection USER lww/lww; //define a connection name
    { ECPGconnect(__LINE__, 0, "tcp:postgresql://10.136.1.143:5432/test" , "lww" , "lww" , NULL, 0); }
#line 10 "simpConn.pgc"

    
    //*EXEC SQL CONNECT TO unix:postgresql://10.136.1.143:5432/test USER lww; /* ERROR: Unix-domain sockets only work   */
                                                                            /* on "localhost" but not on "10.136.1.143" */
    //EXEC SQL CONNECT TO unix:postgresql://localhost:5432/test USER lww;   

 
    //不同声明用户名方法：
    //EXEC SQL CONNECT TO test@10.136.1.143:5432 USER lww/lww;
    //EXEC SQL CONNECT TO test@10.136.1.143:5432 USER lww IDENTIFIED BY lww;
    //EXEC SQL CONNECT TO test@10.136.1.143:5432 USER lww USING lww;
  
    //变量声明方式连接： 
/*
    EXEC SQL BEGIN DECLARE SECTION;
    const char *target="test@10.136.1.143:5432";
    const char *user="lww";
    const char *password="lww";
    EXEC SQL END DECLARE SECTION;
    
    EXEC SQL CONNECT TO :target USER :user USING :password; //OR EXEC SQL CONNECT TO :target USER :user/:password
*/

//**************************管理多个连接******************************************************//
/*
    EXEC SQL BEGIN DECLARE SECTION;
         char dbname[1024];
    EXEC SQL END DECLARE SECTION;
    
    EXEC SQL CONNECT TO test@10.136.1.143:5432 AS myconn USER lww/lww; //define a connection name
    
    //EXEC SQL AT myconn SELECT current_database() INTO :dbname; //为SQL语句指定连接（多个连接时）    
    EXEC SQL SET CONNECTION myconn;//设置当前连接（多个连接切换）
    EXEC SQL SELECT current_database() INTO :dbname;
    
    printf("current database=%s \n", dbname);
*/
//*************************************************************************************************

    if(sqlca.sqlcode)
    {
       printf("Connect database ERROR! sqlcode=%d!\n", sqlca.sqlcode);
    }
    else
       printf("Connect database OK!\n");

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set client_encoding to 'GB18030'", ECPGt_EOIT, ECPGt_EORT);}
#line 56 "simpConn.pgc"
 //设置当前连接的客户端编码
    /*验证当前连接客户端编码*/
    /* exec sql begin declare section */
     
    
#line 59 "simpConn.pgc"
 char encoding [ 10 ] ;
/* exec sql end declare section */
#line 60 "simpConn.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "show client_encoding", ECPGt_EOIT, 
	ECPGt_char,(encoding),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 61 "simpConn.pgc"

    printf("current client_encoding is \"%s\"\n", encoding);


//关闭一个连接
    { ECPGdisconnect(__LINE__, "ALL");}
#line 66 "simpConn.pgc"

    //EXEC SQL DISCONNECT myconn;
    return 0;
    
}


