CXX = g++
CXXFLAGS = -Wall

proj4: Animal.o Safari.o Herbivore.o Carnivore.o Elephant.o Gazelle.o Lion.o driver.cpp
	$(CXX) $(CXXFLAGS) Animal.o Safari.o driver.cpp Herbivore.o Carnivore.o Elephant.o Gazelle.o Lion.o -o proj4

Safari.o: Safari.cpp Safari.h
	$(CXX) $(CXXFLAGS) -c Safari.cpp

Animal.o: Animal.cpp Animal.h
	$(CXX) $(CXXFLAGS) -c Animal.cpp

Herbivore.o: Animal.o Herbivore.cpp Herbivore.h
	$(CXX) $(CXXFLAGS) -c Herbivore.cpp

Carnivore.o: Animal.o Carnivore.cpp Carnivore.h
	$(CXX) $(CXXFLAGS) -c Carnivore.cpp

Elephant.o: Elephant.cpp Elephant.h Herbivore.o
	$(CXX) $(CXXFLAGS) -c Elephant.cpp

Gazelle.o: Gazelle.cpp Gazelle.h Herbivore.o
	$(CXX) $(CXXFLAGS) -c Gazelle.cpp

Lion.o: Lion.cpp Lion.h Carnivore.o
	$(CXX) $(CXXFLAGS) -c Lion.cpp

clean:
	rm *.o*
	rm *~

run:
	./proj4

run1:
	./proj4 proj4_t1.txt
run2:
	./proj4 proj4_t2.txt
run3:
	./proj4 proj4_t3.txt
val1:
	valgrind ./proj4 proj4_t1.txt
val2:
	valgrind ./proj4 proj4_t2.txt
val3:
	valgrind ./proj4 proj4_t3.txt
