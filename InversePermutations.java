import java.util.ArrayList;
import java.util.Scanner;

public class InversePermutations {
	public static ArrayList<ArrayList<Integer>> permute(int[] num) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		result.add(new ArrayList<Integer>());
		for (int i = 0; i < num.length; i++) {
			ArrayList<ArrayList<Integer>> current = new ArrayList<ArrayList<Integer>>();
			for (ArrayList<Integer> l : result) {
				for (int j = 0; j < l.size() + 1; j++) {
					l.add(j, num[i]);
					ArrayList<Integer> temp = new ArrayList<Integer>(l);
					current.add(temp);
					l.remove(j);
				}
			}

			result = new ArrayList<ArrayList<Integer>>(current);
		}
		return result;
	}// Helper Method

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("How long is our array?");
		int n = scan.nextInt(), counter = 0, runs = 1;
		int[] arr = new int[n];
		for (int i = n; i > 0; i--) {
			arr[counter] = i;
			counter++;
		}
		ArrayList<ArrayList<Integer>> allPermutes = permute(arr);
		for (ArrayList<Integer> innerLs : allPermutes) {
			int total = 0;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (innerLs.get(i) > innerLs.get(j)) {
						System.out.printf("(%d, %d), ",innerLs.get(i), innerLs.get(j));
						total++;
					}
				}
			}
			System.out.println();
			System.out.printf("%d. There are %d inverse pairs in this current permutation.\n",runs, total);
			runs++;
		}
		scan.close();
	}
}
