bin/TestListArray: TestListArray.cpp List.h ListArray.h
	mkdir -p bin
	g++ -o bin/TestListArray TestListArray.cpp

bin/testNode: testNode.cpp Node.h
        mkdir -p bin
        g++ -o bin/testNode testNode.cpp Node.h

clean:
	rm -r *.o *.gch bin
