all:	c run

c:
	@gcc -Wall PG_MP_L2.c xorshift.c linearGen.c -o PG_MP_L2

cnasm:
	@nasm -felf64 gen_shift.asm
	@gcc -c PG_MP_L2.c xorshift.c linearGen.c
	@gcc  -no-pie gen_shift.o PG_MP_L2.o -o PG_MP_L2
	@rm *.o
run:
	./PG_MP_L2
