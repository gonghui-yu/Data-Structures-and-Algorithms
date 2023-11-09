#include "DoubleLinkList.h"

DoubleLinkList::DoubleLinkList()
{
    this->head = new Node;
    this->head->prior = NULL;
    this->head->next = NULL;
}

DoubleLinkList::~DoubleLinkList()
{
    Node* p = this->head->next;
    Node* q = NULL;
    while(p != NULL && p != this->head)
    {
        q = p->next;
        delete p;
        p = p->next;
    }
    delete this->head;
}