
#include <cstddef>


/*
   This class defines an element that is stored
   in the garbage collection information list.
*/
template <typename T>
class PtrDetails
{
    /*
       Here, mPtr points to the allocated memory.
       If this is an array, then arraySize specifies
       the size of the array.
    */

  public:
    // Current reference count.
    std::size_t refcount;
    // Pointer to allocated memory.
    T * const memPtr;
    /* isArray is true if memPtr points
       to an allocated array. It is false
       otherwise. */
    const bool isArray;
    /* If memPtr is pointing to an allocated
       array, then arraySize contains its size. */
    const std::size_t arraySize;
    
    PtrDetails(T *pointer, std::size_t size = 0) : refcount(0), memPtr(pointer),
                                                   isArray(size > 0), arraySize(size) {}
};

// Overloading operator== allows two class objects to be compared.
// This is needed by the STL list class.
template <typename T>
bool operator==(const PtrDetails<T> &obj1,
                const PtrDetails<T> &obj2)
{
    return obj1.memPtr == obj2.memPtr;
}
