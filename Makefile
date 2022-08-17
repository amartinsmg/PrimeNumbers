all: calc text-single text-multiple db_multiblock db_singleblock db_singleexec db_singlecommand

dir:
	[ -d build ] || mkdir build

calc: dir
	gcc -o build/calc -O3 src/calc.c

text-single: dir
	gcc -o build/text_single -O3 src/text_single.c

text-multiple: dir
	gcc -o build/text_multiple -O3 src/text_multiple.c

db_multiblock: dir
	gcc -o build/db_multiblock -I"libs" -L"C:/Program Files/PostgreSQL/14/lib" -O3 src/db_multiblock.c -lpq

db_singleblock: dir
	gcc -o build/db_singleblock -I"libs" -L"C:/Program Files/PostgreSQL/14/lib" -O3 src/db_singleblock.c -lpq

db_singleexec: dir
	gcc -o build/db_singleexec -I"libs" -L"C:/Program Files/PostgreSQL/14/lib" -O3 src/db_singleexec.c -lpq

db_singlecommand: dir
	gcc -o build/db_singlecommand -I"libs" -L"C:/Program Files/PostgreSQL/14/lib" -O3 src/db_singlecommand.c -lpq

clean:
	rm build/*
