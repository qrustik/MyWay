#include <iostream>
#include <string>

template <typename valueType>
struct Mystack
{
    struct Node
    {
        valueType val;
        Node *prev;
        Node(valueType val, Node *last) : val(val)
        {
            prev = last;
        }
    };

    using ptr_type = Node *;

    void push(valueType val)
    {
        last = new Node(val, last);
        ++lenght;
    }

    valueType pop()
    {
        ptr_type tmp;
        tmp = last;
        last = last->prev;
        valueType val = tmp->val;
        delete tmp;
        --lenght;
        return val;
    }

    valueType top()
    {
        return last->val;
    }

    size_t Lenght()
    {
        ptr_type tmp = this->last;
        size_t lenght = 0;
        while (tmp != nullptr)
        {
            tmp = tmp->prev;
            ++lenght;
        }
        return lenght;
    }

    bool empty()
    {
        return this->lenght == 0 ? true : false;
    }

    Mystack<valueType>() : last(nullptr), lenght(0) {}
    ~Mystack<valueType>()
    {
        ptr_type tmp;
        while (this->last != nullptr)
        {
            tmp = this->last;
            this->last = tmp->prev;
            delete tmp;
        }
    }

    valueType operator[](size_t index)
    {
        ptr_type tmp = this->last;
        while (index > 0)
        {
            tmp = tmp->prev;
            --index;
        }
        return tmp->val;
    }

    ptr_type last;
    size_t lenght;
};

int main(int argc, char const *argv[])
{
    Mystack<int> stack{};
    std::cout << "Lenght: " << stack.Lenght() << std::endl;
    stack.push(111);
    stack.push(222);
    stack.push(333);
    stack.push(444);
    std::cout << stack[0] << std::endl;
    std::cout << "Lenght: " << stack.Lenght() << std::endl;
    int val = stack.pop();
    std::cout << val << std::endl;
    std::cout << "Lenght: " << stack.Lenght() << std::endl;
    val = stack.pop();
    std::cout << val << std::endl;
    std::cout << "Lenght: " << stack.Lenght() << std::endl;
    std::cout << "lenght: " << stack.lenght << std::endl;

    Mystack<std::string> stack2{};
    stack2.push("World!");
    stack2.push("Hello");
    for (size_t i = stack2.lenght; i > 0; --i)
    {
        std::cout << stack2.pop() << " ";
    }
    std::cout << "\nStack is empty? " << std::boolalpha << stack2.empty() << std::endl;

    return 0;
}
