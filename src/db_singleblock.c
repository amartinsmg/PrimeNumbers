#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "nth_prime.h"

void callback(int num, void *data)
{
  PGconn *conn = (PGconn *)data;
  char query[50];
  sprintf(query, "INSERT INTO single_block(num) VALUES(%d);", num);
  PQexec(conn, query);
}

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

  res = PQexec(conn, "DROP TABLE IF EXISTS single_block;"
                     "CREATE TABLE single_block(id SERIAL PRIMARY KEY, num INTEGER NOT NULL)");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    fprintf(stderr, "%s\n", PQerrorMessage(conn));
    PQfinish(conn);
    return 1;
  }

  PQexec(conn, "BEGIN");
  prime = nthPrime(num, (void *)conn, callback);
  PQexec(conn, "COMMIT");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    fprintf(stderr, "%s\n", PQerrorMessage(conn));
    exit(-1);
  }

  PQfinish(conn);

  printf("%d\n", prime);

  return 0;
}