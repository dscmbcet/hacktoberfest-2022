import java.util.Scanner;

class Palindrome {
    void isPalindrome(String str) {
        String strL = str.toLowerCase();
        int i = 0, j = str.length() - 1;

        System.out.println();

        while(i < j) {
            if(strL.charAt(i) != strL.charAt(j)) {
                System.out.println(str + " is not a palindrome");
                return;
            }

            i++;
            j--;
        }

        System.out.println(str + " is a palindrome");
    }
}

class PalindromeMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string: ");
        String str = sc.nextLine();

        Palindrome p = new Palindrome();

        p.isPalindrome(str);

        sc.close();
    }
}
