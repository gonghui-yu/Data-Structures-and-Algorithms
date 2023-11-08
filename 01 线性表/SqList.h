#include <iostream>

using namespace std;

/*
顺序存储的线性表实现
特点：以物理位置相邻表示逻辑关系
优点：任一元素均可随机存取
缺点：进行插入和删除操作时，需移动大量的元素。存储空间不灵活
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

// 顺序线性表的元素类型结构体
struct Element{
    double p; // 多项式系数
    double e; // 多项式指数
};

class SqList{
private:
    Element* list;  // 线性表首地址
    int length;     // 线性表当前存在元素个数
    int max_length; // 线性表最大元素个数

public:
    SqList(int length);     // 构造一个空的线性表
    ~SqList();              // 销毁线性表，释放存储空间

    // Element结构体是否相等比较函数，结构体改变时需同步变更
    friend bool operator==(const Element& elem1, const Element& elem2);

    void ClearList();   // 清空线性表内所有元素
    bool IsEmpty();   // 判断线性表是否为空
    int GetLength();   // 返回线性表元素长度
    
    status GetElem(int i, Element& elem);    // 获取线性表第i个元素
    int LocateElem(const Element& elem);   // 查找与elem相同的元素，返回元素下标
    status PriorElem(const Element& elem, Element& prior_elem);   // 获取当前元素的前驱元素
    status NextElem(Element current_element);   // 获取当前元素的前驱元素
    status ListInsert(int i, const Element& elem); // 在指定位置前插入元素
    status ListDelete(int i); // 删除指定位置元素
};
