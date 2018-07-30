//TODO: tests
#include<iostream>
#include <assert.h>
using namespace std;

template <typename T>
class StaticStack {
    public:
        StaticStack();
        void Push(const T & Element);
        void Pop();
        T Top() const;

        int GetSize() const;
        bool IsEmpty() const;

    private:
        enum { SIZE = 10 };
        T StackData[SIZE];
        int Used;
};

template<typename T>
StaticStack<T>::StaticStack()
{
	Used = 0;
}

template<typename T>
void StaticStack<T>::Push(const T & Element)
{
	if (Used >= SIZE)
	{
		cout << "Stack already full!" << endl;
		return;
	}

	StackData[Used++] = Element;
}

template<typename T>
void StaticStack<T>::Pop()
{
	assert(Used > 0);

	--Used;
}

template<typename T>
T StaticStack<T>::Top() const
{
	assert(Used > 0);

	return StackData[Used - 1];
}

template<typename T>
int StaticStack<T>::GetSize() const
{
	return Used;
}

template<typename T>
bool StaticStack<T>::IsEmpty() const
{

	return Used == 0;
}

int main()
{
    return 0;
}
