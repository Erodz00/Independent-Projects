import java.util.Random;
import java.util.Scanner;

public class Password_Maker {
	private static boolean check;

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Do you want special characters in your password? Yes or No");
		String str = scan.nextLine();
		if (str.toLowerCase().equals("yes"))
			check = true;
		else
			check = false;
		System.out.println("Enter desired length of password:");
		int length = scan.nextInt();
		System.out.println(genepass(length));
		scan.close();
	}

	static char[] genepass(int n) {
		String chars = "";
		if (check)
			chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*_=+-/.?<>)";
		else
			chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
		System.out.print("Your new password is : ");
		Random random = new Random();
		char[] password = new char[n];
		for (int i = 0; i < n; i++) {
			password[i] = chars.charAt(random.nextInt(chars.length()));
		}
		return password;
	}
}