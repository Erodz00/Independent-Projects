import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Timer;
/*
 * Created by Enrique Rodriguez, Contact at erodz2000@gmail.com
 */
public class DrNim {

	public static int marble = 12;

	public static void main(String[] args) throws InterruptedException {
		Scanner scan = new Scanner(System.in);
		System.out.println("Welcome to Dr.Nim!");
		ArrayList<Integer> NimCounter = new ArrayList<Integer>();
		for (int i = 0; i < marble; i++) {
			NimCounter.add(1);
		}
		while (true) {
			System.out.println("Please select a Gamemode\n1) Original\n2) Winnable\n3) Two Player");
			int input = scan.nextInt();
			if (input == 1) {
				System.out.println("Welcome to Original Dr.Nim!\n\nPlease select a number between 1-3.\n");
				while (NimCounter.get(0) != 0) {
					if (NimCounter.size() != 1) {
						System.out.println("There Is " + NimCounter.size() + " Marbles Remaining.");
					} else {
						System.out.println("There Are " + NimCounter.size() + " Marbles Remaining");
					}
					System.out.println(Arrays.toString(NimCounter.toArray()));
					int number = scan.nextInt();
					if (number > 3 || number < 1) {
						System.out.println("You Can Only Remove 3 Marbles At A Time.");
					} else {
						if (number == 1) {
							NimCounter.remove(NimCounter.size() - 1);
							System.out.println("You Have Removed " + number + " Marble\n");
						} else if (number == 2) {
							NimCounter.remove(NimCounter.size() - 1);
							NimCounter.remove(NimCounter.size() - 1);
							System.out.println("You Have Removed " + number + " Marbles\n");
						} else {
							NimCounter.remove(NimCounter.size() - 1);
							NimCounter.remove(NimCounter.size() - 1);
							NimCounter.remove(NimCounter.size() - 1);
							System.out.println("You Have Removed " + number + " Marbles\n");
						}
						Thread.sleep((long) (Math.random() * 2000));
						int cpuAnswer = 4 - number;
						if (cpuAnswer == 1) {
							System.out.println("The Computer Has Removed " + cpuAnswer + " Marble");
							NimCounter.remove(NimCounter.size() - 1);
						} else if (cpuAnswer == 2) {
							System.out.println("The Computer Has Removed " + cpuAnswer + " Marbles");
							NimCounter.remove(NimCounter.size() - 1);
							NimCounter.remove(NimCounter.size() - 1);
						} else {
							System.out.println("The Computer Has Removed " + cpuAnswer + " Marbles");
							NimCounter.remove(NimCounter.size() - 1);
							NimCounter.remove(NimCounter.size() - 1);
							NimCounter.remove(NimCounter.size() - 1);
						}
						if (NimCounter.isEmpty()) {
							System.out.print(
									"And Got The Last Marble!\nThere Are No Marbles Remaining, The Computer Has Won!");
							return;
						}
					}
				}
			} else if (input == 2) {
				System.out.println("Welcome to Winnable Dr.Nim!\n\nPlease select a number between 1-3.\n");
				while (NimCounter.get(0) != 0) {
					if (NimCounter.size() != 1) {
						System.out.println("There Is " + NimCounter.size() + " Marbles Remaining.");
					} else {
						System.out.println("There Are " + NimCounter.size() + " Marbles Remaining");
					}
					System.out.println(Arrays.toString(NimCounter.toArray()));
					int number = scan.nextInt();
					if (number > 3 || number < 1) {
						System.out.println("You Can Only Remove 3 Marbles At A Time.");
					} else {
						if (number == 1) {
							NimCounter.remove(NimCounter.size() - 1);
							System.out.println("You Have Removed " + number + " Marble");
						} else if (number == 2) {
							if (NimCounter.size() < 2) {
								System.out.println("You Have Removed " + NimCounter.size() + " Marble");
								System.out.println(
										"And Got The Last Marble!\nThere Are No Marbles Remaining, You Have Won!");
								return;
							}
							NimCounter.remove(NimCounter.size() - 1);
							NimCounter.remove(NimCounter.size() - 1);
							System.out.println("You Have Removed " + number + " Marbles");
						} else {
							if (NimCounter.size() < 3) {
								System.out.println("You Have Removed " + NimCounter.size() + " Marbles");
								System.out.println(
										"And Got The Last Marble!\nThere Are No Marbles Remaining, You Have Won!");
								return;
							}
							NimCounter.remove(NimCounter.size() - 1);
							NimCounter.remove(NimCounter.size() - 1);
							NimCounter.remove(NimCounter.size() - 1);
							System.out.println("You Have Removed " + number + " Marbles");
						}
						if (NimCounter.isEmpty()) {
							System.out.print("And Got The Last Marble!\nThere Are No Marbles Remaining, You Have Won!");
							return;
						}
						Thread.sleep((long) (Math.random() * 2000));
						int cpuAnswer = (int) (Math.random() * 100);
						if (cpuAnswer < 33) {
							System.out.println("The Computer Has Removed 1 Marble");
							NimCounter.remove(NimCounter.size() - 1);
						} else if (cpuAnswer > 33 && cpuAnswer < 66) {
							System.out.println("The Computer Has Removed 2 Marbles");
							NimCounter.remove(NimCounter.size() - 1);
							NimCounter.remove(NimCounter.size() - 1);
						} else {
							System.out.println("The Computer Has Removed 3 Marbles");
							NimCounter.remove(NimCounter.size() - 1);
							NimCounter.remove(NimCounter.size() - 1);
							NimCounter.remove(NimCounter.size() - 1);
						}
						if (NimCounter.isEmpty()) {
							System.out.print("And Got The Last Marble!\nThere Are No Marbles Remaining!");
							return;
						}
					}
				}
			} else if (input == 3) {
				int turn = 2;
				for (;;) {
					if (turn % 2 == 0) {
						turn++;
						System.out.println("Welcome to Two Player Dr.Nim!\n\nPlayer 1, please select a number between 1-3.\n");
						while (NimCounter.get(0) != 0) {
							if (NimCounter.size() != 1) {
								System.out.println("There Is " + NimCounter.size() + " Marbles Remaining.");
							} else {
								System.out.println("There Are " + NimCounter.size() + " Marbles Remaining");
							}
							System.out.println(Arrays.toString(NimCounter.toArray()));
							int number = scan.nextInt();
							if (number > 3 || number < 1) {
								System.out.println("You Can Only Remove 3 Marbles At A Time.");
							} else {
								if (number == 1) {
									NimCounter.remove(NimCounter.size() - 1);
									System.out.println("You Have Removed " + number + " Marble");
								} else if (number == 2) {
									if (NimCounter.size() < 2) {
										System.out.println("You Have Removed " + NimCounter.size() + " Marble");
										System.out.println(
												"And Got The Last Marble!\nThere Are No Marbles Remaining, Player 1 Has Won!");
										return;
									}
									NimCounter.remove(NimCounter.size() - 1);
									NimCounter.remove(NimCounter.size() - 1);
									System.out.println("You Have Removed " + number + " Marbles");
								} else {
									if (NimCounter.size() < 3) {
										System.out.println("You Have Removed " + NimCounter.size() + " Marbles");
										System.out.println(
												"And Got The Last Marble!\nThere Are No Marbles Remaining, Player 1 Has Won!");
										return;
									}
									NimCounter.remove(NimCounter.size() - 1);
									NimCounter.remove(NimCounter.size() - 1);
									NimCounter.remove(NimCounter.size() - 1);
									System.out.println("You Have Removed " + number + " Marbles");
								}
								if (NimCounter.isEmpty()) {
									System.out.print("And Got The Last Marble!\nThere Are No Marbles Remaining, Player 1 Has Won!");
									return;
								}
								Thread.sleep((long) (Math.random() * 500));
							}
						}
					} else {
						System.out.println("\nPlayer 2, please select a number between 1-3.\n");
						while (NimCounter.get(0) != 0) {
							if (NimCounter.size() != 1) {
								System.out.println("There Is " + NimCounter.size() + " Marbles Remaining.");
							} else {
								System.out.println("There Are " + NimCounter.size() + " Marbles Remaining");
							}
							System.out.println(Arrays.toString(NimCounter.toArray()));
							int number = scan.nextInt();
							if (number > 3 || number < 1) {
								System.out.println("You Can Only Remove 3 Marbles At A Time.");
							} else {
								if (number == 1) {
									NimCounter.remove(NimCounter.size() - 1);
									System.out.println("You Have Removed " + number + " Marble");
								} else if (number == 2) {
									if (NimCounter.size() < 2) {
										System.out.println("You Have Removed " + NimCounter.size() + " Marble");
										System.out.println("And Got The Last Marble!\nThere Are No Marbles Remaining, Player 2 Has Won!");
										return;
									}
									NimCounter.remove(NimCounter.size() - 1);
									NimCounter.remove(NimCounter.size() - 1);
									System.out.println("You Have Removed " + number + " Marbles");
								} else {
									if (NimCounter.size() < 3) {
										System.out.println("You Have Removed " + NimCounter.size() + " Marbles");
										System.out.println("And Got The Last Marble!\nThere Are No Marbles Remaining, Player 2 Has Won!");
										return;
									}
									NimCounter.remove(NimCounter.size() - 1);
									NimCounter.remove(NimCounter.size() - 1);
									NimCounter.remove(NimCounter.size() - 1);
									System.out.println("You Have Removed " + number + " Marbles");
								}
								if (NimCounter.isEmpty()) {
									System.out.print("And Got The Last Marble!\nThere Are No Marbles Remaining, Player 2 Has Won!");
									return;
								}
								Thread.sleep((long) (Math.random() * 500));
							}
						}
						turn--;
					}
				}
			} else {
				System.out.println("Select a valid number.\n");
			}
		}
	}

}
