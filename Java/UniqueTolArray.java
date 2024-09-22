import java.util.Arrays;

public class UniqueTolArray {
    private final double[] arr;
    private final int[] indicesUnique;
    private final int[] inverseUnique;
    private final int[] countsUnique;
    
    public UniqueTolArray(
        double[] arr,
        int[] indicesUnique,
        int[] inverseUnique,
        int[] countsUnique
    ) {
        this.arr = arr;
        this.indicesUnique = indicesUnique;
        this.inverseUnique = inverseUnique;
        this.countsUnique = countsUnique;
    }
    
    public double[] getArr() {
        return this.arr;
    }
    
    public int[] getIndicesUnique() {
        return this.indicesUnique;
    }
    
    public int[] getInverseUnique() {
        return this.inverseUnique;
    }
    
    public int[] getCountsUnique() {
        return this.countsUnique;
    }
    
    @Override
    public String toString() {
        return Arrays.toString(this.arr) + "\n\n" +
            Arrays.toString(this.indicesUnique) + "\n\n" +
            Arrays.toString(this.inverseUnique) + "\n\n" +
            Arrays.toString(this.countsUnique);
    }
}