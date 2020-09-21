class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        heap = []
        for x in arr:
            if (len(heap) < k):
                heapq.heappush(heap, -x)
            else:
                if (len(heap) > 0 and -heap[0] > x):
                    heapq.heappop(heap)
                    heapq.heappush(heap, -x)
        return [-x for x in heap]
