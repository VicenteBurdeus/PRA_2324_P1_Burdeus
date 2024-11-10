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

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp

clean:
	rm -r *.o *.gch bin
