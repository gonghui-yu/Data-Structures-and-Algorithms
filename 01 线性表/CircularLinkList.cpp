#include "CircularLinkList.h"

CircularLinkList::CircularLinkList()
{
    this->head = new Node;
    this->head->next = NULL;
}

CircularLinkList::~CircularLinkList()
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