test:
	gcc -Wall libs/*.c test.c -o .test
	./.test

mike:
	emacs -nw test.c libs/*
