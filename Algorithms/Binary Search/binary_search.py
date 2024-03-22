def binary_search(numbers=[], target=0):

    low = 0
    high = len(numbers)

    numbers.sort()

    while high >= low:

        mid = (low + high) // 2

        if numbers[mid] == target:
            return mid

        elif numbers[mid] > target:
            high = mid - 1

        else:
            low = mid + 1

    return -1
