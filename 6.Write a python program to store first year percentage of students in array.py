"""
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: Write a python program to store first year percentage of students in array. 
Write function for sorting array of floating-point numbers in ascending order using quick sort 
and display top five scores.
"""

# Function to perform quick sort
def quicksort(arr):
    if len(arr) <= 1:  # Base case: a list with one or zero elements is already sorted
        return arr
    else:
        pivot = arr[0]  # Choosing the first element as the pivot
        left = [x for x in arr[1:] if x < pivot]  # Elements less than pivot
        middle = [x for x in arr if x == pivot]  # Elements equal to pivot
        right = [x for x in arr[1:] if x >= pivot]  # Elements greater than pivot
        return quicksort(left) + middle + quicksort(right)  # Recursively sort the left and right parts

# Main program
if __name__ == "__main__":
    m = int(input("Enter the number of students: "))
    percentage = []

    for i in range(m):
        n = float(input(f"Enter the percentage of student {i + 1}: "))
        percentage.append(n)

    # Sorting the percentages using quicksort
    sorted_percentage = quicksort(percentage)

    # Display sorted percentages in ascending order
    print("Percentages in ascending order:")
    print(sorted_percentage)

    # Display top five percentages in ascending order
    top_five_per = sorted_percentage[-5:]
    print("Top five percentages in ascending order:", top_five_per)

    # Display top five percentages in descending order
    top_five_per.reverse()  # Reverse the list to get descending order
    print("Top five percentages in descending order:", top_five_per)
