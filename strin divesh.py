def longestword(s):
    words = s.split()
    longest = max(words, key=len)
    return longest

def char_frequency(s, char):
    return s.count(char)

def is_palindrome(s):
    s = s.replace(" ", "").lower()
    return s == s[::-1]

def substring_index(s, substring):
    return s.find(substring)

def word_occurrences(s):  
    words = s.split()    #list b    
    occurrences = {}   #initilize dect
    for word in words:
        if word in occurrences: 
            occurrences[word] += 1
        else:
            occurrences[word] = 1
    return occurrences

s = "Python is fun and Python is powerful"
char = 'P'
substring = "fun"

print("Word with the longest length:", longestword(s))

print(f"Frequency of character '{char}':", char_frequency(s, char))

print("Is the given string a palindrome?:", is_palindrome(s))

print(f"First appearance of substring '{substring}':", substring_index(s, substring))

# Count occurrences of each word in the given string
print("Word count:", word_occurrences(s))
