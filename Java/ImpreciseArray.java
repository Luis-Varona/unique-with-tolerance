// Imports
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;


// Class
public class ImpreciseArray {
    // Fields
    private double[] arr;
    private int arrSize;
    private int[] permSorted;
    private double[] arrSorted;
    
    
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
        double[] arr = this.arr;
        List<Integer> permSorted = IntStream.range(
            0, this.arrSize
        ).boxed().collect(Collectors.toList());
        
        Comparator<Integer> sortingComparator = new Comparator<Integer>() {
            @Override
            public int compare(Integer i, Integer j) {
                return Double.compare(arr[i], arr[j]);
            }
        };
        
        permSorted.sort(sortingComparator);
        return permSorted.stream().mapToInt(k -> k).toArray();
    }
    
    private double[] setArrSorted() {
        double[] arrSorted = new double[this.arrSize];
        
        for (int i = 0; i < this.arrSize; i++) {
            arrSorted[i] = this.arr[permSorted[i]];
        }
        
        return arrSorted;
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
        if (occurrence != "highest" && occurrence != "lowest") {
            throw new IllegalArgumentException(
                "`occurrence` must be either 'highest' or 'lowest'"
            );
        }
        
        if (this.arrSize == 0) {
            double[] arrUnique = new double[0];
            int[] indicesUnique = new int[0];
            int[] inverseUnique = new int[0];
            int[] countsUnique = new int[0];
            
            return new UniqueTolArray(
                arrUnique,
                indicesUnique,
                inverseUnique,
                countsUnique
            );
        }
        else {
            setIndicesUnique(atol, rtol);
            setCountsUnique();
            setInverseUnique();
            
            if (occurrence == "highest") {
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
        List<Integer> indicesUnique = new ArrayList<Integer>();
        indicesUnique.add(0);
        
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
                indicesUnique.add(i);
            }
        }
        
        this.indicesUnique = indicesUnique.stream().mapToInt(k -> k).toArray();
        this.numUnique = this.indicesUnique.length;
    }
    
    
    private void setCountsUnique() {
        int[] countsUnique = new int[this.numUnique];
        int[] flags = Arrays.copyOf(this.indicesUnique, this.numUnique + 1);
        flags[this.numUnique] = this.arrSize;
        
        for (int i = 0; i < this.numUnique; i++) {
            countsUnique[i] = flags[i + 1] - flags[i];
        }
        
        this.countsUnique = countsUnique;
    }
    
    
    private void setInverseUnique() {
        int[] inverseUnique = new int[this.arrSize];
        
        for (int i = 0; i < this.numUnique; i++) {
            for (int j = 0; j < this.countsUnique[i]; j++) {
                inverseUnique[permSorted[indicesUnique[i] + j]] = i;
            }
        }
        
        this.inverseUnique = inverseUnique;
    }
    
    
    private void useHighestOccurrences() {
        System.arraycopy(
            this.indicesUnique,
            1,
            this.indicesUnique,
            0,
            this.numUnique - 1
        );
        
        for (int i = 0; i < this.numUnique - 1; i++) {
            this.indicesUnique[i] -= 1;
        }
        
        this.indicesUnique[this.numUnique - 1] = this.arrSize - 1;
    }
    
    
    private void permuteIndicesUnique() {
        int[] indicesUniqueTemp = new int[this.numUnique];
        
        for (int i = 0; i < this.numUnique; i++) {
            indicesUniqueTemp[i] = permSorted[indicesUnique[i]];
        }
        
        this.indicesUnique = indicesUniqueTemp;
    }
    
    
    private double[] getArrUnique() {
        double[] arrUnique = new double[this.numUnique];
        
        for (int i = 0; i < this.numUnique; i++) {
            arrUnique[i] = this.arr[this.indicesUnique[i]];
        }
        
        return arrUnique;
    }
}