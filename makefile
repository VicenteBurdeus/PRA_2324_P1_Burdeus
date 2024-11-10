bin/TestListArray: TestListArray.cpp List.h ListArray.h
	mkdir -p bin
	g++ -o bin/TestListArray TestListArray.cpp

bin/testNode: testNode.cpp Node.h
        mkdir -p bin
        g++ -o bin/testNode testNode.cpp Node.h

bin/testNode: testNode.cpp Node.h
        mkdir -p bin
        g++ -o bin/testNode testNode.cpp Node.h

bin/testList: testList.cpp List.h ListArray.h
		mkdir -p bin
		g++ -o bin/testList testList.cpp
		
clean:
	rm -r *.o *.gch bin
