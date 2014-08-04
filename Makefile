BOOST_PATH=../../Software/Import/boost-1.47.0/ 

all:
	g++ -c sqlite3cpp.cpp -Wall -I$(BOOST_PATH)
	ar rcs libsqlite3cpp.a *.o 

clean:
	rf -f *.o *.a
    
buildtestinsert:
	rm -f ./testinsert ./test.db
	g++ testinsert.cpp -Wall -I./ -I$(BOOST_PATH) -lsqlite3 libsqlite3cpp.a  -o testinsert
    
buildtestselect:
	rm -f ./testselect ./test.db
	g++ testselect.cpp -Wall -I./ -I$(BOOST_PATH) -lsqlite3 libsqlite3cpp.a  -o testselect

test: buildtestinsert buildtestselect
	./testinsert
	./testselect
