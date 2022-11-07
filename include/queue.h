#include "stdvector.hpp"
template <typename T> class queue: public stdvector<T>{
private:
    int head=0,tail=0;
public:
    queue(int n=100000): stdvector<T>(n){
        this->size=0;
    }
    void resize(int n_size)=delete;
    
    void set_cap(int n_cap)=delete;
    
    T& operator [](int i)=delete;
    
    void insert(int i,T val)=delete;
    
    bool empty() {return (this->size==0);}
    
    
    T front(){
        if (this->empty()) throw std::out_of_range("queue is empty");
        return this->data[this->head];
    }
    void push(T a){
        if (this->size==this->capacity) throw std::out_of_range("queue owerflow");
        this->data[this->tail]=a;
        this->tail=(this->tail+1)%this->capacity;
        this->size++;
    }
    void pop(){
        if (this->empty()) throw std::out_of_range("queue is empty");
        this->head=(this->head+1)%this->capacity;
        this->size--;
    }
};
