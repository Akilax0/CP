public class Main{

    static void insertion_sort(int [] data) {
        int i;
        for(i=1; i < data.length; i++) {
            int k = data[i];
            int j = i-1;

            /* Move elements of data[0..i-1] that are greater than key, to one position 
            ahead of the current position*/
            while(j>=0 && data[j]>k){
                data[j+1]=data[j];
                j = j-1;
            }

            data[j+1]=k;
        } 
    }

    static void insertion_sort_opt(int [] data) {
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
                 
        System.out.println("Array Before insertion Sort");  
        for(int i=0; i < arr.length; i++){  
            System.out.print(arr[i] + " ");  
        }  
        System.out.println();  
                  
        insertion_sort(arr);//sorting array elements using insertion sort  
                 
        System.out.println("Array After insertion Sort");  
        for(int i=0; i < arr.length; i++){  
            System.out.print(arr[i] + " ");  
        }  
        System.out.print("\n");
    }
}
