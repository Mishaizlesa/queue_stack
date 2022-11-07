#include<algorithm>
#include <cmath>
#include <exception>

template<typename T>class stdvector {
protected:
    unsigned int size = 0;
    T* data = nullptr;
    unsigned int capacity=0;
    const int ch_size=2;
public:
    stdvector(int num = 0){
        if (num<0) throw std::out_of_range("negative size");
        size = num;
        capacity = num;
        data= new T[capacity]();
    }
    stdvector(const stdvector<T>& other){
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    };
    void resize(int n_size){
        size = n_size;
        set_cap(n_size+1);
    }
    void set_cap(int n_cap){
        T* n_s = new T[n_cap];
        for (int i = 0; i < std::min(n_cap, int(size)); ++i) {
            n_s[i] = data[i];
        }
        for (int i = size + 1; i < n_cap; ++i) {
            n_s[i] = 0;
        }
        capacity = n_cap;
        delete[] data;
        data = n_s;
         
    }
    stdvector<T>& operator=(const stdvector<T>& v1){
        if (this == &v1) return *this;
        size = v1.size;
        capacity = v1.capacity;
        delete[]data;
        data = new T[v1.capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = v1.data[i];
        }
        return *this;
    }
    unsigned int get_size(){
        return size;
    }
    T& operator [](int i) {return data[i];}
    void push_back(int val){
        if (capacity < size + 1) {
            set_cap((size + 1) * ch_size);
        }
        data[size] = val;
        size++;
    }
    void pop_back(){
        if (size==0) throw std::out_of_range("stack is empty");
        size--;
    }
    void push_front(T val) {inser(0,val);}
    void pop_front(){
        T tmp=data[0];
        erase(0);
    }
    void insert(int id,T val){
        if (capacity < size + 1) {
            set_cap((size + 1) * ch_size);
        }
        T tmp=data[id];
        data[id]=val;
        for (int i=id+1;i<size+1;++i){
            std::swap(data[i], tmp);
        }
        size++;
    }
    void erase(int id){
        for(int i=id;i<size-1;++i){
            std::swap(data[i], data[i+1]);
        }
        size--;
    }
    ~stdvector() {delete[] data;}
};
