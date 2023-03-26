public class test {
    public static void main(String[] args) {
        int N = 1000;
        // printN(N);
        printN2(N);
        
    }
    public static void printN(int N){
        for(int i=1;i<=N;i++){
            System.out.println(i+"\n");
        }
        return;
    }   
    public static void printN2(int N){
        if(N!=0){
            printN2(N-1);
            System.out.println(N+"\n");
        }
        return;
    }  
}
