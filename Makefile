all release debug:
	g++ -c sqlite3cpp.cpp -Wall -I../$(BOOST_INCLUDE_DIR)
	mkdir -p lib
	ar rcs lib/libsqlite3cpp.a *.o

clean:
	rm -f *.o
	rm -rf ./lib

deps:
	apt-get install libboost-dev

install:

buildtestinsert:
	rm -f ./testinsert ./test.db
	g++ testinsert.cpp -Wall -I./ -I../$(BOOST_INCLUDE_DIR) -lsqlite3 lib/libsqlite3cpp.a  -o testinsert

buildtestselect:
	rm -f ./testselect ./test.db
	g++ testselect.cpp -Wall -I./ -I../$(BOOST_INCLUDE_DIR) -lsqlite3 lib/libsqlite3cpp.a  -o testselect

test: buildtestinsert buildtestselect
	./testinsert
	./testselect
