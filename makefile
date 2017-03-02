all: A3

A3: main.c Q1_1.c Q2_1.c Q1_2.c
		 gcc -o A3 main.c Q1_1.c Q2_1.c Q1_2.c

clean:
	rm -f *.o
	rm A3
