
from collections import Counter
import heapq

def topKFrequent(nums, k):
    freq = Counter(nums)
    return [item for item, count in heapq.nlargest(k, freq.items(), key=lambda x: x[1])]
