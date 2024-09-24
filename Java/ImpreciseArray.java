// Imports
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;


// Class definition
public class ImpreciseArray {
    // Fields and constructor
    private final double[] arr;
    private final int arrSize;
    private final int[] permSorted;
    private final double[] arrSorted;
    
    public ImpreciseArray(double[] arr) {
        this.arr = arr;
        this.arrSize = arr.length;
        this.permSorted = initializePermSorted();
        this.arrSorted = initializeArrSorted();
    }
    
    
    // Getter and field initialization methods
    public double[] getArr() {
        return this.arr;
    }
    
    private int[] initializePermSorted() {        
        List<Integer> permSortedLocal = IntStream.range(
            0, this.arrSize
        ).boxed().collect(Collectors.toList());
        
        permSortedLocal.sort((i, j) -> {
            return Double.compare(this.arr[i], this.arr[j]);
        });
        
        return permSortedLocal.stream().mapToInt(k -> k).toArray();
    }
    
    private double[] initializeArrSorted() {
        double[] arrSortedLocal = new double[this.arrSize];
        
        for (int i = 0; i < this.arrSize; i++) {
            arrSortedLocal[i] = this.arr[permSorted[i]];
        }
        
        return arrSortedLocal;
    }
    
    
    // `Unique with tolerance` method
    public UniqueTolArray uniqueTol(
        double atol,
        double rtol,
        String occurrence
    ) {
        if (atol < 0) {
            throw new IllegalArgumentException("`atol` must be non-negative");
        }
        if (rtol < 0) {
            throw new IllegalArgumentException("`rtol` must be non-negative");
        }
        if (!"highest".equals(occurrence) && !"lowest".equals(occurrence)) {
            throw new IllegalArgumentException(
                "`occurrence` must be either 'highest' or 'lowest'"
            );
        }
        
        UniqueTolArray out;
        
        if (this.arrSize == 0) {
            out = new UniqueTolArray(
                new double[0],
                new int[0],
                new int[0],
                new int[0]
            );
        }
        else {
            setIndicesUnique(atol, rtol);
            setCountsAndInverseUnique();
            setArrUniqueAndPermuteIndices(occurrence);
            
            out = new UniqueTolArray(
                this.arrUnique,
                this.indicesUnique,
                this.inverseUnique,
                this.countsUnique
            );
        }
        
        return out;
    }
    
    
    // Fields for internal use
    private double[] arrUnique;
    private int numUnique;
    private int[] indicesUnique;
    private int[] inverseUnique;
    private int[] countsUnique;
    
    
    // Private helper methods for `uniqueTol`
    private void setIndicesUnique(double atol, double rtol) {
        List<Integer> indicesUniqueLocal = new ArrayList<>();
        indicesUniqueLocal.add(0);
        double c = this.arrSorted[0];
        
        for (int i = 1; i < this.arrSize; i++) {
            if (
                Math.abs(c - this.arrSorted[i]) > Math.max(
                    atol, rtol * Math.max(Math.abs(c), Math.abs(this.arrSorted[i]))
                )
            ) {
                c = this.arrSorted[i];
                indicesUniqueLocal.add(i);
            }
        }
        
        this.indicesUnique = indicesUniqueLocal.stream().mapToInt(k -> k).toArray();
        this.numUnique = this.indicesUnique.length;
    }
    
    private void setCountsAndInverseUnique() {
        int[] inverseUniqueLocal = new int[this.arrSize];
        int[] countsUniqueLocal = new int[this.numUnique];
        int indexLast = this.indicesUnique[this.numUnique - 1];
        int countLast = this.arrSize - indexLast;
        countsUniqueLocal[this.numUnique - 1] = countLast;
        
        for (int j = 0; j < countLast; j++) {
            inverseUniqueLocal[permSorted[indexLast + j]] = this.numUnique - 1;
        }
        
        for (int i = 0; i < this.numUnique - 1; i++) {
            int index = this.indicesUnique[i];
            int count = this.indicesUnique[i + 1] - index;
            countsUniqueLocal[i] = count;
            
            for (int j = 0; j < count; j++) {
                inverseUniqueLocal[permSorted[index + j]] = i;
            }
        }
        
        this.inverseUnique = inverseUniqueLocal;
        this.countsUnique = countsUniqueLocal;
    }
    
    private void setArrUniqueAndPermuteIndices(String occurrence) {
        double[] arrUniqueLocal = new double[this.numUnique];
        
        if ("highest".equals(occurrence)) {
            for (int i = 0; i < this.numUnique - 1; i++) {
                this.indicesUnique[i] = this.indicesUnique[i + 1];
            }
            
            this.indicesUnique[this.numUnique - 1] = this.arrSize - 1;
        }
        
        for (int i = 0; i < this.numUnique; i++) {
            int index = permSorted[indicesUnique[i]];
            this.indicesUnique[i] = index;
        }
        
        this.arrUnique = arrUniqueLocal;
    }
}