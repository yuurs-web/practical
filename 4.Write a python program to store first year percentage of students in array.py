"""
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: Write a python program to store first year percentage of students in array. 
Write function for sorting array of floating point numbers in ascending order using 
a) Selection Sort 
b) Bubble sort and display top five scores.
"""

def selection_sort(arr):
    """Sort the array using the selection sort algorithm."""
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):  # Fix: 'for' loop was incorrect in the original code
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

def bubble_sort(arr):
    """Sort the array using the bubble sort algorithm."""
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def display_top_five(arr):
    """Display the top five scores."""
    print("Top five scores:")
    for score in sorted(arr, reverse=True)[:5]:  # Sort in descending order and slice the top five
        print(f"{score:.2f}")  # Format the score to two decimal places

# Example percentages
percentages = [75, 82.3, 91, 89.88, 53, 63, 85, 95, 99]

# Sorting using selection sort
stored_percentages_selection = selection_sort(percentages[:])  # Create a copy for sorting
print("Selection Sort:")
display_top_five(stored_percentages_selection)

# Sorting using bubble sort
stored_percentages_bubble = bubble_sort(percentages[:])  # Create a copy for sorting
print("\nBubble Sort:")
display_top_five(stored_percentages_bubble)
