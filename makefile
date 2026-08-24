CC = gcc
CFLAGS = -Wall -Wextra

all: meu_programa

meu_programa: main.o funcoes.o
	$(CC) $(CFLAGS) -o meu_programa main.o order_list.o

main.o: main.c order_list.h
	$(CC) $(CFLAGS) -c -o main.o main.c

funcoes.o: order_list.c order_list.h
	$(CC) $(CFLAGS) -c -o order_list.o order_list.c

clean:
	rm -f meu_programa main.o order_list.o