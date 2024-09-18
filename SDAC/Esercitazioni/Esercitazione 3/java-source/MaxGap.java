public class MaxGap {

    public static int maxGap(int[] array, int start, int end) {
        if(array == null || start < 0 || start > end) {
			throw new RuntimeException("Invalidi array, start o end");
		}
		int size = end - start;

		if(size < 2) {
			return -1;
		}
		if(size == 2) {
			return array[start+1] - array[start];
		}
		int med = start + (size/2);

		int sx = maxGap(array, start, med+1);
		int dx = maxGap(array, med, end);

		return (sx > dx) ? sx : dx;
    }
}
