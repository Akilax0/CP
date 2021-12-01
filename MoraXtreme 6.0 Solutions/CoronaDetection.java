import java.util.Scanner;

public class CoronaDetection {

    public static void virusDetecter(String patient, String virus) {
        String output = "";
        int i;
        int j;
        boolean hasMatch;
        hasMatch = false;
        int NoOfDiff;

        int p_length = patient.length();
        int v_length = virus.length();

        for (i=0; i<=p_length - v_length;i++)
        {
            NoOfDiff = 0;
            for (j = i; j <= i + v_length - 1; j++)
            {
                if (patient.charAt(j) != virus.charAt(j-i))
                {
                    NoOfDiff++;
                    if (NoOfDiff >= 2)
                        break;
                }
            }
            if (NoOfDiff < 2)
            {
                output = output.concat(i+ " ");
                hasMatch = true;
            }
        }

        if (!hasMatch)
            output = "No Match!";

        System.out.println(output);
        return;
    }

    public static void main(String[] args) {

        Scanner myScanner = new Scanner(System.in);
        int num = myScanner.nextInt();
        myScanner.nextLine();
        for (int i=0;i<num;i++){
            String dataString = myScanner.nextLine();
            String[] stringArr = dataString.split(" ", 2);
            virusDetecter(stringArr[0], stringArr[stringArr.length-1]);
        }
    }
}