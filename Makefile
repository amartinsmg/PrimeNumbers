# This Makefile is used to compile and build several C programs using the gcc compiler, as well as the PostgreSQL library in some of them.
# It provides different targets to compile and build different programs, including those that interact with a PostgreSQL database.

# Targets
# all - This target is the default and will build all other targets.
# dir - creates the build directory if it doesn't exist. 
# calc - compiles src/calc.c, generating the executable build/calc.
# text-single - compiles src/text_single.c, generating the executable build/text_single.
# text-multiple - compiles src/text_multiple.c, generating the executable build/text_multiple.
# bin-single - compiles src/bin_single.c, generating the executable build/bin_single.
# bin-multiple - compiles src/bin_multiple.c, generating the executable build/bin_multiple.
# db_multiblock - compiles src/db_multiblock.c, generating the executable build/db_multiblock. It requires the PostgreSQL library.
# db_singleblock - compiles src/db_singleblock.c, generating the executable build/db_singleblock. It requires thePostgreSQL library.
# db_singleexec - compiles src/db_singleexec.c, generating the executable build/db_singleexec. It requires the PostgreSQL library. 
# db_singlecommand - compiles src/db_singlecommand.c, generating the executable build/db_singlecommand. It requires the PostgreSQL library.
# clean - removes all files in the build directory.

# Variables
# CC: Defines the C compiler to be used, in this case, it is set to gcc.
# Include: Defines the include path for header files, in this case, it is set to "C:/Program Files/PostgreSQL/15/include".
# LibPG_path: Defines the path where the PostgreSQL library is installed, in this case, it is set to "C:/Program Files/PostgreSQL/15/lib".



CC=gcc
Include=-I "C:/Program Files/PostgreSQL/15/include"
LibPG_path=-L "C:/Program Files/PostgreSQL/15/lib"


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
	$(CC) -o build/db_multiblock $(Include) $(LibPG_path) -O3 src/db_multiblock.c -lpq

db_singleblock: dir
	$(CC) -o build/db_singleblock $(Include) $(LibPG_path) -O3 src/db_singleblock.c -lpq

db_singleexec: dir
	$(CC) -o build/db_singleexec $(Include) $(LibPG_path) -O3 src/db_singleexec.c -lpq

db_singlecommand: dir
	$(CC) -o build/db_singlecommand $(Include) $(LibPG_path) -O3 src/db_singlecommand.c -lpq

clean:
	rm build/*
