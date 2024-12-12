"""
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: Write a python program to store second year percentage of students in array. 
Write function for sorting array of floating-point numbers in ascending order using 
a) Insertion sort 
b) Shell Sort and display top five scores.
"""

# Function to perform insertion sort
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

# Function to perform shell sort
def shell_sort(arr):
    n = len(arr)
    gap = n // 2  # Corrected gap calculation
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:  # Corrected condition
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2  # Fixed indentation
    return arr

# Function to display top 5 scores
def display_top_five(arr):
    top_five = sorted(arr, reverse=True)[:5]  # Sort and take top 5 directly
    print("Top 5 scores:")
    for score in top_five:
        print(f"{score:.2f}")  # Format to 2 decimal places for better readability

# Example usage
if __name__ == "__main__":
    m = int(input("Enter total number of students: "))
    percentage = []
    for k in range(m):
        n = float(input(f"Enter the percentage of student {k + 1}: "))
        percentage.append(n)
    
    print("Original percentages:", percentage)
    
    # Sorting using insertion sort
    sorted_per_insertion = insertion_sort(percentage.copy())
    print("\nSorted percentages using insertion sort:")
    display_top_five(sorted_per_insertion)
    
    # Sorting using shell sort
    sorted_per_shell = shell_sort(percentage.copy())
    print("\nSorted percentages using shell sort:")
    display_top_five(sorted_per_shell)
