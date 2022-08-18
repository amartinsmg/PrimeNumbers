# PrimeNumbers

| Mode                                                              | Source file                                    | Average Runtime |
| ----------------------------------------------------------------- | ---------------------------------------------- | --------------- |
| No callback                                                       | [calc.c](./src/calc.c)                         | 1.459s          |
| Single file write operation                                       | [text_single.c](./src/text_single.c)           | 1.724s          |
| Multiple file write operations                                    | [text_multiple.c](./src/text_multiple.c)       | 1.916s          |
| Insertion into the database with a single command                 | [db_singlecommand.c](./src/db_singlecommand.c) | 15.430s         |
| Insertions into the database concatenated into a single statement | [db_singleexec.c](./src/db_singleexec.c)       | 32.763s         |
| Insertions into the database executed in a single transaction     | [db_singleblock.c](./src/db_singleblock.c)     | 13m 37.060s     |
| Insertions into the database executed in multiple transactions    | [db_multiblock.c](./src/db_multiblock.c)       | 110m            |
