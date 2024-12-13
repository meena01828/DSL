def selection_sort(marks):
    for i in range(len(marks)):
        min_idx = i
        for j in range(i + 1, len(marks)):
            if marks[min_idx] > marks[j]:
                min_idx = j

        marks[i], marks[min_idx] = marks[min_idx], marks[i]

    print("Marks of students after performing Selection Sort on the list:")
    for mark in marks:
        print(mark)


def bubble_sort(marks):
    n = len(marks)
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if marks[j] > marks[j + 1]:
                marks[j], marks[j + 1] = marks[j + 1], marks[j]

    print("Marks of students after performing Bubble Sort on the list:")
    for mark in marks:
        print(mark)


def top_five_marks(marks):
    print("Top marks are:")
    print(*marks[::-1], sep="\n")


marks = []
n = int(input("Enter number of students whose marks are to be displayed: "))
print(f"Enter marks for {n} students (Press ENTER after every student's marks):")
for _ in range(n):
    ele = int(input())
    marks.append(ele)  # adding the element

print(f"The marks of {n} students are:")
print(marks)

while True:
    print("\n---------------MENU---------------")
    print("1. Selection Sort of the marks")
    print("2. Bubble Sort of the marks")
    print("3. Exit")
    ch = int(input("\nEnter your choice (from 1 to 3): "))

    if ch == 1:
        selection_sort(marks)
        a = input("\nDo you want to display top marks from the list (yes/no): ").strip().lower()
        if a == 'yes':
            top_five_marks(marks)
    elif ch == 2:
        bubble_sort(marks)
        a = input("\nDo you want to display top marks from the list (yes/no): ").strip().lower()
        if a == 'yes':
            top_five_marks(marks)
    elif ch == 3:
        print("\nThanks for using this program!")
        break
    else:
        print("\nInvalid choice. Please try again.")
