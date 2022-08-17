# PrimeNumbers

| Source file                                                       | Average Runtime |
| ----------------------------------------------------------------- | --------------- |
| No callback                                                       | 1.459s          |
| Single file write operation                                       | 1.724s          |
| Multiple file write operations                                    | 1.916s          |
| Insertion into the database with a single command                 | 15.430s         |
| Insertions into the database concatenated into a single statement | 32.763s         |
| Insertions into the database executed in a single transaction     | 13m 37.060s     |
| Insertions into the database executed in multiple transactions    |                 |
