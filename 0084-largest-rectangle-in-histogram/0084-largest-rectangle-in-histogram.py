class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack=[]
        area=0
        heights.append(0)
        i=0
        while  i<len(heights):
            if not stack or heights[i]>=heights[stack[-1]]:
                stack.append(i)
                i+=1
            else:
                top=stack.pop()
                width=i if not stack else i-stack[-1]-1
                area=max(area,heights[top]*width)
        return area