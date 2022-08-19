LibPG_path="C:/Program Files/PostgreSQL/14/lib"

ifeq ($(OS), Windows_NT)
	Libs=-I libs -I libs/include
endif

all: calc text-single text-multiple db_multiblock db_singleblock db_singleexec db_singlecommand

lib:
	[ $(OS) != Windows_NT ] || [ -d libs ] || git clone https://github.com/ClickHouse/libpq.git libs

dir:
	[ -d build ] || mkdir build

calc: dir
	gcc -o build/calc -O3 src/calc.c

text-single: dir
	gcc -o build/text_single -O3 src/text_single.c

text-multiple: dir
	gcc -o build/text_multiple -O3 src/text_multiple.c

db_multiblock: dir lib
	gcc -o build/db_multiblock $(Libs) -L$(LibPG_path) -O3 src/db_multiblock.c -lpq

db_singleblock: dir lib
	gcc -o build/db_singleblock $(Libs) -L$(LibPG_path) -O3 src/db_singleblock.c -lpq

db_singleexec: dir lib
	gcc -o build/db_singleexec $(Libs) -L$(LibPG_path) -O3 src/db_singleexec.c -lpq

db_singlecommand: dir lib
	gcc -o build/db_singlecommand $(Libs) -L$(LibPG_path) -O3 src/db_singlecommand.c -lpq

clean:
	rm build/*
