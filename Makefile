all: main iterative.lst recursive.lst

main: main.o iterative.o recursive.o ackermann.o ackermann_asm2.o
	g++ $^ -o $@ $(CXXFLAGS)

%.o: %.cpp 
	$(CXX) -c $< -o $@ $(CXXFLAGS)

%.lst: %.cpp
	g++ -O0 -c -fverbose-asm -Wa,-adhln $< > $@

%.o: %.asm
	nasm -f elf64 -o $@ $<

clean:
	rm -rf *.o *.lst
