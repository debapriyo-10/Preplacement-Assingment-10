
from collections import Counter

def sherlockAndAnagrams(s):
    substrings = []
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            substrings.append("".join(sorted(s[i:j])))
    freq = Counter(substrings)
    count = 0
    for val in freq.values():
        count += val * (val - 1) // 2
    return count
