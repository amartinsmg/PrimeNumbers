# PrimeNumbers

It's a personal project for a prime numbers calculator in C. It uses the nth_prime function (in [nth_prime.h](./src/nth_prime.h)) to calculate the nth prime number, and, for each prime number found, it calls a callback function that receives this number and a void pointer.

The main objective of this project is to observe the difference in runtime for the different operations done by each callback function.

The measurements in the table below were performed using the `time` command in Git Bash. The items are organized by execution time.

| Operation                                                                  | Source file                                    | Average Runtime |
| -------------------------------------------------------------------------- | ---------------------------------------------- | --------------- |
| No operation                                                                | [calc.c](./src/calc.c)                         | 1.418s          |
| Multiple write operations on a binary file                                 | [bin_multiple.c](./src/bin_multiple.c)         | 1.470s          |
| Single write operation on a binary file                                    | [bin_single.c](./src/bin_single.c)             | 1.526s          |
| Single write operation on a text file                                      | [text_single.c](./src/text_single.c)           | 1.569s          |
| Multiple write operations on a text file                                   | [text_multiple.c](./src/text_multiple.c)       | 1.837s          |
| Insertion into the Postgres database with a single command                 | [db_singlecommand.c](./src/db_singlecommand.c) | 15.430s         |
| Insertions into the Postgres database concatenated into a single statement | [db_singleexec.c](./src/db_singleexec.c)       | 32.763s         |
| Insertions into the Postgres database executed in a single transaction     | [db_singleblock.c](./src/db_singleblock.c)     | 13m 37.060s     |
| Insertions into the Postgres database executed in multiple transactions    | [db_multiblock.c](./src/db_multiblock.c)       | 112m 20.118s    |

<sup>Builds and runs were performed using a laptop with Windows 10.0.22000, Intel Core i5-8250U and 8 GB of RAM in GNU bash.<sup>

All source files can be compiled using this command:

```sh
make
```

<sup>**Note**: before compiling, open the [Makefile](./Makefile) and verify if the variables Include, LibPG_path and CC store, respectively, the actual location of the [Postgres header files](https://www.postgresql.org/docs/9.1/libpq.html), the location of the [Postgres object files library](https://www.postgresql.org/docs/9.1/libpq.html) and the C compiler installed in your machine. To get the Postgres header library you can clone this [repository](https://github.com/ClickHouse/libpq).</sup>

To run the container with the PostgreSQL database, run the command below:

```sh
docker compose up
```

<sub>**Note**: before run this command, make sure you have installed the [Docker engine](https://docs.docker.com/engine/install/) and the [Docker Compose](https://docs.docker.com/compose/install/).</sub>
