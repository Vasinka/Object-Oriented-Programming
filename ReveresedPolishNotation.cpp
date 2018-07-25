#include <iostream>
using namespace std;

template<typename T> class Stack
{

public:

        Stack()
        {

        count = 0;
        last = NULL;

        }



        void Push(T value)
        {

        Node* node = new Node;



        node->value = value;



        if (count == 0)
        {

        node->next = NULL;

        last = node;

        count++;

        }

                else
                    {

                        node->next = last;

                        last = node;

                        count++;

                    }

        }



        T Pop() {

            if (count == 0)
            {

                return (T)0;

            }

                    else
                    {

                        Node* node = last;

                        T popped = node->value;

                        last = node->next;

                        count--;

                        return popped;

                    }

                }



                T Count()
                {

                return count;

                }



private:

                struct Node
                {

                    T value;

                    Node* next;

                };

                Node* last;

                int count;

};



int calculate(char* notation)

{

                Stack<int> stack;

                char temp[] = "";

                bool pushedValue = true;

                int pos = 0;



                for (int i = 0; notation[i] != '\0'; i++) {

                                if (notation[i] >= '0' && notation[i] <= '9') {

                                                if (!pushedValue) {

                                                                stack.Push(stack.Pop() * 10 + (notation[i] - '0'));

                                                }

                                                else {

                                                                stack.Push(notation[i] - '0');

                                                                pushedValue = false;

                                                }

                                }

                                else if (notation[i] == ' ') {

                                                pushedValue = true;

                                }

                                else {

                                                pushedValue = true;



                                                int left, right;

                                                right = stack.Pop();

                                                left = stack.Pop();



                                                switch (notation[i]) {

                                                case '+': stack.Push(right + left);

                                                                break;

                                                case '-': stack.Push(left - right);

                                                                break;

                                                case '*': stack.Push(left * right);

                                                                break;

                                                case '/': stack.Push(left / right);

                                                                break;

                                                default: break;

                                                }

                                }

                }

                return stack.Pop();

}



bool testNotationSolution()

{

                char testString[] = "5 1 2 + 4 * + 3 -";

                return calculate(testString) == 14;

}



int main()
{

         char notation[100];
         cin.getline(notation, 100);


        int result = calculate(notation);

        cout << "Result: " << result << endl;
              
        return 0;
}
