import java.util.Scanner;

public class removeLNSOSU {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while(scan.hasNextLine()) {
			String str = scan.nextLine();
			str = str.replace(":", "");
			str = str.substring(0, str.length() - 4);
			if(str.charAt(str.length()-1) != ',') {
				String[] temp = str.split(",");
				for(int i = 0;i<temp.length-1;i++) {
					if(i==3) {
						System.out.print("1,");
					}else if(i==temp.length-2) {
						System.out.print(temp[i] + ",0:");
					}else {
					System.out.print(temp[i] + ",");
					}
				}
				System.out.println("0:0:0:0:");
			} else {
				System.out.println(str + "0:0:0:0:");
			}
		}		
	}

}
