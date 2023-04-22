#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "nth_prime.h"

/**
  This function writes an SQL INSERT command for each integer found to a buffer.
  @param num The integer found.
  @param data A pointer to the buffer where the SQL commands will be written.
*/

void callback(int num, void *data)
{
  static int buffer = 0;
  char *str = (char *)(data + buffer);
  buffer += sprintf(str, "INSERT INTO tb_single_exec(num) VALUES (%d);", num);
}

/**
  The function connects to the database using the credentials specified in the
  connection string and creates a table called tb_single_exec. Next, it generates
  SQL INSERT commands for the n first prime numbers, and executes them against
  a PostgreSQL database. 
  @return The exit status of the program.
*/

int main()
{
  PGconn *conn = PQconnectdb("user=root password=root123 dbname=prime_numbers");
  int prime, num = 1000000;
  char *query = (char *)calloc(60 * num, sizeof(*query));
  PGresult *res;

  if (PQstatus(conn) == CONNECTION_BAD)
  {
    fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
    exit(-1);
  }

  res = PQexec(conn, "DROP TABLE IF EXISTS tb_single_exec;"
                     "CREATE TABLE tb_single_exec(id SERIAL PRIMARY KEY, num INTEGER NOT NULL)");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    fprintf(stderr, "%s\n", PQerrorMessage(conn));
    exit(-1);
  }

  prime = nthPrime(num, (void *)query, callback);

  res = PQexec(conn, query);

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    fprintf(stderr, "%s\n", PQerrorMessage(conn));
    exit(-1);
  }

  free(query);
  PQfinish(conn);

  printf("%d\n", prime);

  return 0;
}