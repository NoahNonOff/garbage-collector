# C garbage collector
Are you fed up with memory leaks, with valgrind blaming you for your 45,000 bits definitely lost and hours of debugging to find out where the damn leaks are ?<br>
Well, that's all in the past, because today I'm offering you a C implementation of a garbage collector.

### A what !?
According to [wikipedia](https://en.wikipedia.org/wiki/Garbage_collection_(computer_science)), in computer science, garbage collection (GC) is a form of automatic memory management invented by American computer scientist John McCarthy around 1959 to simplify manual memory management in Lisp. Garbage collection relieves the programmer from doing manual memory management, where the programmer specifies what objects to de-allocate and return to the memory system and when to do so. Unfortunately it may take a significant proportion of a program's total processing time, and affect performance as a result. 

### Dependencies
None...
### How it works
To create the garbage collector, I use a linked list (see [gc.h](https://github.com/NoahNonOff/garbage-collector/blob/main/gc.h)) saved in a static variable. The linked list store 3 informations : the size of the allocation, the address of the allocated block and an integer that can be used to differentiate memory blocks<br>
5 functions are available in the library : One function to allocate memory, 3 functions to free specific blocks and one last function to show the current heap memory in use.<br>
```C
void	*gc_alloc( size_t sz, int imp ); /* function use to allocate memory */
void	gc_free( void *ptr ); /* function use to free a specific block */
void	gc_free_p( int imp ); /* function use to free all blocks of type <imp> */
void	gc_free_all( void ); /* function use to free all blocks */
void	print_addr(void); /* function use to show the heap memory in use */
```
<br>

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
<br><br>Date: Mar 2024
