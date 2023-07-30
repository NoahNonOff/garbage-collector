#include "p_alloc.h"

t_alloc_ptr	*addr_save(t_alloc_ptr *ptr, int code);

#define malloc(X) p_alloc(X)

void	print_addr(void)
{
	int			i;
	t_alloc_ptr	*lst;

	i = 0;
	lst = addr_save(NULL, 1);
	printf("Adress:\n");
	printf("-------------------------------\n\n");
	while (lst)
	{
		printf("%d -> |%p|\n", i++, lst->addr);
		lst = lst->next;
	}
	printf("\n-------------------------------\n");
}

int	main(void)
{
	void	*test1 = malloc(25);
	void	*test2 = malloc(48);
	void	*test3 = malloc(3);

	print_addr();
	p_free();

	return (0);
}