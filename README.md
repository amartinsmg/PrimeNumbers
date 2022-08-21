# PrimeNumbers

| Mode                                                              | Source file                                    | Average Runtime |
| ----------------------------------------------------------------- | ---------------------------------------------- | --------------- |
| No callback                                                       | [calc.c](./src/calc.c)                         | 1.418s          |
| Multiple write operations on a binary file                        | [bin_multiple.c](./src/bin_multiple.c)         | 1.470s          |
| Single write operation on a binary file                           | [bin_single.c](./src/bin_single.c)             | 1.526s          |
| Single write operation on a text file                             | [text_single.c](./src/text_single.c)           | 1.569s          |
| Multiple write operations on a text file                          | [text_multiple.c](./src/text_multiple.c)       | 1.837s          |
| Insertion into the database with a single command                 | [db_singlecommand.c](./src/db_singlecommand.c) | 15.430s         |
| Insertions into the database concatenated into a single statement | [db_singleexec.c](./src/db_singleexec.c)       | 32.763s         |
| Insertions into the database executed in a single transaction     | [db_singleblock.c](./src/db_singleblock.c)     | 13m 37.060s     |
| Insertions into the database executed in multiple transactions    | [db_multiblock.c](./src/db_multiblock.c)       | 112m 20.118s            |
