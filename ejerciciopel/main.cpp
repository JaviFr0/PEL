#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::vector; using std::cin;

class MyClass {
private:
    int* data;

public:
    explicit MyClass(int d) {
        data = new int;
        *data = d;
        cout << "Constructor 1 is called" << endl;
    };

    MyClass(const MyClass& source): MyClass(*source.data) {
        cout << "Copy Constructor is called " << endl;
    }

    MyClass(MyClass&& source) noexcept : data(source.data) {
        source.data = nullptr;
        cout << "Move Constructor is called" << endl;
    }

    int getData() const {
        return *data;
    }

    ~MyClass() {
        delete data;
        cout << "Destructor is called" << endl;
    }

};

void printVec(const vector<MyClass> &vec) {

    for (const auto & i : vec) {
        cout << i.getData() << " ";
    }
    cout << endl;
}

int main() {
    vector<MyClass> vec;

    vec.push_back(MyClass(10));
    vec.push_back(MyClass(11));
    printVec(vec);
    cout << "------------------" << endl;

    return EXIT_SUCCESS;
}