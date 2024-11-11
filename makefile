bin/TestListArray: TestListArray.cpp List.h ListArray.h
	mkdir -p bin
	g++ -o bin/TestListArray TestListArray.cpp ListArray.cpp

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.cpp

bin/testList: testList.cpp List.h ListArray.h
	mkdir -p bin
	g++ -o bin/testList testList.cpp ListArray.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h ListLinked.cpp
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.cpp

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp

circle.o: circle.h circle.cpp Shape.o Point2D.o
	g++ -c circle.cpp

bin/testCircle: testCircle.cpp Shape.o Point2D.o circle.o
	mkdir -p bin
	g++ -o bin/testCircle testCircle.cpp Shape.o Point2D.o circle.o

rectangle.o: rectangle.h rectangle.cpp Shape.o Point2D.o
	g++ -c rectangle.cpp 

bin/testRectangle: testRectangle.cpp Shape.o Point2D.o rectangle.o
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.cpp Shape.o Point2D.o rectangle.o

clean:
	rm -rf *.o *.gch bin
