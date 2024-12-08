all:
	gcc main.c quadro.c menu.c -o main
run:
	./main
clean:
	rm main