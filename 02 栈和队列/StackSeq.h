#include <iostream>

using namespace std;

// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// 函数返回值类型，其值为函数结果状态代码
typedef int status;

struct Data {

};

// 顺序存储结构的栈，第一个元素为栈底
class StackSeq{
private:
    Data* top; // 指向栈顶元素的上一个位置
    Data* base; // 指向栈底

    int stack_size; // 最大长度

public:
    StackSeq(int length); // 初始化栈
    ~StackSeq(); // 销毁栈

    bool isEmpty(); // 判断栈是否为空
    int getLength(); // 获取栈长度
    void ClearStack(); // 清空栈

    status getTop(Data& item); // 获取栈顶元素，但不删除

    status Pop(Data& item); // 出栈，获取栈顶元素，并删除
    status Push(Data item); // 入栈
};