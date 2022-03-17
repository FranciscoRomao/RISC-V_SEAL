#include <stdio.h>

unsigned long read_cycles(void)
{
	unsigned long cycles;
	asm volatile ("rdcycle %0" : "=r" (cycles));
	return cycles;
}

int main()
{
	printf("%ld\n", read_cycles());
	printf("%ld\n", read_cycles());
	return 0;
}
