import java.util.ArrayList;
import java.util.Scanner;
/*
 * Created by Enrique Rodriguez, Contact at erodz2000@gmail.com
 */
public class TextFlipper {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the number of Strings you want to flip:");
		int n = scan.nextInt();
		scan.nextLine();
		ArrayList<String> arr = new ArrayList<String>();
		for (int i = 0; i < n; i++) {
			System.out.println("Enter a String:");
			String str = scan.nextLine();
			StringBuilder sb = new StringBuilder(str);
			for (int j = 1; j < str.length()+1; j++) {
				try {
					arr.add(sb.toString());
					sb.deleteCharAt(0);
					sb.append(str.charAt(str.length() - (j + 1)));
				} catch (Exception e) {
					/*it's free real estate*/
				}
			}
			arr.add("");
		}
		for (int i = 0; i < arr.size(); i++) {
			System.out.println(arr.get(i));
		}
		scan.close();
	}
}
