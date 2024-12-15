def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid  # Return the index if found
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    
    return -1

def fibonacci_search(arr, target):
    fib_m2 = 0  # (m-2)'th Fibonacci number
    fib_m1 = 1  # (m-1)'th Fibonacci number
    fib_m = fib_m2 + fib_m1  # m'th Fibonacci number

    n = len(arr)
    while fib_m < n:
        fib_m2 = fib_m1
        fib_m1 = fib_m
        fib_m = fib_m2 + fib_m1  # Update Fibonacci numbers
   # to the next Fibonacci numbers until fib_m is greater than or equal to n.
    offset = -1  # Eliminated front portion

    while fib_m > 1:
        i = min(offset + fib_m2, n - 1)  # Check if fib_m2 is a valid location

        if arr[i] < target:
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = i  # Move offset to i
        elif arr[i] > target:
            fib_m = fib_m2
            fib_m1 = fib_m1 - fib_m2
            fib_m2 = fib_m - fib_m1  # Move to lower segment
        else:
            return i  # Target found
    
    if fib_m1 and arr[offset + 1] == target:
        return offset + 1  # Check last element
    
    return -1  # Target not found

# Main program
students = [101, 115, 109, 130, 129, 106, 117]
roll_no = int(input("Enter roll number to search: "))



# Binary Search (requires sorted array)
students.sort()  # Sort the array for Binary Search
result = binary_search(students, roll_no)
print("Binary Search:", result)

# Fibonacci Search
result = fibonacci_search(students, roll_no)
print("Fibonacci Search:", result)