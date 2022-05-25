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
    using iterator = valueType*;                                          
    using const_iterator = const valueType*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    CustomVector() : _element(new valueType[0]), _size(), _capacity() {}
    explicit CustomVector(int size);
    CustomVector(int size, int val);
    CustomVector(const CustomVector<valueType>& vect);
    CustomVector(const std::initializer_list<valueType>& vec);

    ~CustomVector() { delete[] _element; }

    CustomVector& operator=(CustomVector&& vect);                      
    CustomVector& operator=(const CustomVector<valueType>& vect);      

    iterator begin();
    const_iterator begin() const;
    const_iterator cbegin() const;

    iterator end();
    const_iterator end() const;
    const_iterator cend() const;

    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator crbegin() const;

    reverse_iterator rend();
    const_reverse_iterator rend() const;
    const_reverse_iterator crend() const;

    int size() const { return _size; }
    size_t max_size() const;
    void resize(int new_size);
    int capacity() const { return _capacity; }
    bool empty() const;
    void reserve(int new_size);
    void shrink_to_fit();

    valueType& operator[](int i) { return _element[i]; }
    valueType& at(int pos);
    valueType& front();
    valueType& back();
    valueType* data();

    void push_back(const valueType& value);
    void pop_back();

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

template <class valueType>
CustomVector<valueType>& CustomVector<valueType>::operator=(CustomVector&& vec)
{
    if (&vec == this)
        return *this;
    _element = vec._element;
    _size = vec._size;
    _capacity = vec._capacity;
    vec._element = nullptr;
    vec._size = 0;
    vec._capacity = 0;
    return *this;
}

template <class valueType>
CustomVector<valueType>& CustomVector<valueType>::operator=(const CustomVector<valueType>& vec)
{
    if (&vec == this)
        return *this;
    valueType* newCont = new valueType[vec._size];
    for (int i = 0; i != vec._size; ++i)
        newCont[i] = vec._element[i];
    delete[] _element;
    _element = newCont;
    _size = vec._size;
    _capacity = vec._capacity;
    return *this;
}

template<class valueType>
typename CustomVector<valueType>::iterator CustomVector<valueType>::begin()
{
    return _element;
}

template<class valueType>
typename CustomVector<valueType>::const_iterator CustomVector<valueType>::begin() const
{
    return _element;
}

template<class valueType>
typename CustomVector<valueType>::const_iterator CustomVector<valueType>::cbegin() const
{
    return _element;
}

template<class valueType>
typename CustomVector<valueType>::iterator CustomVector<valueType>::end()
{
    return _element + _size;
}

template<class valueType>
typename CustomVector<valueType>::const_iterator CustomVector<valueType>::end() const
{
    return _element + _size;
}

template<class valueType>
typename CustomVector<valueType>::const_iterator CustomVector<valueType>::cend() const
{
    return end();
}

template<class valueType>
typename CustomVector<valueType>::reverse_iterator CustomVector<valueType>::rbegin()
{
    return _element + _size;
}

template<class valueType>
typename CustomVector<valueType>::const_reverse_iterator CustomVector<valueType>::rbegin() const
{
    return _element + _size;
}

template<class valueType>
typename CustomVector<valueType>::const_reverse_iterator CustomVector<valueType>::crbegin() const
{
    return rbegin();
}

template<class valueType>
typename CustomVector<valueType>::reverse_iterator CustomVector<valueType>::rend()
{
    return _element;
}

template<class valueType>
typename CustomVector<valueType>::const_reverse_iterator CustomVector<valueType>::rend() const
{
    return _element;
}

template<class valueType>
typename CustomVector<valueType>::const_reverse_iterator CustomVector<valueType>::crend() const
{
    return rbegin();
}

template <class valueType>
size_t CustomVector<valueType>::max_size() const
{
    return std::numeric_limits<size_type>::max();
}

template<class valueType>
void CustomVector<valueType>::resize(int new_size)
{
    if (new_size < 0)
        throw std::exception();
    if (new_size < _size)
        _size = new_size;
    if (new_size > _capacity)
    {
        valueType* temp = new valueType[new_size];

        for (int i = 0; i < _size; i++)
            temp[i] = _element[i];

        delete[] _element;
        _element = temp;
        _capacity = new_size;
    }
}

template <class valueType>
bool CustomVector<valueType>::empty() const
{
    return (_size == 0);
}

template<class valueType>
void CustomVector<valueType>::reserve(int amt)
{
    if (_capacity < amt)
        resize(amt);
}

template<class valueType>
void CustomVector<valueType>::shrink_to_fit()
{
    valueType* temp = new valueType[_size];

    for (int i = 0; i < _size; i++)
        temp[i] = _element[i];

    delete[] _element;
    _element = temp;
    _capacity = _size;
}

template <class valueType>
valueType& CustomVector<valueType>::at(int pos)
{
    if (pos >= _size)
        throw std::out_of_range("Index was out of range.");
    return _element[pos];
}

template <class valueType>
valueType& CustomVector<valueType>::front()
{
    return _element[0];
}

template <class valueType>
valueType& CustomVector<valueType>::back()
{
    return _element[_size - 1];
}

template <class valueType>
valueType* CustomVector<valueType>::data()
{
    return _element;
}

template<class valueType>
void CustomVector<valueType>::push_back(const valueType& value)
{
    if (_size == _capacity)
        reserve(2 * _capacity + 1);
    _element[_size++] = value;
}

template<class valueType>
void CustomVector<valueType>::pop_back()
{
    if (_size > 0)
        _size--;
}
