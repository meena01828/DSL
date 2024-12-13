def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


def shell_sort(arr):
    gap = len(arr) // 2
    while gap > 0:
        for i in range(gap, len(arr)):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2


def display_top_scores(arr, top_n):
    arr.sort(reverse=True)  # Sort the list in descending order
    print(f"Top {top_n} scores:")
    for score in arr[:top_n]:
        print(score)


if __name__ == "__main__":
    percentages = [78.5, 65.2, 82.1, 70.3, 91.5, 68.9, 75.4, 88.2, 79.1, 83.7]

    print("Original Percentages:")
    print(percentages)

    # Insertion Sort
    insertion_sorted = percentages.copy()
    insertion_sort(insertion_sorted)
    print("\nAfter Insertion Sort:")
    display_top_scores(insertion_sorted, 5)

    # Shell Sort
    shell_sorted = percentages.copy()
    shell_sort(shell_sorted)
    print("\nAfter Shell Sort:")
    display_top_scores(shell_sorted, 5)
