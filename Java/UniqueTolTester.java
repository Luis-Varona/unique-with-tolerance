public class UniqueTolTester {
    public static void main(String[] args) {
        ImpreciseArray arr = ConstTestArray.testarray;
        
        UniqueTolArray arrUnique = arr.uniqueTol(
            1e-8,
            Math.sqrt(Math.ulp(1.0)),
            "highest"
        );
        
        System.out.println(String.valueOf(arr.getArr().length));
        System.out.println(String.valueOf(arrUnique.arr.length) + "\n");
        System.out.println(arrUnique.toString());
    }
}