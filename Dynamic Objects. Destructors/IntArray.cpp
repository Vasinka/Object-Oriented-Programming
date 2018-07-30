//TODO: add sorting method, binary search; test the methods
#include<iostream>
using namespace std;

const int MAX = 20;

class IntArray
{
    public:
        IntArray(int size)
        {
            if (size < 0 || size > MAX )
            {
                cout << "Invalid size," << endl;
                //exit (1);
            }

            arr = new int [size];

            if(!arr)
            {
                cout << "memory error" << endl;
                //exit (1);
            }

            num = size;

            for (int i = 0; i < size; i++)
            {
                arr[i] = 0;
            }
        }

        ~IntArray()
        {
            delete [] arr;
        }

        IntArray(const IntArray& p)
        {
            arr = new int [p.num];
            if (!arr)
            {
                cout << "memory error" << endl;
               // exit(1);
            }

            for (int i = 0; i < p.num ; i++)
            {
                arr[i] = p.arr[i];
            }

            num = p.num;
        }


        bool setElem(int elem, int value)
        {
            if (isValid(elem))
                {
                    arr[elem] = value;
                    return true;
                }
            return false;
        }

        bool getElem(int elem, int& value)
        {
            if (isValid(elem))
            {
                value = arr[elem];
                return true;
            }

            return false;
        }

    private:
        int* arr; //pointer to the array
        int num; //count of elements
        bool isValid (int elem)
        {
            return elem >=0 && elem < num;
        }
};

int main ()
{
    return 0;
}
