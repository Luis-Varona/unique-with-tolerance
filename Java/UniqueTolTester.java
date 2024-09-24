public class UniqueTolTester {
    public static void main(String[] args) {
        ImpreciseArray arr = ConstTestArray.arr;
        
        UniqueTolArray arrUnique = arr.uniqueTol(
            1e-8,
            Math.sqrt(Math.ulp(1.0)),
            "highest"
        );
        
        // System.out.println(String.valueOf(Math.sqrt(Math.ulp(1.0))) + "\n");
        System.out.println(String.valueOf(arr.getArr().length));
        System.out.println(String.valueOf(arrUnique.getArr().length) + "\n");
        System.out.println(arrUnique.toString());
    }
}