#ifndef MAZEPROJECT_STACK_H
#define MAZEPROJECT_STACK_H

// class

// stack의 자료구조를 구현하기 위한 class
// 여러 자료형의 데이터를 저장하기 위해 template class 사용
template<typename KeyType>
class Stack
{
private:
    // stack 포인터
    KeyType *stack;
    // stack의 최대 크기
    int MaxSize;
    // stack의 top의 index
    int top;
public:
    // stack 동적할당 및 top 초기화하는 생성자
    Stack(int MaxStackSize);
    // stack이 가득 차 있는 지 판단하는 함수
    bool IsFull();
    // stack이 비어있는 지 판단하는 함수
    bool IsEmpty();
    // stack에 item을 추가하는 함수
    void Push(const KeyType &item);
    // stack에 item을 삭제하는 함수
    KeyType *Pop(KeyType &item);
    // stack 동적할당 해제하는 소멸자
    ~Stack();
};

// template class를 cpp파일에 구현하면 오류 발생

// stack 동적할당 및 top 초기화
template<typename KeyType>
Stack<KeyType>::Stack(int MaxStackSize): MaxSize(MaxStackSize)
{
    // stack 동적할당
    stack = new KeyType[MaxSize];
    // top을 -1로 초기화
    top = -1;
}

// stack이 가득 차 있는 지 판단하는 함수
template<typename KeyType>
bool Stack<KeyType>::IsFull()
{
    if (top == MaxSize - 1)
        return true;
    else
        return false;
}

// stack이 비어있는 지 판단하는 함수
template<typename KeyType>
bool Stack<KeyType>::IsEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

// stack에 item을 추가하는 함수
template<typename KeyType>
void Stack<KeyType>::Push(const KeyType &item)
{
    // stack이 가득 차 있다면 추가하지 않음
    if (IsFull())
        return;
    else
        stack[++top] = item;
}

// stack에 item을 삭제하는 함수
template<typename KeyType>
KeyType *Stack<KeyType>::Pop(KeyType &item)
{
    // stack이 비어 있다면 삭제하지 않음
    if (IsEmpty())
        return 0;
    else
    {
        item = stack[top--];
        return &item;
    }
}

// stack 동적할당 해제하는 소멸자
template<typename KeyType>
Stack<KeyType>::~Stack()
{
    // stack 동적할당 해제
    delete[] stack;
}

#endif //MAZEPROJECT_STACK_H
