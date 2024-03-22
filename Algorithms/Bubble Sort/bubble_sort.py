def bubble_sort(array):
    """
    Sorts an array of integers in place using the bubble sort algorithm.

    Args:
        array: The array to sort.

    Returns:
        None. The array is sorted in place.
    """
    for i in range(len(array)):
        for j in range(len(array) - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]


if __name__ == "__main__":
    my_array = [64, 34, 25, 12, 22, 11, 90]
    bubble_sort(my_array)
    print(*my_array)
