# Prime Numbers

This is a personal project that calculates prime numbers using C. It utilizes the nth_prime function in [nth_prime.h](./src/nth_prime.h) to calculate the nth prime number. For each prime number found, a callback function is called that receives the number and a void pointer.

The main goal of this project is to measure the difference in runtime for each operation done by the callback functions.

## Runtime

The table below shows the runtime for each operation, measured using the `time` command in Git Bash. The operations are ordered by execution time.

| Operation                                                                  | Source file                                    | Average Runtime |
| -------------------------------------------------------------------------- | ---------------------------------------------- | --------------- |
| No operation                                                               | [calc.c](./src/calc.c)                         | 1.418s          |
| Multiple write operations on a binary file                                 | [bin_multiple.c](./src/bin_multiple.c)         | 1.470s          |
| Single write operation on a binary file                                    | [bin_single.c](./src/bin_single.c)             | 1.526s          |
| Single write operation on a text file                                      | [text_single.c](./src/text_single.c)           | 1.569s          |
| Multiple write operations on a text file                                   | [text_multiple.c](./src/text_multiple.c)       | 1.837s          |
| Insertion into the Postgres database with a single command                 | [db_singlecommand.c](./src/db_singlecommand.c) | 15.430s         |
| Insertions into the Postgres database concatenated into a single statement | [db_singleexec.c](./src/db_singleexec.c)       | 32.763s         |
| Insertions into the Postgres database executed in a single transaction     | [db_singleblock.c](./src/db_singleblock.c)     | 13m 37.060s     |
| Insertions into the Postgres database executed in multiple transactions    | [db_multiblock.c](./src/db_multiblock.c)       | 112m 20.118s    |

<sup>The builds and runs were performed on a laptop with Windows 10.0.22000, Intel Core i5-8250U and 8 GB of RAM in GNU bash.<sup>

## Getting Started

The [Makefile](./Makefile) provides an easy way to compile all source files to binary format. To compile all source files at once, simply clone this repository and run the command `make`.

However, it is important to note that you may need to open the Makefile and verify the values of some variables, such as CC for the compiler, Include for the include path, and LibPG_path for the path to the PostgreSQL library.

To run the docker container with the PostgreSQL database, run the command below:

```sh
docker compose create
docker start db_container
```
<sub>**Note**: Before run this command, make sure you have installed the [Docker engine](https://docs.docker.com/engine/install/) and the [Docker Compose](https://docs.docker.com/compose/install/).</sub>

## Contributing

Contributions to the Prime Numbers project are welcome. If you find a bug or have a suggestion for an improvement, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](./LICENSE).
