#include <iostream>
#include <string>
#include <list>
using namespace std;

template<typename T>
class MyVector {
private:
    T*data;
    size_t capacity;
    size_t length;

    void resize(){
        size_t oldCap = capacity;
        capacity*=2;
        cout << "Resize: " << oldCap << " -> " << capacity << endl;

        T*newData = new T[capacity];
        for (size_t i=0; i < length; i ++)
            newData[i] = data[i];

        delete[] data;
        data = newData;
    }

    public:
        MyVector(){
            capacity = 2;
            length = 0;
            data = new T[capacity];
    }

    ~MyVector(){
        delete[] data;
    }

    void push_back(const T& value){
        if(length == capacity)
            resize();
        data[length++] = value;
    }

    T pop_back(){
        return data[--length];
    }

    size_t size() const{
        return length;
    }

    T& operator[](size_t index){
        return data[index];
    }

    const T& operator[](size_t index) const{
        return data[index];
    }
};

template<typename T>
void testVector(const string& name, std::list<T> values) {

    cout << "------------------" << endl;
    MyVector<T> vec;
    for (auto& v : values)
        vec.push_back(v);

    cout << name << ": ";
    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";

    cout << endl;
    while(vec.size())
        cout << "Pop: " << vec.pop_back() << "\n";
}

int main() {
    testVector<int>("IntVec", {1, 2, 3, 4, 5, 6});
    testVector<double>("DoubleVec", {1.1, 2.2, 3.3, 4.4, 5.5});
    testVector<char>("CharVec", {'A', 'B', 'C', 'D', 'E', 'F'});
    testVector<string>("StringVec", {"Hello", "World", "C++", "Template", "Vector"});
    return 0;
}
