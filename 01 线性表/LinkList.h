#include <iostream>

using namespace std;
/*
带头结点的单链表

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
    Node* node_next; // 指针域
};

class LinkList{
private:
    Node* node_head; // 头指针，指向头节点

public:
    LinkList();
    ~LinkList();

    friend bool operator==(const Data& data1, const Data& data2);

    bool IsEmpty(); // 是否为空链表
    void ClearList(); // 清空链表
    int GetLength(); // 获取链表长度

    status GetData(int i, Data& data); // 获取链表第i个元素
    status GetData(const Data& data, int& i); // 获取链表相同数据的节点编号
};