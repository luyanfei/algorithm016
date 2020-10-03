class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
            public int compare(Integer t1, Integer t2) {
                return t2 - t1;
            }
        });
        for (int i = 0; i < arr.length; i++) {
            if (pq.size() < k) {
                pq.offer(arr[i]);
            } else if (pq.size() > 0 && pq.size() == k && pq.peek() > arr[i]) {
                pq.poll();
                pq.offer(arr[i]);
            }
        }
        int i = 0;
        int[] result = new int[k];
        while (pq.size() > 0) {
            result[i++] = pq.peek();
            pq.poll();
        }
        return result;
    }
}
