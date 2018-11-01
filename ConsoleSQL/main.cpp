#include <iostream>
#include <boost/variant.hpp>
#include <boost/any.hpp>
#include <vector>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <string.h>
#include <exception>

int main (int argc, char* argv[])
{

   MYSQL*     conn;
   MYSQL_RES* res;
   MYSQL_ROW  row;

   const char* server   = "127.0.0.1";
   const char* user     = "root";
   const char* password = "mysql"; /* set me first */
   const char* database = "mysql";



   char exitt[100]="exit";

   while(true)
   {
       char input[100];
       std::cout<<"Enter sql statement:\n";
       std::cin.getline(input,sizeof(input));

       std::cout<<("exit\0"==input)<<std::endl;
       std::vector<std::string> some_values1;
     try{
       conn = mysql_init(NULL);

    /* Connect to database */
       if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
       {
          std::cout<<mysql_error(conn)<<std::endl;
          exit(1);
       }

       /* send SQL query */


       if (mysql_query(conn, input))
       {
           std::cout<<mysql_error(conn)<<std::endl;
           exit(1);
       }

       res = mysql_use_result(conn);

       /* output table name */
       printf("Result of request:\n");

           std::cout<<"try block\n";
           while ((row = mysql_fetch_row(res)) != NULL)
           {
               //      printf("%s \n", row[0]);
               some_values1.push_back(row[0]);
           }
           for(auto i:some_values1){
               std::cout<<i<<std::endl;
           }
           mysql_free_result(res);
           mysql_close(conn);
       }
       catch(std::exception& e){
           std::cout<<"catch block\n";
           mysql_free_result(res);
           mysql_close(conn);
       }
   }
   return 0;
}


