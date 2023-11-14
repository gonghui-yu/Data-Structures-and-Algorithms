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

// 链表节点
struct Node{
    Data data;
    Node* next;
};


// 链式存储结构的栈
// top指向第n个元素，第n个元素的指针指向第n-1个元素，与一般链表指向相反
class StackLink{
private:
    Node* head;

public:
    StackLink(); // 初始化栈
    ~StackLink(); // 销毁栈

    bool isEmpty(); // 判断栈是否为空
    int getLength(); // 获取栈长度
    void ClearStack(); // 清空栈

    status getTop(Data& item); // 获取栈顶元素，但不删除

    status Pop(Data& item); // 出栈，获取栈顶元素，并删除
    status Push(Data item); // 入栈
};