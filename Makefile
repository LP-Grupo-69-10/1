compile:
	gcc -Wall libs/*.c main.c -o kanban

run:
	./kanban

clear:
	rm -rf files/*

emacs:
	emacs main.c libs/* &
