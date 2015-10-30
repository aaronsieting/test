gcc: stmachine.c
	gcc stmachine.c

run: ./a.out
	./a.out

clean:
	rm *.out
