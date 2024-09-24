from uniquetol cimport uniquetol

cdef main():
    arr = [1.0, 2.0, 3.0, 4.0]
    n = len(arr)
    result = uniquetol(arr, n)
    print(result.arr_unique)