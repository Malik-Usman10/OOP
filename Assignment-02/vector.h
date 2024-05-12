#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename D>
class Vector 
{
private:
    D* data_array;
    int max_size;
    int current_size;

    void resize();

public:
    Vector();
    Vector(const Vector& copy);
    Vector(int max_size);
    ~Vector();

    // Class Functions Section
    int size() const;
    int getMaxSize() const;
    void push_back(const D& value);
    void pop_back();
    bool is_empty();
    bool is_full();
    D at(int index); 
    D erase(int index);
    // void swap(D* a, D* b);
    // void swap(Vector<D>& copy);
    void insert(int index, const D& element);
    // void sort();
    void move(int num);
    Vector<D> union_with(const Vector<D>& copy); 
    Vector<D> intersection_with(const Vector<D>& copy);
    Vector<D> unique_elements(); 
    int count(const D& element); 
    bool is_subset(const Vector<D>& copy); 
    bool search(const D& key); 
    
    // Operator Overloading Section
    D& operator[](int index); 
    const D& operator[](int index) const;
    Vector operator+(const Vector& copy) const;
    Vector operator-(const Vector& copy) const;
    // friend ostream& operator<<(ostream& os, const Vector& vec);
    // friend istream& operator>>(istream& is, Vector& vec);
    template<typename U>
    friend ostream& operator<<(ostream& os, const Vector<U>& vec);
    template<typename U>
    friend istream& operator>>(istream& is, Vector<U>& vec);
    bool operator==(const Vector& copy) const;
    bool operator>(const Vector& copy) const;
    bool operator<(const Vector& copy) const;
    Vector& operator=(const Vector& copy);
};

#endif

template<typename D>
Vector<D>::Vector() : data_array(nullptr), max_size(0), current_size(0) {}

template<typename D>
Vector<D>::Vector(const Vector& copy) : max_size(copy.max_size), current_size(copy.current_size) 
{
    data_array = new D[max_size];
    for (int i = 0; i < current_size; ++i) 
    {
        data_array[i] = copy.data_array[i];
    }
}

template<typename D>
Vector<D>::Vector(int max_size) : max_size(max_size), current_size(0) {
    if (max_size <= 0) 
    {
        throw invalid_argument("Max size should be greater than zero");
    }
    data_array = new D[max_size];
}

template<typename D>
Vector<D>::~Vector() 
{
    delete[] data_array;
}


template<typename D>
void Vector<D>::resize() 
{
    if (current_size >= max_size) 
    {
        max_size *= 2;
        D* new_data_array = new D[max_size];
        for (int i = 0; i < current_size; i++) 
        {
            new_data_array[i] = data_array[i];
        }
        delete[] data_array;
        data_array = new_data_array;
    } 
    else if (current_size <= max_size / 4 && max_size > 1) 
    {
        max_size /= 2;
        D* new_data_array = new D[max_size];
        for (int i = 0; i < current_size; ++i) 
        {
            new_data_array[i] = data_array[i];
        }
        delete[] data_array;
        data_array = new_data_array;
    }
}


template<typename D>
int Vector<D>::size() const 
{
    return current_size;
}

template<typename D>
int Vector<D>::getMaxSize() const 
{
    return max_size;
}

template<typename D>
void Vector<D>::push_back(const D& value) 
{
    resize();
    data_array[current_size++] = value;
}

template<typename D>
void Vector<D>::pop_back() 
{
    if (current_size > 0) 
    {
        --current_size;
        resize();
    }
}

template<typename D>
D& Vector<D>::operator[](int index) 
{
    if (index < 0 || index >= current_size) 
    {
        throw out_of_range("Index out of range");
    }
    return data_array[index];
}

template<typename D>
const D& Vector<D>::operator[](int index) const 
{
    if (index < 0 || index >= current_size) 
    {
        throw out_of_range("Index out of range");
    }
    return data_array[index];
}

template<typename D>
bool Vector<D>::is_empty() 
{
    return current_size == 0;
}

template<typename D>
bool Vector<D>::is_full() 
{
    return current_size == max_size;
}

template<typename D>
D Vector<D>::at(int index)
{
    if (index < 0 || index >= current_size)
    {
        throw out_of_range("Index out of range");
    }
    return data_array[index];
}

template<typename D>
D Vector<D>::erase(int index) 
{
    if (index < 0 || index >= current_size) 
    {
        throw out_of_range("Index out of range");
    }
    D removedElement = data_array[index];
    for (int i = index; i < current_size - 1; i++) 
    {
        data_array[i] = data_array[i + 1];
    }
    --current_size;
    resize();
    return removedElement;
}

// template<typename D>
// void Vector<D>::swap(Vector<D>& copy) 
// {
//     swap(data_array, copy.data_array);
//     swap(max_size, copy.max_size);
//     swap(current_size, copy.current_size);
// }

template<typename D>
void Vector<D>::insert(int index, const D& element)
{
    if (index < 0 || index > current_size) 
    {
        throw out_of_range("Index out of range");
    }
    resize();
    for (int i = current_size; i > index; i--) 
    {
        data_array[i] = data_array[i - 1];
    }
    data_array[index] = element;
    ++current_size;
}

// template<typename D>
// void Vector<D>::sort() 
// {
//     for (int i = 0; i < current_size - 1; i++) 
//     {
//         for (int j = 0; j < current_size - i - 1; j++) 
//         {
//             if (data_array[j] > data_array[j + 1]) 
//             {
//                 swap(data_array[j], data_array[j + 1]);
//             }
//         }
//     }
// }

template<typename D>
void Vector<D>::move(int num) 
{
    if (num > 0) 
    {
        for (int i = 0; i < num; i++) 
        {
            D temp = data_array[current_size - 1];
            for (int j = current_size - 1; j > 0; j--) 
            {
                data_array[j] = data_array[j - 1];
            }
            data_array[0] = temp;
        }
    } 
    else if (num < 0) 
    {
        for (int i = 0; i > num; i--) 
        {
            D temp = data_array[0];
            for (int j = 0; j < current_size - 1; j++) 
            {
                data_array[j] = data_array[j + 1];
            }
            data_array[current_size - 1] = temp;
        }
    }
}

template<typename D>
Vector<D> Vector<D>::union_with(const Vector<D>& copy) 
{
    Vector<D> result(max_size + copy.max_size);
    for (int i = 0; i < current_size; i++) 
    {
        result.push_back(data_array[i]);
    }
    for (int i = 0; i < copy.current_size; i++) 
    {
        result.push_back(copy.data_array[i]);
    }
    return result;
}

template<typename D>
Vector<D> Vector<D>::intersection_with(const Vector<D>& copy) 
{
    Vector<D> result(min(max_size, copy.max_size));
    for (int i = 0; i < current_size; i++) 
    {
        for (int j = 0; j < copy.current_size; j++) 
        {
            if (data_array[i] == copy.data_array[j]) 
            {
                result.push_back(data_array[i]);
                break;
            }
        }
    }
    return result;
}

template<typename D>
Vector<D> Vector<D>::unique_elements() 
{
    Vector<D> result(max_size);
    for (int i = 0; i < current_size; i++) 
    {
        bool isUnique = true;
        for (int j = 0; j < result.current_size; ++j) 
        {
            if (data_array[i] == result.data_array[j]) 
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique) 
        {
            result.push_back(data_array[i]);
        }
    }
    return result;
}

template<typename D>
int Vector<D>::count(const D& element) 
{
    int count = 0;
    for (int i = 0; i < current_size; i++) 
    {
        if (data_array[i] == element) 
        {
            count++;
        }
    }
    return count;
}

template<typename D>
bool Vector<D>::is_subset(const Vector<D>& copy) 
{
    for (int i = 0; i < copy.current_size; i++) 
    {
        bool found = false;
        for (int j = 0; j < current_size; j++) 
        {
            if (copy.data_array[i] == data_array[j]) 
            {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

template<typename D>
bool Vector<D>::search(const D& key) 
{
    for (int i = 0; i < current_size; i++) 
    {
        if (data_array[i] == key) 
        {
            return true;
        }
    }
    return false;
}

template<typename D>
Vector<D> Vector<D>::operator+(const Vector<D>& copy) const 
{
    Vector<D> result(current_size + copy.current_size);
    for (int i = 0; i < current_size; i++) 
    {
        result.push_back(data_array[i]);
    }
    for (int i = 0; i < copy.current_size; i++) 
    {
        result.push_back(copy.data_array[i]);
    }
    return result;
}

template<typename D>
Vector<D> Vector<D>::operator-(const Vector<D>& copy) const 
{
    Vector<D> result(current_size);
    for (int i = 0; i < current_size; i++) 
    {
        bool found = false;
        for (int j = 0; j < copy.current_size; j++) 
        {
            if (data_array[i] == copy.data_array[j]) 
            {
                found = true;
                break;
            }
        }
        if (!found) {
            result.push_back(data_array[i]);
        }
    }
    return result;
}

template<typename D>
ostream& operator<<(ostream& os, const Vector<D>& vec) 
{
    for (int i = 0; i < vec.size(); ++i) 
    {
        os << vec[i] << " ";
    }
    return os;
}

template<typename D>
istream& operator>>(istream& is, Vector<D>& vec) 
{
    for (int i = 0; i < vec.size(); i++) 
    {
        is >> vec[i];
    }
    return is;
}

template<typename D>
bool Vector<D>::operator==(const Vector<D>& copy) const 
{
    if (current_size != copy.current_size)
    {
        return false;
    }
    for (int i = 0; i < current_size; i++) 
    {
        if (data_array[i] != copy.data_array[i]) 
        {
            return false;
        }
    }
    return true;
}

template<typename D>
bool Vector<D>::operator>(const Vector<D>& copy) const 
{
    return current_size > copy.current_size;
}

template<typename D>
bool Vector<D>::operator<(const Vector<D>& copy) const 
{
    return current_size < copy.current_size;
}

template<typename D>
Vector<D>& Vector<D>::operator=(const Vector<D>& copy) 
{
    if (this != &copy) 
    {
        delete[] data_array;
        max_size = copy.max_size;
        current_size = copy.current_size;
        data_array = new D[max_size];
        for (int i = 0; i < current_size; i++) 
        {
            data_array[i] = copy.data_array[i];
        }
    }
    return *this;
}

