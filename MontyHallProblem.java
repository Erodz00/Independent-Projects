import java.util.*;
/*
 * Created by Enrique Rodriguez, Contact at erodz2000@gmail.com
 */
public class MontyHallProblem {
	static int[] winlossratioswitch = { 0, 0 };
	static int[] winlossratiostay = { 0, 0 };

	public static void simulation(int swit) {
		Random gen = new Random();
		int[] doors = { 0, 0, 0 };
		int winner = gen.nextInt(3), choice = gen.nextInt(3), shown = gen.nextInt(3);
		doors[winner] = 1;
		while (shown == choice || doors[shown] == 1) {
			shown = gen.nextInt(3);
		}
		//System.out.println(doors[0] + " " + doors[1] + " " + doors[2] + "\nChoice: " + choice + "\nShown door: " + shown);
		if (swit == 1) {
			if (shown == 2 && choice == 1) {
				choice = 0;
			} else if (shown == 2 && choice == 0) {
				choice = 1;
			} else if (shown == 1 && choice == 2) {
				choice = 0;
			} else if (shown == 1 && choice == 0) {
				choice = 2;
			} else if (shown == 0 && choice == 1) {
				choice = 2;
			} else if (shown == 0 && choice == 2) {
				choice = 1;
			}
			if (doors[winner] == doors[choice]) {
				winlossratioswitch[0]++;
			} else {
				winlossratioswitch[1]++;
			}
		} else {
			if (doors[winner] == doors[choice]) {
				winlossratiostay[0]++;
			} else {
				winlossratiostay[1]++;
			}
		}

	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("How many times do you want to run the simulation?");
		try {
			int runs = scan.nextInt();
			for (int i = 0; i < runs; i++) {
				simulation(1);
			}
			System.out.printf("Won by switching %d times, Loss by switching %d times.\n", winlossratioswitch[0], winlossratioswitch[1]);

			for (int i = 0; i < runs; i++) {
				simulation(0);
			}
			System.out.printf("Won by staying %d times, Loss by staying %d times.\n", winlossratiostay[0], winlossratiostay[1]);
		} catch (Exception e) {
			System.out.println("Input expected an integer value.\nClosing program.");
		}
		scan.close();
	}
}