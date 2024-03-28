// author: BEAUFILS Noah
// date: march/28/2024

#include "gc.h"

void	foo(void)
{
	char			*ptr5;
	unsigned char	*ptr6;

	ptr5 = gc_alloc(sizeof(char) * 3, 1);
	ptr6 = gc_alloc(sizeof(unsigned char) * 32, 3);
}

int	main(void)
{
	char	*ptr1;
	int		*ptr2;
	void	*ptr3;
	int		**ptr4;

	ptr1 = gc_alloc(sizeof(char) * 5, 1);
	ptr2 = gc_alloc(sizeof(int) * 27, 1);
	printf("\x1B[1m\x1B[35mtest1: <gc_free>\x1B[0m\n");
	print_addr();
	gc_free(ptr1);
	print_addr();
	ptr3 = gc_alloc(13, 2);
	ptr4 = gc_alloc(sizeof(int) * 5, 2);

	printf("\x1B[1m\x1B[32mtest2: <foo>\x1B[0m\n");
	print_addr();
	foo();
	print_addr();

	printf("\x1B[1m\x1B[34mtest3: <gc_free_p>\x1B[0m\n");
	gc_free_p(1);
	print_addr();

	printf("\x1B[1m\x1B[33mtest4: <gc_free_all>\x1B[0m\n");
	gc_free_all();
	print_addr();

	return (0);
}