# Function for Linear Search
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # Return the index if found
    return -1  # Return -1 if not found


# Function for Sentinel Search
def sentinel_search(arr, target):
    n = len(arr)
    last = arr[n-1] 
    arr[n-1] = target
    i = 0
    while arr[i] != target:
        i += 1
    arr[n-1] = last  # Restore the last element
    if i < n - 1 or arr[n-1] == target:
        return i  # Return the index if found
    return -1  # Return -1 if not found

# Main program
students = [101, 115, 109, 130, 129, 106, 117]
roll_no = int(input("Enter roll number to search: "))

# Linear Search
result = linear_search(students, roll_no)
print("Linear Search:", result)

# Sentinel Search
result = sentinel_search(students, roll_no)
print("Sentinel Search:", result)

