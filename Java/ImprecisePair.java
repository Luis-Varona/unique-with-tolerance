public class ImprecisePair {
    private double x;
    private double y;
    private double atol;
    private double rtol;
    
    public ImprecisePair(double x, double y, double atol, double rtol) {
        this.x = x;
        this.y = y;
        this.atol = atol;
        this.rtol = rtol;
    }
    
    public Boolean isClose() {
        return Math.abs(this.x - this.y) <= Math.max(
            atol, rtol * Math.max(Math.abs(this.x), Math.abs(this.y))
        );
    }
}
