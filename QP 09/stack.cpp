#include "Stack.h"

template <typename T>
Stack<T>::Stack() {
    size_ = 0; 
    top_ = nullptr;
}

template <typename T> 
Stack<T>::~Stack() {
    while (top_ != nullptr) {
        node<T>* prox_apagar = top_->next;
        delete top_;
        top_ = prox_apagar;
    }
}

template <typename T>
size_t Stack<T>::size() const{
    return size_;
}

template <typename T>
bool Stack<T>::peek(T& elem) const{
    if (size_ != 0) {
        elem = top_->value;
        return true;
    }
    return false;
}

template <typename T>
bool Stack<T>::pop(T& elem) {
    if (size_ != 0) {
        elem = top_->value;
        size_ --;
        node<T>* prox = top_->next;
        delete top_;
        top_ = prox;
        return true;
    }
    return false;
}

template <typename T>
void Stack<T>::push(const T& elem) {
    node<T>* pre = new node<T>;
    size_ ++;
    pre->next = top_;
    pre->value = elem;
    top_ = pre;
}

int main() {
    return 0;
}