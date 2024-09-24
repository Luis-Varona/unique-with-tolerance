from cpython import array
from uniquetol cimport uniquetol

cdef main():
    cdef double *arr
    cdef int n
    cdef UniqueTolArray result
    
    arr = array([1.0, 2.0, 3.0, 4.0])
    n = len(arr)
    result = uniquetol(arr, n)
    print(result.arr_unique)

main()