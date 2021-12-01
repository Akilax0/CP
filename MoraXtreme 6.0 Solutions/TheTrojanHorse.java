import java.io.*;
import java.util.*;

public class TheTrojanHorse {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int noOfSoldiers = input.nextInt();
        int noOfPairs = input.nextInt();

        int[] soldiers = new int[noOfSoldiers];
        HashMap<Integer,Integer> cities = new HashMap<>();

        Arrays.fill(soldiers, -1);

        for(int i = 0; i < noOfPairs; i++)
        {
            int first = input.nextInt();
            int second = input.nextInt();


            soldiers[first] = (soldiers[first] == -1) ? first : soldiers[first];
            soldiers[second] = (soldiers[second] == -1) ? second : soldiers[second];

            int oldResult = soldiers[second];
            soldiers[second] = soldiers[first];

            for(int j = 0; j < noOfSoldiers; j++)
            {
                if(soldiers[j] == oldResult)
                {
                    soldiers[j] = soldiers[first];
                }
            }
        }


        for(int person : soldiers)
        {
            if(cities.get(person) == null)
            {
                cities.put(person, 1);
            }
            else
            {
                cities.put(person, cities.get(person) + 1);
            }
        }


        int[] temp = new int[cities.size()];
        long aloneSoldier = 0;
        int j = 0;
        for(Map.Entry<Integer,Integer> city : cities.entrySet())
        {
            if(city.getKey() == -1)
            {
                aloneSoldier = (long) city.getValue();
                continue;
            }

            temp[j] = city.getValue();
            j++;
        }


        long combinations = 0;

        for(int p = 0; p < temp.length; p++)
        {
            for(int q = p+1; q < temp.length; q++)
            {
                combinations += temp[p] * temp[q];
            }
        }

        if(aloneSoldier != 0)
        {
            combinations += (aloneSoldier * (noOfSoldiers-aloneSoldier)) + (((aloneSoldier-1)*aloneSoldier)/2);
        }

        System.out.println(combinations);
    }
}