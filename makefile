bin/TestListArray: TestListArray.cpp List.h ListArray.h
	mkdir -p bin
	g++ -o bin/TestListArray TestListArray.cpp

clean:
	rm -r *.o *.gch bin
