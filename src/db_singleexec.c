#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "nth_prime.h"

void callback(int num, void *data)
{
  static int buffer = 0;
  char *str = (char *)(data + buffer);
  buffer += sprintf(str, "INSERT INTO tb_single_exec(num) VALUES (%d);", num);
}

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