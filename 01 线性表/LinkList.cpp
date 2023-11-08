#include "LinkList.h"

LinkList::LinkList()
{
    this->node_head = new Node;
    this->node_head->node_next = NULL;
}

LinkList::~LinkList()
{
    Node* p = NULL;
    while(this->node_head != NULL){
        p = this->node_head;
        this->node_head = this->node_head->node_next;
        delete p;
    }
}

bool operator!=(const Data &data1, const Data &data2)
{
    return (data1.id != data2.id ||
            data1.name != data2.name ||
            data1.score != data2.score);
}

bool LinkList::IsEmpty()
{
    return this->node_head->node_next == NULL;
}

void LinkList::ClearList()
{
    Node* p, * q;
    p = this->node_head->node_next; // 从第一个数据节点开始删除
    while(p != NULL){
        q = p->node_next;
        delete p;
        p = q;
    }
    this->node_head->node_next = NULL;
}

int LinkList::GetLength()
{
    int i = 0;
    Node* p = this->node_head->node_next;
    
    while(p != NULL){
        i++;
        p = p->node_next;
    }

    return i;
}

status LinkList::GetData(int i, Data& data)
{
    if(i < 1)
        return ERROR;
    
    int j = 1;
    Node* p = this->node_head->node_next;

    while(p!= NULL && j < i){
        p = p->node_next;
        j++;
    }

    if(p == NULL || j >= i) // 第i个节点不存在
        return ERROR;
    
    data = p->data;
    return OK;
}

status LinkList::GetData(const Data& data, int& i)
{
    int j = 1;
    Node* p = this->node_head->node_next;

    while(p != NULL && p->data != data){
        j++;
        p = p->node_next;
    }

    if(p == NULL){
        i = 0;
        return ERROR;  
    }
    else{
        i = j;
        return OK;
    }     
}


