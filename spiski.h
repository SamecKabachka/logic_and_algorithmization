#include <iostream>

using namespace std;

typedef struct spisok
{
    int num, preoriti;
    spisok* next, * back;
}sip;

class Spisochek
{ 
protected:
    spisok* start, * end;

public:
    virtual void add(int) = 0;
    virtual void print() = 0;

    virtual void pop() = 0;
   
};

class Queue : public Spisochek{

public:
    Queue(){start = NULL; end = NULL;};
    void add(int num) override;
public: void print() override;
    
    void pop() override;
};

class PQueue : public Queue
{
public: void add (int num, int prioriti);
};

class Stack : public Queue
{
public:
    void pop();
};
