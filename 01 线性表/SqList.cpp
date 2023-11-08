#include "SqList.h"

SqList::SqList(int length)
{
    this->list = new Element[length];
    this->length = 0;
    this->max_length = length;
}

SqList::~SqList()
{
    delete this->list;
}

bool operator==(const Element& elem1, const Element& elem2)
{
    return (elem1.e == elem2.e && elem1.p == elem2.p);
}

void SqList::ClearList()
{
    this->length = 0;
}

bool SqList::IsEmpty()
{
    return this->length == 0;
}

int SqList::GetLength()
{
    return this->length;
}

status SqList::GetElem(int i, Element& elem)
{ // i从 1 ~ length
    if(i > this->length || i < 1)
        return ERROR;
    
    elem = this->list[i - 1];
    return OK;
}

int SqList::LocateElem(const Element& elem)
{ // 顺序查找
    for(int i = 0; i < this->length; i++){
        if(elem == this->list[i])
            return i + 1;
    }

    return 0;
}

status SqList::PriorElem(const Element& elem, Element& prior_elem)
{
    
}

status SqList::NextElem(Element current_element)
{

}

status SqList::ListInsert(int i, const Element& elem)
{
    // 判断插入位置是否合法
    if(i < 1 || i > this->length + 1)
        return ERROR;

    // 判断是否已满
    if(this->length == this->max_length)
        return ERROR;

    // 空出第i个位置
    for(int j = this->length - 1;j >= i - 1;j--){
        this->list[j + 1] = this->list[j];
    }

    // 将新元素插入第i个位置
    this->list[i - 1] = elem;

    // 表长+1
    this->length++;

    return OK;
}

status SqList::ListDelete(int i)
{
    // 判断删除位置是否合法
    if(i < 1 || i > this->length)
        return ERROR;

    // 第i个位置后面元素前移
    for(int j = i;j <= this->length - 1; j++){
        this->list[j - 1] = this->list[j];
    }

    // 表长-1
    this->length--;

    return OK;
}