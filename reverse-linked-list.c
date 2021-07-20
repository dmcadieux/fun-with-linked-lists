#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    char word[8];
    struct node *next;
}
node;

node* create_list(char **);

node* reverse_list(node* list);
void print_list(node* list);
void free_list(node* list);

int main(void)
{
    char* r[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


    node* list = create_list(r);
    print_list(list);
    node* reversed = reverse_list(list);
    print_list(reversed);
    free_list(reversed);


}

// Constructs the linked list from an array
node* create_list(char* arr[])
{

    node* pointee = malloc(sizeof(node));


    if (pointee == NULL)
    {
        return 0;
    }

    for (int i = 0; i < 10; i++)
    {

        if (i == 0)
        {
            strcpy(pointee->word, arr[i]);
            pointee->next = NULL;
        }
        else
        {
            node* sticker = malloc(sizeof(node));
            if (sticker == NULL)
            {
                return 0;
            }

            strcpy(sticker->word, arr[i]);
            sticker->next = pointee;
            pointee = sticker;
        }

    }

    return pointee;
}

node* reverse_list(node* list)
{
    node* reversed;
    node* tmp;

    int i = 0;

    while (list != NULL)
    {
        if (i == 0)
        {
            reversed = list;
            list = list->next;
            reversed->next = NULL;
            i++;
        }
        else
        {
            tmp = list->next;
            list->next = reversed;
            reversed = list;
            list = tmp;
        }
    }

    return reversed;
}

void print_list(node* list)
{
    while (list != NULL)
    {
        printf("%s\n", list->word);
        list = list->next;
    }
}

void free_list(node* list)
{
    if (list != NULL)
    {
        node* tmp = list->next;
        free(list);
        list = tmp;
        free_list(list);
    }
}


/*
int * numstrings()
{
    static int r[10];

    int i;

    char
}
*/