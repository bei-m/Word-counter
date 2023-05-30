CXXFLAGS=-O3 -std=c++17

main: prog.o
	g++ $(CXXFLAGS) -o prog prog.cpp
prog.o: prog.cpp
	g++ -c $(CXXFLAGS) prog.cpp
clean:
	-- rm *.o 
	-- rm prog
	-- rm rezultatai.txt

