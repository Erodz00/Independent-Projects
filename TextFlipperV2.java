import java.util.Scanner;
/*
 * Created by Enrique Rodriguez, Contact at erodz2000@gmail.com
 */
public class TextFlipperV2 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter a String:");
		String str = scan.nextLine();
		reverse(str);
	}

	public static String reverse(String text) {
		StringBuilder builder = new StringBuilder(text);
		System.out.println(text);
		for (int i = text.length() - 2; i >= 0; i--) {
			char c = text.charAt(i);
			builder.deleteCharAt(0);
			builder.append(c);
			System.out.println(builder.toString());
		}
		return builder.toString();
	}
}
