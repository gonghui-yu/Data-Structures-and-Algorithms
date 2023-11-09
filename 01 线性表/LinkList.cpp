#include "LinkList.h"

LinkList::LinkList()
{
    this->head = new Node;
    this->head->next = NULL;
}

LinkList::~LinkList()
{
    Node* p = NULL;
    while(this->head != NULL){
        p = this->head;
        this->head = this->head->next;
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
    return this->head->next == NULL;
}

void LinkList::ClearList()
{
    Node* p, * q;
    p = this->head->next; // 从第一个数据节点开始删除
    while(p != NULL){
        q = p->next;
        delete p;
        p = q;
    }
    this->head->next = NULL;
}

int LinkList::GetLength()
{
    int i = 0;
    Node* p = this->head->next;
    
    while(p != NULL){
        i++;
        p = p->next;
    }

    return i;
}

status LinkList::GetData(int i, Data& data)
{
    if(i < 1)
        return ERROR;
    
    int j = 1;
    Node* p = this->head->next;

    while(p!= NULL && j < i){
        p = p->next;
        j++;
    }

    if(p == NULL || j >= i) // 第i个节点不存在
        return ERROR;
    
    data = p->data;
    return OK;
}

status LinkList::LocateElem(const Data& data, int& i)
{
    int j = 1;
    Node* p = this->head->next;

    while(p != NULL && p->data != data){
        j++;
        p = p->next;
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

status LinkList::ListInsert(int index, Data data)
{
    // 找到第index-1个节点地址
    int j = 0;
    Node* p = this->head->next;
    while(p != NULL && j < index - 1)
    {
        p = p->next;
        j++;
    }

    // 如果为NULL，则代表实际节点数小于index-1
    if(p == NULL)
        return ERROR;

    // 创建新节点，并插入第index个节点前
    Node* node = new Node;
    node->data = data;
    node->next = p->next;

    // 将新节点插入第index-1个节点后
    p->next = node;

    return OK;
}

status LinkList::ListDelete(int index, Data& data)
{
    // 找到第index-1个节点地址
    int j = 0;
    Node* p = this->head->next;
    while(p != NULL && j < index - 1)
    {
        p = p->next;
        j++;
    }

    // 如果为NULL，则代表实际节点数小于index
    if(p->next == NULL)
        return ERROR;

    Node* q = p->next;

    // 将第index+1个节点插入index-1节点后
    p->next = q->next;

    data = q->data;

    // 删除第index个节点
    delete q;

    return OK;
}

status LinkList::HeadInsert(Data data)
{
    Node* node = new Node;
    node->data = data;

    node->next = this->head->next;
    this->head->next = node;

    return OK;
}

status LinkList::TailInsert(Data data)
{
    Node* node = new Node;
    node->data = data;
    node->next = NULL;

    // 尾指针
}
