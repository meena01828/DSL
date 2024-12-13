def get_percentages():
    num_students = int(input("Enter the number of students: "))
    return [float(input(f"Enter the percentage for student {i + 1}: ")) for i in range(num_students)]


def show_percentages(percentages):
    print("Student Percentages:")
    print(*percentages, sep="\n")


def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[0]
    less = [x for x in arr[1:] if x <= pivot]
    greater = [x for x in arr[1:] if x > pivot]
    return quick_sort(less) + [pivot] + quick_sort(greater)


def show_top_five(arr):
    print("Top Five Percentages:")
    print(*sorted(arr, reverse=True)[:5], sep="\n")


if __name__ == "__main__":
    percentages = []

    while True:
        print("\n---------- MENU ----------")
        print("1. Enter percentages")
        print("2. Show percentages")
        print("3. Quick Sort the percentages")
        print("4. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            percentages = get_percentages()

        elif choice == 2:
            if percentages:
                show_percentages(percentages)
            else:
                print("No data to display. Please enter percentages first.")

        elif choice == 3:
            if percentages:
                percentages = quick_sort(percentages)
                print("Percentages after Quick Sort:")
                show_percentages(percentages)
                if input("Do you want to see the top 5 percentages? (yes/no): ").lower() == 'yes':
                    show_top_five(percentages)
            else:
                print("No data to sort. Please enter percentages first.")

        elif choice == 4:
            print("Exiting the program. Thank you!")
            break

        else:
            print("Invalid choice, please try again.")
