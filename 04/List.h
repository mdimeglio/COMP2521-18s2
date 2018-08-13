typedef struct node *List;


List empty();
List cons(int v, List l);
int head(List l);
List tail(List l);
int isEmpty(List l);

void drop(List l);
List map(int (*f)(int), List l);
int foldr(int (*f)(int,int), int z, List l);
int length(List l);