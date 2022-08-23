Include=-I libs
LibPG_path="C:/Program Files/PostgreSQL/14/lib"
CC=gcc

all: calc text-single text-multiple bin-single bin-multiple db_multiblock db_singleblock db_singleexec db_singlecommand

dir:
	[ -d build ] || mkdir build

calc: dir
	$(CC) -o build/calc -O3 src/calc.c

text-single: dir
	$(CC) -o build/text_single -O3 src/text_single.c

text-multiple: dir
	$(CC) -o build/text_multiple -O3 src/text_multiple.c

bin-single: dir
	$(CC) -o build/bin_single -O3 src/bin_single.c

bin-multiple: dir
	$(CC) -o build/bin_multiple -O3 src/bin_multiple.c

db_multiblock: dir
	$(CC) -o build/db_multiblock $(Include) -L$(LibPG_path) -O3 src/db_multiblock.c -lpq

db_singleblock: dir
	$(CC) -o build/db_singleblock $(Include) -L$(LibPG_path) -O3 src/db_singleblock.c -lpq

db_singleexec: dir
	$(CC) -o build/db_singleexec $(Include) -L$(LibPG_path) -O3 src/db_singleexec.c -lpq

db_singlecommand: dir
	$(CC) -o build/db_singlecommand $(Include) -L$(LibPG_path) -O3 src/db_singlecommand.c -lpq

clean:
	rm build/*
