def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def partition(arr, low, high):
    pivot = arr[low]
    i = low + 1

    for j in range(low + 1, high + 1):
        if arr[j] <= pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1

    arr[low], arr[i - 1] = arr[i - 1], arr[low]
    return i - 1

# Directly executing the code
n = int(input("Enter the number of students: "))
percentages = [float(input(f"Enter percentage of student {i + 1}: ")) for i in range(n)]

quick_sort(percentages, 0, len(percentages) - 1)

print("Top Five Scores are...")
for i in range(n - 1, n - 6, -1):
    print(percentages[i])
