#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    struct Node *next;
} Node;

Node *SListCreat();
int SListPrint(Node *head);
int SListNodeInsert(Node *head, int x, int y);
int SListNodeDel(Node *head, int x);
int SListFree(Node **head);
int SListNodeDelPro(Node *head, int x);
int SListNodeSort(Node *head);
int SListNodeInsertPro(Node *head, int x);
int SListNodeReverse(Node *head);

int main()
{
    Node *head = NULL;
    head = SListCreat();
    printf("\nbefore\n");
    SListPrint(head);

    SListNodeInsert(head, 5, 4);
    printf("\nadd 4 before 5\n");
    SListPrint(head);

    SListNodeDel(head, 5);
    printf("\ndel fist 5\n");
    SListPrint(head);

    SListNodeDelPro(head, 5);
    printf("\ndel all 5\n");
    SListPrint(head);

    SListNodeSort(head);
    printf("\nafter sort\n");
    SListPrint(head);

    SListNodeInsertPro(head, 3);
    printf("\nafter add 3 in order\n");
    SListPrint(head);

    SListNodeReverse(head);
    printf("\nafter reverse\n");
    SListPrint(head);

    SListFree(&head);

    system("pause");
    return 0;
}

Node *SListCreat()
{
    Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));
    (*head).id = -1;
    (*head).next = NULL;

    Node *pCur = head;
    Node *pNew = NULL;

    int data = 0;
    while (1)
    {
        printf("please enter the data: ");
        scanf("%d", &data);
        if (data == -1)
            break;

        pNew = (Node *)malloc(sizeof(Node));
        if (pNew == NULL)
        {
            continue;
        }
        (*pNew).id = data;
        (*pNew).next = NULL;
        (*pCur).next = pNew;
        pCur = pNew;
    }
    return head;
}

int SListPrint(Node *head)
{
    if (head == NULL)
        return -1;
    Node *pCur = (*head).next;
    printf("head -> ");
    while (pCur != NULL)
    {
        printf("%d -> ", (*pCur).id);
        pCur = (*pCur).next;
    }
    printf("NULL\n");
}

int SListNodeInsert(Node *head, int x, int y)
{
    if (head == NULL)
        return -1;
    Node *pPre = head;
    Node *pCur = (*pPre).next;
    //find
    while (pCur != NULL)
    {
        if ((*pCur).id == x)
            break;
        pPre = pCur;
        pCur = (*pCur).next;
    }
    //malloc
    Node *pNew = (Node *)malloc(sizeof(Node));
    if (pNew == NULL)
        return -2;
    (*pNew).id = y;
    (*pNew).next = NULL;

    //Insert
    (*pPre).next = pNew;
    (*pNew).next = pCur;

    return 0;
}

int SListNodeDel(Node *head, int x)
{
    if (head == NULL)
        return -1;
    Node *pPre = head;
    Node *pCur = (*pPre).next;
    while (pCur != NULL)
    {
        if ((*pCur).id == x)
        {
            (*pPre).next = (*pCur).next;
            free(pCur);
            pCur = NULL;
            return 0;
        }
        pPre = pCur;
        pCur = (*pCur).next;
    }
    printf("no such node with value %d\n", x);
    return -2;
}

int SListFree(Node **head)
{
    if (*head == NULL)
        return -1;
    Node *tmp = NULL;
    while (*head != NULL)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
    return 0;
}

int SListNodeDelPro(Node *head, int x)
{
    if (head == NULL)
        return -1;
    Node *pPre = head;
    int flag = 0;
    Node *pCur = (*pPre).next;
    while (pCur != NULL)
    {
        if ((*pCur).id == x)
        {
            (*pPre).next = (*pCur).next;
            free(pCur);
            pCur = (*pPre).next;
            flag = 1;
            continue;
        }
        pPre = pCur;
        pCur = (*pCur).next;
    }

    if (flag == 0)
    {
        printf("no such node with value %d\n", x);
        return -2;
    }
    return 0;
}

int SListNodeSort(Node *head)
{
    if (head == NULL || (*head).next == NULL)
        return -1;
    Node *pPre = NULL;
    Node *pCur = NULL;
    Node tmp;
    for (pPre = head; (*pPre).next != NULL; pPre = (*pPre).next)
    {
        for (pCur = (*pPre).next; pCur != NULL; pCur = (*pCur).next)
        {
            if ((*pPre).id > (*pCur).id)
            {
                tmp.id = (*pCur).id;
                (*pCur).id = (*pPre).id;
                (*pPre).id = tmp.id;
                /*
                tmp = *pCur;
                *pCur = *pPre;
                *pPre = tmp;

                tmp.next = (*pCur).next;
                (*pCur).next = (*pPre).next;
                (*pPre).next = tmp.next;
            */
            }
        }
    }
    return 0;
}

int SListNodeInsertPro(Node *head, int x)
{
    int ret = SListNodeSort(head);
    if (ret != 0)
        return -1;
    if (head == NULL)
        return -1;
    Node *pPre = head;
    Node *pCur = (*pPre).next;
    //find
    while (pCur != NULL)
    {
        if ((*pCur).id > x)
            break;
        pPre = pCur;
        pCur = (*pCur).next;
    }
    //malloc
    Node *pNew = (Node *)malloc(sizeof(Node));
    if (pNew == NULL)
        return -2;
    (*pNew).id = x;
    (*pNew).next = NULL;

    //Insert
    (*pPre).next = pNew;
    (*pNew).next = pCur;

    return 0;

    return 0;
}

int SListNodeReverse(Node *head)
{
    if (head == NULL || (*head).next == NULL || (*head).next->next == NULL)
        return -1;
    Node *pPre = (*head).next;
    Node *pCur = (*pPre).next;
    Node *tmp = NULL;
    while (pCur != NULL)
    {
        tmp = (*pCur).next;
        (*pCur).next = pPre;
        pPre = pCur;
        pCur = tmp;
    }
    (*head).next->next = NULL;
    (*head).next = pPre;
    return 0;
}