// Imports
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;


// Class
public class ImpreciseArray {
    // Fields
    private final double[] arr;
    private final int arrSize;
    private final int[] permSorted;
    private final double[] arrSorted;
    
    
    // Constructor
    public ImpreciseArray(double[] arr) {
        this.arr = arr;
        this.arrSize = arr.length;
        this.permSorted = setPermSorted();
        this.arrSorted = setArrSorted();
    }
    
    
    // Getter
    public double[] getArr() {
        return this.arr;
    }
    
    
    // Field initialization methods
    private int[] setPermSorted() {
        double[] arrLocal = this.arr;
        
        List<Integer> permSortedLocal = IntStream.range(
            0, this.arrSize
        ).boxed().collect(Collectors.toList());
        
        permSortedLocal.sort((i, j) -> {
            return Double.compare(arrLocal[i], arrLocal[j]);
        });
        
        return permSortedLocal.stream().mapToInt(k -> k).toArray();
    }
    
    private double[] setArrSorted() {
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
        
        if (this.arrSize == 0) {
            return new UniqueTolArray(
                new double[0],
                new int[0],
                new int[0],
                new int[0]
            );
        }
        else {
            setIndicesUnique(atol, rtol);
            setCountsUnique();
            setInverseUnique();
            
            if ("highest".equals(occurrence)) {
                useHighestOccurrences();
            }
            
            permuteIndicesUnique();
            double[] arrUnique = getArrUnique();
            
            return new UniqueTolArray(
                arrUnique,
                this.indicesUnique,
                this.inverseUnique,
                this.countsUnique
            );
        }
    }
    
    
    // Fields for internal use
    private int numUnique;
    private int[] indicesUnique;
    private int[] inverseUnique;
    private int[] countsUnique;
    
    
    // Private methods
    private void setIndicesUnique(double atol, double rtol) {
        List<Integer> indicesUniqueLocal = new ArrayList<>();
        indicesUniqueLocal.add(0);
        
        int i = 0;
        int j = 1;
        
        while (j < this.arrSize) {
            double c = this.arrSorted[i];
            Boolean isClose = true;
            
            while (isClose && j < this.arrSize) {
                isClose = new ImprecisePair(
                    c,
                    this.arrSorted[j],
                    atol,
                    rtol
                ).isClose();
                j++;
            }
            
            i = j - 1;
            if (!isClose) {
                indicesUniqueLocal.add(i);
            }
        }
        
        this.indicesUnique = indicesUniqueLocal.stream().mapToInt(k -> k).toArray();
        this.numUnique = this.indicesUnique.length;
    }
    
    
    private void setCountsUnique() {
        int[] countsUniqueLocal = new int[this.numUnique];
        countsUniqueLocal[this.numUnique - 1] = this.arrSize 
                                         - this.indicesUnique[this.numUnique - 1];
        
        for (int i = 0; i < this.numUnique - 1; i++) {
            countsUniqueLocal[i] = this.indicesUnique[i + 1] - this.indicesUnique[i];
        }
        
        this.countsUnique = countsUniqueLocal;
    }
    
    
    private void setInverseUnique() {
        int[] inverseUniqueLocal = new int[this.arrSize];
        
        for (int i = 0; i < this.numUnique; i++) {
            for (int j = 0; j < this.countsUnique[i]; j++) {
                inverseUniqueLocal[permSorted[this.indicesUnique[i] + j]] = i;
            }
        }
        
        this.inverseUnique = inverseUniqueLocal;
    }
    
    
    private void useHighestOccurrences() {
        for (int i = 0; i < this.numUnique - 1; i++) {
            this.indicesUnique[i] = this.indicesUnique[i + 1];
        }
        
        this.indicesUnique[this.numUnique - 1] = this.arrSize - 1;
    }
    
    
    private void permuteIndicesUnique() {
        for (int i = 0; i < this.numUnique; i++) {
            indicesUnique[i] = permSorted[indicesUnique[i]];
        }
    }
    
    
    private double[] getArrUnique() {
        double[] arrUnique = new double[this.numUnique];
        
        for (int i = 0; i < this.numUnique; i++) {
            arrUnique[i] = this.arr[this.indicesUnique[i]];
        }
        
        return arrUnique;
    }
}