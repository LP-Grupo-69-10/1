test:
	gcc -Wall libs/*.c test.c -o .test
	./.test
