all : main
main : main.c
	gcc -std=c11 main.c -o client
clean :
	rm client