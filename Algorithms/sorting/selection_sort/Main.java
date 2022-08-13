public class Main{

    static void selection_sort(int [] data) {
        int i,j;
        for(i=0; i < data.length-1; i++) {
            int m = i;
            for(j = i+1; j < data.length; j++) {
                if(data[j]<data[m])m=j;

            } 
            
            int tmp = data[m];
            data[m] = data[i];
            data[i] = tmp;
             
        } 
    }

    static void selection_sort_opt(int [] data) {
        int i,j;
        boolean quit = false;
        for(i=0; i < data.length; i++) {
            quit = true;
            for(j = data.length-1; j > i; j--) {
                if(data[j] < data[j-1]) {
                    int tmp = data[j];
                    data[j] = data[j-1];
                    data[j-1] = tmp;
                    quit = false;
                } 
            } 
        } 
    }

    // method main(): ALWAYS the APPLICATION entry point
    public static void main (String[] args) {
	    System.out.println ("Hello World!");
        int arr[] ={3,60,35,2,45,320,5};  
                 
        System.out.println("Array Before selection Sort");  
        for(int i=0; i < arr.length; i++){  
            System.out.print(arr[i] + " ");  
        }  
        System.out.println();  
                  
        selection_sort(arr);//sorting array elements using selection sort  
                 
        System.out.println("Array After selection Sort");  
        for(int i=0; i < arr.length; i++){  
            System.out.print(arr[i] + " ");  
        }  
        System.out.print("\n");
    }
}
