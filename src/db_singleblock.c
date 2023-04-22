#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "nth_prime.h"

/**
  This function receives a prime number and a pointer to a PostgreSQL connection
  object. It creates a SQL query to insert the prime number into a table named
  tb_single_block. The query is executed using the connection object.
  @param num the prime number to be inserted into the table
  @param data a void pointer to a PostgreSQL connection object
*/

void callback(int num, void *data)
{
  PGconn *conn = (PGconn *)data;
  PGresult *res;
  char query[50];
  sprintf(query, "INSERT INTO tb_single_block(num) VALUES(%d);", num);
  res = PQexec(conn, query);
  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    fprintf(stderr, "%s\n", PQerrorMessage(conn));
    exit(-1);
  }
}

/**
  The function connects to the database using the credentials specified in the connection string and
  creates a table called tb_single_block, and begins a trasaction. It calculates the n first prime
  numbers using a function named nthPrime, and stores them into the table using the callback function,
  and commits the trasaction.
  @return The exit status of the program.
*/

int main()
{
  PGconn *conn = PQconnectdb("user=root password=root123 dbname=prime_numbers");
  int prime, num = 1000000;
  PGresult *res;

  if (PQstatus(conn) == CONNECTION_BAD)
  {
    fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
    PQfinish(conn);
    return 1;
  }

  res = PQexec(conn, "DROP TABLE IF EXISTS tb_single_block;"
                     "CREATE TABLE tb_single_block(id SERIAL PRIMARY KEY, num INTEGER NOT NULL)");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    fprintf(stderr, "%s\n", PQerrorMessage(conn));
    PQfinish(conn);
    return 1;
  }

  PQexec(conn, "BEGIN");
  prime = nthPrime(num, (void *)conn, callback);
  PQexec(conn, "COMMIT");

  PQfinish(conn);

  printf("%d\n", prime);

  return 0;
}