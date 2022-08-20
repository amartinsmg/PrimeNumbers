#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "nth_prime.h"

void callback(int num, void *data)
{
  static int buffer = 0;
  char *str = (char *)data;
  buffer += sprintf(str + buffer, "(%d),", num);
}

int main()
{
  PGconn *conn = PQconnectdb("user=root password=root123 dbname=prime_numbers");
  char *query = (char *)calloc(12000000, sizeof(*query));
  int prime, num = 1000000;
  PGresult *res;

  sprintf(query, "INSERT INTO single_command(num) VALUES ");

  if (PQstatus(conn) == CONNECTION_BAD)
  {
    fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
    exit(-1);
  }

  res = PQexec(conn, "DROP TABLE IF EXISTS single_command;"
                     "CREATE TABLE single_command(id SERIAL PRIMARY KEY, num INTEGER NOT NULL)");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    fprintf(stderr, "%s\n", PQerrorMessage(conn));
    exit(-1);
  }

  prime = nthPrime(num, (void *)(query + strlen(query)), callback);

  query[strlen(query) - 1] = '\0';

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