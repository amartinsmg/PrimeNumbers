#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "nth_prime.h"

void callback(int num, void *data)
{
  static int buffer = 0;
  char *str = (char *)(data + buffer);
  buffer += sprintf(str, "(%d),", num);
}

int main()
{
  PGconn *conn = PQconnectdb("user=root password=root123 dbname=prime_numbers");
  int prime, num = 1000000;
  char *query = (char *)calloc(12 * num, sizeof(*query));
  PGresult *res;

  sprintf(query, "INSERT INTO tb_single_command(num) VALUES ");

  if (PQstatus(conn) == CONNECTION_BAD)
  {
    fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
    exit(-1);
  }

  res = PQexec(conn, "DROP TABLE IF EXISTS tb_single_command;"
                     "CREATE TABLE tb_single_command(id SERIAL PRIMARY KEY, num INTEGER NOT NULL)");

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