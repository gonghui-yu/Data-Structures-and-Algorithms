#include "StackSeq.h"

StackSeq::StackSeq(int length)
{
    this->base = new Data[length];
    this->top = this->base;

    this->stack_size = length;
}

StackSeq::~StackSeq()
{
    delete this->base;
}

bool StackSeq::isEmpty()
{
    return this->base == this->top;
}

int StackSeq::getLength()
{
    return (this->top - this->base) / sizeof(Data);
}

void StackSeq::ClearStack()
{
    this->top = this->base;
}

status StackSeq::getTop(Data& item)
{
    if(this->isEmpty())
        return ERROR;

    item = *(this->top - 1);

    return OK;
}

status StackSeq::Pop(Data& item)
{
    if(this->isEmpty())
        return ERROR;
    
    // top指针下移一位，取出所在位置元素
    item = *--this->top;

    return OK;
}

status StackSeq::Push(Data item)
{
    // 判断栈是否已满
    if(this->getLength() == this->stack_size)
        return ERROR;

    *this->top++ = item;

    return OK;
}