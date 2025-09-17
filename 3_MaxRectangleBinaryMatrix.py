
def maxHistogramArea(heights):
    stack, max_area = [], 0
    heights.append(0)
    for i, h in enumerate(heights):
        while stack and heights[stack[-1]] > h:
            height = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, height * width)
        stack.append(i)
    heights.pop()
    return max_area

def maxRectangle(matrix):
    if not matrix:
        return 0
    n, m = len(matrix), len(matrix[0])
    heights = [0] * m
    max_area = 0
    for row in matrix:
        for i in range(m):
            heights[i] = heights[i] + 1 if row[i] == 1 else 0
        max_area = max(max_area, maxHistogramArea(heights))
    return max_area
