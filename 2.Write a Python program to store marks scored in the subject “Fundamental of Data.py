"""
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: Write a Python program to store marks scored in the subject “Fundamental of Data 
Structure” by N students in the class. Write functions to compute the following: 
a) The average score of the class 
b) Highest score and lowest score of the class 
c) Count of students who were absent for the test 
d) Display the mark with the highest frequency 
"""

# Input the number of students
n = int(input("Enter the number of students: "))

# Initialize variables
present, total, min_score, max_score, absent = 0, 0, 51, -1, 0
marks = []

# Loop to input the marks for each student
for i in range(n):
    temp = input(f"Enter the marks of student {i + 1} or AB if absent: ")
    marks.append(temp)
    
    # If the student is present
    if temp != "AB":
        score = int(temp)
        present += 1
        total += score
        
        # Update highest and lowest scores
        if score > max_score:
            max_score = score
        if score < min_score:
            min_score = score
    else:
        absent += 1

# Calculate average score (avoid division by zero)
avg = total / present if present > 0 else 0

# Frequency calculation (only for present students)
frequency = {}
for mark in marks:
    if mark != "AB":  # Only count present students
        mark_int = int(mark)
        if mark_int in frequency:
            frequency[mark_int] += 1
        else:
            frequency[mark_int] = 1

# Find the mark with the highest frequency
max_freq = 0
most_frequent_marks = []
for mark, freq in frequency.items():
    if freq > max_freq:
        max_freq = freq
        most_frequent_marks = [mark]
    elif freq == max_freq:
        most_frequent_marks.append(mark)

# Print the results
print(f"The average score of the class: {avg}")
print(f"Highest and lowest score of the class: {max_score} and {min_score}")
print(f"Students absent for the test: {absent}")
print(f"Marks with the highest frequency ({max_freq}): {most_frequent_marks}")
