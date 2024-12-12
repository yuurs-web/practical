"""
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: In second-year computer engineering class, group A students play cricket, group B 
students play badminton, and group C students play football. Write a Python program using 
functions to compute the following:
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton.
(Note: While realizing the group, duplicate entries should be avoided. Do not use SET built-in functions.)
"""

# Function to calculate union of two lists
def union(a, b):
    ans = a.copy()
    for i in b:
        if i not in a:
            ans.append(i)
    return ans

# Function to calculate difference of two lists (a - b)
def minus(a, b):
    ans = []
    for i in a:
        if i not in b:
            ans.append(i)
    return ans

# Function to calculate intersection of two lists
def intersection(a, b):
    ans = []
    for i in a:
        if i in b:
            ans.append(i)
    return ans

# Input lists
u = input("ENTER THE UNIVERSAL LIST (all students): ").split(",")
b = input("ENTER THE BADMINTON LIST: ").split(",")
c = input("ENTER THE CRICKET LIST: ").split(",")
f = input("ENTER THE FOOTBALL LIST: ").split(",")

# Clean up inputs by removing duplicates and extra spaces
u = list(dict.fromkeys([x.strip() for x in u]))
b = list(dict.fromkeys([x.strip() for x in b]))
c = list(dict.fromkeys([x.strip() for x in c]))
f = list(dict.fromkeys([x.strip() for x in f]))

# a) List of students who play both cricket and badminton
print("List of students who play CRICKET and BADMINTON:", intersection(c, b))

# b) List of students who play either cricket or badminton but not both
print("List of students who play either CRICKET or BADMINTON but not BOTH:", 
      union(minus(c, intersection(c, b)), minus(b, intersection(c, b))))

# c) Number of students who play neither cricket nor badminton
neither = minus(minus(u, c), b)
print("Number of students who play neither CRICKET nor BADMINTON:", len(neither))

# d) Number of students who play cricket and football but not badminton
cricket_football_not_badminton = minus(intersection(c, f), b)
print("Number of students who play CRICKET and FOOTBALL but not BADMINTON:", len(cricket_football_not_badminton))
