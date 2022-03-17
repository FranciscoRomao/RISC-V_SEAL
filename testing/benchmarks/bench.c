#include <stdio.h>
#include <seal.h>

unsigned long read_cycles(void)
{
	unsigned long cycles;
	printf("Working!!!"\n);
	asm volatile ("rdcycle %0" : "=r" (cycles));
	return cycles;
}

int main()
{
	printf("%ld\n", read_cycles());
	printf("%ld\n", read_cycles());
	print("-----Nice-----");
	return 0;
}
