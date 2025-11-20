#include <iostream>
#include <list>
using namespace std;

class MyIntVector {
private:
    int* data;           // 동적 배열을 가리키는 포인터
    size_t capacity;     // 현재 할당된 배열 크기
    size_t length;       // 실제 저장된 요소 개수

    void resize() {
        cout << "Resize: " << capacity << " -> " << capacity * 2 << endl;

        size_t newcap = capacity*2;
        int* newData = new int[newcap];

        for(size_t i = 0; i < length; i++)
        newData[i] = data[i];
       
        delete[] data;
        data = newData;
        capacity = newcap;
    }

public:

    // 초기 capacity를 2로 설정하고, length는 0으로 초기화하세요.
    MyIntVector() : capacity(2), length(0) {
        data = new int[capacity];
    }

    ~MyIntVector() {
        delete[] data;
    }

    void push_back(const int& value) {
      if(length == capacity)
        resize();

        data[length++]=value;
    }

    // 마지막 항목을 리턴하세요.
    int pop_back() {
        if (length == 0)
            throw out_of_range("Vector is empty");
        return data[--length]; // 마지막 요소 제거
    }

    // 주어진 index의 요소를 반환하세요.
    int& operator[](const int index){
        return data[index];
    }

    // 현재 저장된 요소 개수를 반환하세요.
    size_t size() const {
        return length;
    }

};
void testVector(const string& name, std::list<int> values) {

    cout << "------------------" << endl;
    MyIntVector vec;
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
    testVector("IntVec", {1, 2, 3, 4, 5, 6});
    return 0;
}
