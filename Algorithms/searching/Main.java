public class Main{

	static boolean linear_searching(int [] data, int key) {
		int i;
		for(i=0;i<data.length;i++){
			if(data[i]==key)break;
		}
		return i!=data.length;
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

		int key = 45; //key to be searched
		System.out.println("Searching for key: "+key);
		System.out.println("Search result using linear search : " + linear_searching(arr,key));//searching array element using linear search

		System.out.print("\n");
	}
}
