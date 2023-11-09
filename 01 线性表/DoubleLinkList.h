#include <iostream>

using namespace std;
/*
双向链表
 
*/

// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// 函数返回值类型，其值为函数结果状态代码
typedef int status;

typedef struct Data{
    string id;  // 学号
    string name;    // 姓名
    int score;  // 分数
};

// 链表节点
struct Node{
    Data data; // 数据域

    Node* prior; // 指向上一个节点
    Node* next; // 指向下一个节点
};

class DoubleLinkList{
private:
    Node* head; // 头指针，指向头节点

public:
    DoubleLinkList();
    ~DoubleLinkList();
};