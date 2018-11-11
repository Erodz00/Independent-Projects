import java.util.*;

public class DrStrangeBargain {
	public static void main(String[] args) throws InterruptedException {
		Scanner sc = new Scanner(System.in);
		System.out.println("Pick a positive number:");
		int n = sc.nextInt();
		Random r = new Random();
		System.out.println("Pick a positive number lower than your number and one higher than your number:");
		int low = sc.nextInt();
		int high = sc.nextInt();
		int random_number = r.nextInt(high - low) + low;
		Dr_Strange_Bargain(n, random_number , high);
	}

	public static void Dr_Strange_Bargain(int n, int random_number, int high) throws InterruptedException {
		if(n > high)
			n=0;
		System.out.println("Dr Strange:  Dormammu! I’ve come to bargain.\n");
		Thread.sleep(1000);
		System.out.println("Dormammu: You’ve come to die.\n");
		System.out.println("Dormammu: Your world is now my world, like all worlds.\n");
		Thread.sleep(1000);
		if (n == 0) {
			n = n + 1;
			Dr_Strange_Bargain(n, random_number, high);
		} else if (n == 1) {
			Thread.sleep(1000);
			System.out.println("Dormammu: What is this?\n");
			System.out.println("Dormammu: Illusion? - No, this is real.\n");
			Thread.sleep(2000);
			n = n + 1;
			Dr_Strange_Bargain(n, random_number, high);
		} else if ((n > 1) && (n != random_number)) {
			Thread.sleep(1000);
			System.out.println("Dormammu: You cannot do this forever.\n");
			System.out.println("Dormammu: No! Make it stop. \n");
			System.out.println("Dr Strange: Actually, I can.\n\t This is how things are now.\n\t You and me, trapped in this moment, endlessly.\n");
			Thread.sleep(1000);
			n = n + 1;
			Dr_Strange_Bargain(n, random_number, high);
		} else if (n == random_number) {
			System.out.println("Dr Strange: Take your zealots from the Earth.\n\t\t End your assault on my world.\n\t\t Never come back.");
		}
	}
}
