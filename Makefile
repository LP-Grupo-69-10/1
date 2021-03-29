run:
	gcc -Wall libs/*.c main.c -o .main
	./.main

emacs:
	emacs main.c libs/* &
