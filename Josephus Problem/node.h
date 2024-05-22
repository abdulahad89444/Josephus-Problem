struct person
{
    char name[20];
    int id;
};
struct node
{
    struct person data;
    struct node * next;
    struct node * prev;
};
