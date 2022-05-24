#ifndef CustomVector_H
#define CustomVector_H

// -- after comment designates completed sections of code

#include <limits>

template <class valueType>
class CustomVector
{

private:
    valueType* _element; // stores elements
    int _size,           // keeps current size of vector
    int _capacity;       // keep the capacity of the vector

public:
    using size_type = std::size_t;
    using value_type = valueType;
    using iterator = valueType*;
    using const_iterator = const valueType*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

};


#endif