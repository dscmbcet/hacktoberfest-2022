import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CharFrequency {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter text: ");
        String str = scanner.nextLine();

        Map<Character, Integer> freqMap = new HashMap<>();
        for (int i = 0; i < str.length(); i++) {
            Character c = str.charAt(i);
            freqMap.merge(c, 1, Integer::sum);
        }
        freqMap.forEach((k, v) -> System.out.println(k + " occurs " + v + " times"));
    }
}
