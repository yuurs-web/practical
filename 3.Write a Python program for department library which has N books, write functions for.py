"""
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: Write a Python program for department library which has N books, write functions for 
following: 
a) Delete the duplicate entries 
b) Display books in ascending order based on cost of books 
c) Count number of books with cost more than 500. 
d) Copy books in a new list which has cost less than 500.
"""

def delet(a):
    ans = []  # List to store unique books
    seen = set()  # Set to track unique book IDs
    for item in a:
        if item[0] not in seen:  # Check if the book ID is not seen before
            ans.append(item)
            seen.add(item[0])  # Add the book ID to the seen set
    return ans

def count(a):
    f = 0  # Counter for books with cost more than 500
    less = []  # List for books with cost less than 500
    for i in a:
        if int(i[1]) > 500:  # If cost of book is more than 500
            f += 1
        else:
            less.append(i)  # If cost of book is less than or equal to 500
    return f, less

def sort(a):
    ans = a.copy()  # Create a copy of the list to avoid modifying the original
    for i in range(len(ans)):  # Bubble sort algorithm
        for j in range(0, len(ans) - i - 1):
            if int(ans[j][1]) > int(ans[j + 1][1]):  # Compare the costs of books
                ans[j], ans[j + 1] = ans[j + 1], ans[j]  # Swap books if needed
    return ans

# Main program
n = int(input("Enter the number of books: "))  # Get the number of books
books = []  # List to store book data

# Input details for each book
for i in range(n):
    a = input(f"Enter the ID of book {i + 1}: ")  # Book ID
    b = input(f"Enter the cost of book {i + 1}: ")  # Book cost
    books.append([a, b])  # Store book ID and cost in the list

# Print the original list of books
print("Original list:", books)

# Delete duplicate books
books_no_duplicates = delet(books)
print("After deleting duplicate entries:", books_no_duplicates)

# Sort books based on cost
sorted_books = sort(books_no_duplicates)
print("Books in ascending order based on cost:", sorted_books)

# Count books with cost more than 500 and list those with cost less than 500
tup = count(books_no_duplicates)
print(f"Number of books with cost more than 500: {tup[0]}")
print(f"Books with cost less than 500: {tup[1]}")
