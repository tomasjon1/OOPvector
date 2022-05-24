#pragma once

#include <limits>

template <class valueType>
class CustomVector
{

public:
    valueType* _element; 
    int _size;
    int _capacity;       

public:
    using size_type = std::size_t;
    using value_type = valueType;
    using iterator = valueType*;
    using const_iterator = const valueType*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    CustomVector() : _element(new valueType[0]), _size(), _capacity() {}
    explicit CustomVector(int size);
    CustomVector(int size, int val);
    CustomVector(const CustomVector<valueType>& vect);
    CustomVector(const std::initializer_list<valueType>& vec);

};

template<class valueType>
CustomVector<valueType>::CustomVector(int size) : _size(size), _capacity(size) 
{
    _element = new valueType[size];
}

template<class valueType >
CustomVector<valueType>::CustomVector(int size, int val) : _size(size), _capacity(size) 
{
    _element = new valueType[_size];

    for (int i = 0; i < _size; i++)
        _element[i] = val;
}

template<class valueType>
CustomVector<valueType>::CustomVector(const CustomVector<valueType>& vect) : _size(vect.size()), _capacity(vect.capacity())
{
    _element = new valueType[_capacity];

    for (int i = 0; i < _size; i++)
        _element[i] = vect._element[i];
}

template<class valueType>
CustomVector<valueType>::CustomVector(const std::initializer_list<valueType>& vect) : _size(vect.size()), _capacity(vect.size())
{
    _element = new valueType[vect.size()];

    for (int i = 0; i < vect.size(); i++)
        _element[i] = *(vect.begin() + i);
}

