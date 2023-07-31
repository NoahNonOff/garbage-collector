#include "p_alloc.h"

t_alloc_ptr	*addr_save(t_alloc_ptr *ptr, int code);

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
		printf("%d -> |%p| [%3ld]\n", i++, lst->addr, lst->size);
		lst = lst->next;
	}
	printf("\n-------------------------------\n");
}

int	main(void)
{
	void	*test1 = p_alloc(25);
	void	*test2 = p_alloc(48);
	void	*test3 = p_alloc(3);

	print_addr();
	p_free(test2);
	print_addr();
	p_free_all();

	return (0);
}