public class Main{

    static void bubble_sort(int [] data) {
        int i,j;
        for(i=0; i < data.length; i++) {
            for(j = data.length-1; j > i; j--) {
                if(data[j] < data[j-1]) {
                    int tmp = data[j];
                    data[j] = data[j-1];
                    data[j-1] = tmp;
                } 
            } 
        } 
    }

    static void bubble_sort_opt(int [] data) {
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
                 
        System.out.println("Array Before bubble Sort");  
        for(int i=0; i < arr.length; i++){  
            System.out.print(arr[i] + " ");  
        }  
        System.out.println();  
                  
        bubble_sort_opt(arr);//sorting array elements using bubble sort  
                 
        System.out.println("Array After bubble Sort");  
        for(int i=0; i < arr.length; i++){  
            System.out.print(arr[i] + " ");  
        }  
        System.out.print("\n");
    }
}
