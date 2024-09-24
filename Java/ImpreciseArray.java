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
            setCountsAndInverseUnique();
            
            if ("highest".equals(occurrence)) {
                useHighestOccurrences();
            }
            
            permuteIndicesUnique();
            
            return new UniqueTolArray(
                getArrUnique(),
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
                isClose = Math.abs(c - this.arrSorted[j]) <= Math.max(
                    atol, rtol * Math.max(Math.abs(c), Math.abs(this.arrSorted[j]))
                );
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