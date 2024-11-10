bin/TestListArray: TestListArray.cpp List.h ListArray.h
	mkdir -p bin
	g++ -o bin/TestListArray TestListArray.cpp ListArray.cpp

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.cpp

bin/testList: testList.cpp List.h ListArray.h
	mkdir -p bin
	g++ -o bin/testList testList.cpp ListArray.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h

clean:
	rm -r *.o *.gch bin
