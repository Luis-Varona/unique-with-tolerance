import java.util.Arrays;

public class UniqueTolArray {
    public final double[] arr;
    public final int[] indicesUnique;
    public final int[] inverseUnique;
    public final int[] countsUnique;
    
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
    
    @Override
    public String toString() {
        return Arrays.toString(this.arr) + "\n\n" +
            Arrays.toString(this.indicesUnique) + "\n\n" +
            Arrays.toString(this.inverseUnique) + "\n\n" +
            Arrays.toString(this.countsUnique);
    }
}