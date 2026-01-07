typedef struct builtin
{
	char *name;
	void (*func)(char *);
} builtin_t;