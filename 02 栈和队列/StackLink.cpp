#include "StackLink.h"

StackLink::StackLink()
{
    this->head = NULL;
}

StackLink::~StackLink()
{
    this->ClearStack();
}

bool StackLink::isEmpty()
{
    return this->head == NULL;
}

int StackLink::getLength()
{
    int i = 0;
    Node* p = this->head;
    while(p != NULL)
    {
        i++;
        p = p->next;
    }

    return i;
}

void StackLink::ClearStack()
{
    Node* p;
    while(this->head != NULL)
    {
        p = this->head->next;
        delete this->head;
        this->head = p;
    }
}

status StackLink::getTop(Data& item)
{
    if(this->head == NULL)
        return ERROR;

    item = this->head->data;

    return OK;
}

status StackLink::Push(Data item)
{
    Node* node = new Node;
    if(node == NULL)
        return ERROR;

    node->data = item;
    node->next = this->head;

    this->head = node;

    return OK;
}

status StackLink::Pop(Data& item)
{
    if(this->head == NULL)
        return ERROR;

    item = this->head->data;

    Node* p = this->head;
    this->head = this->head->next;

    delete p;

    return OK;
}