compile:
	gcc -Wall libs/*.c main.c -o .main

run:
	./.main

emacs:
	emacs main.c libs/* &

clear:
	rm -rf .files/*
