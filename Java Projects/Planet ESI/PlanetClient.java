/*
 * 15 December 2021 
 * This program reads the planetary data file into an array of objects and provides the user 
 * with a menu of options of operations to take on the data, including modifying data, 
 * printing out a table of data, displaying the best-fit planet, etc. 
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class PlanetClient {

	public static void main(String[] args) throws FileNotFoundException {
		PlanetData[] planet = readFile(); //create new array filled from readFile method
		int choice = displayMenu(); 
		if (choice == 1) //condition for choice returned from displayMenu
		{
			showAll(planet); //displays full data 
		} else if (choice == 2)
		{
			changeRadius(planet); //allows user to change chosen planet's radius
		} else if (choice == 3) 
		{
			changeFlux(planet); //allows user to change chosen planet's flux
		} else if (choice == 4)
		{
			showMostSimilar(planet); //finds and displays highest ESI
		} else if (choice == 5)
		{
			showLeastSimilar(planet); //finds and displays lowest ESI
		} else if (choice == 6)
		{
			showAverageSimilarity(planet); //calculates and displays average ESI
		}
	}
	
	//@return The planets data is returned of the array type PlanetData[]
	public static PlanetData[] readFile() throws FileNotFoundException
	{
		PlanetData[] planets = new PlanetData[10]; //create new array of 10 elements
		String fileName = "PlanetData.txt";
		File file = new File(fileName);
		Scanner input = new Scanner(file); 
		int i = 0;
		while (input.hasNext() && i < planets.length) //read through file and fill array
		{
			String name = input.nextLine();
			double radius = input.nextDouble();
			double flux = input.nextDouble();
			double distance = input.nextDouble();
			if (input.hasNext()) input.nextLine();
			planets[i] = new PlanetData(name, radius, flux, distance);
			i++;
		}
		return planets; //return array
	}
	//@return The planet menu choice is returned of the int type
	public static int displayMenu()
	{
		Scanner keyboard = new Scanner(System.in); //displays menu and prompts user for choice
		System.out.print("Planetary Conditions Data Menu\n1. List all planetary data\n"
				+ "2. Change radius\n3. Change flux\n4. Show planet with highest ESI\nShow planet with lowest ESI\n"
				+ "6. Show average ESI of planets in the data file\n7. Quit");
		System.out.print("\nYour choice: ");
		int choice = keyboard.nextInt();
		while (choice < 1 || choice > 7) //prompts again while input is invalid
		{
			System.out.print("Invalid choice. Your choice: ");
			choice = keyboard.nextInt();
		}
		return choice; //return choice
	}
	
	//@param The method takes in the parameter planet of the array type PlanetData[]
	public static void showAll(PlanetData[] planet)
	{
		for (int i = 0; i < planet.length; i++) //loops through file and displays all planet data 
		{
	       System.out.printf("\n%-20s%20s\n%-20s%20.2f\n%-20s%20.2f\n%-20s%20.2f\n%-20s%20.2f\n\n", 
	    		   "Name:", planet[i].getName(), "Planetary Radius:", planet[i].getRadius(), "Stellar Flux:", 
	    		   planet[i].getFlux(), "Similarity Index:", planet[i].getEsi(), "Distance from Earth:", 
	    		   planet[i].getDistance()); 
		}
	}
	
	//@param The method takes in the parameter planet of the array type PlanetData[]
	public static void changeRadius(PlanetData[] planet)
	{
		Scanner keyboard = new Scanner(System.in);
		int planetChoice = pickPlanet(planet); //calls for planet choice
		System.out.println("\nCurrent planetary radius: " + planet[planetChoice].getRadius()); 
		System.out.print("Please enter a new radius : "); //displays current radius and prompts user for new radius
		double newRadius = keyboard.nextDouble();
		 System.out.printf("\n%-20s%20s\n%-20s%20.2f\n%-20s%20.2f\n%-20s%20.2f\n%-20s%20.2f\n\n", 
	    		   "Name:", planet[planetChoice].getName(), "Planetary Radius:", newRadius, "Stellar Flux:", 
	    		   planet[planetChoice].getFlux(), "Similarity Index:", planet[planetChoice].getEsi(), "Distance from Earth:", 
	    		   planet[planetChoice].getDistance()); //displays planet data with new radius
	}
	
	//@parameter The method takes in the parameter planet of the array type PlanetData[]
	public static void changeFlux(PlanetData[] planet)
	{
		Scanner keyboard = new Scanner(System.in);
		int planetChoice = pickPlanet(planet); //calls for planet choice
		System.out.println("\nCurrent stellar flux: " + planet[planetChoice].getFlux());
		System.out.print("Please enter a new flux : "); //displays current flux and prompts user for new flux
		double newFlux = keyboard.nextDouble();
		 System.out.printf("\n%-20s%20s\n%-20s%20.2f\n%-20s%20.2f\n%-20s%20.2f\n%-20s%20.2f\n\n", 
	    		   "Name:", planet[planetChoice].getName(), "Planetary Radius:", planet[planetChoice].getRadius(), "Stellar Flux:", 
	    		   newFlux, "Similarity Index:", planet[planetChoice].getEsi(), "Distance from Earth:", 
	    		   planet[planetChoice].getDistance()); //displays planet data with new flux
		 
	}
	
	//@param The method takes in the parameter planet of the array type PlanetData[]
	//@return The planet choice is returned of the the int type
	private static int pickPlanet(PlanetData[] planet)
	{
		Scanner keyboard = new Scanner(System.in);
		System.out.print("\nSelect a planet: \n"); //displays list of planets and prompts user to select 
		for (int i = 0; i < planet.length; i++)
		{
			System.out.println((i + 1) + ". " + planet[i].getName());
		}
		System.out.print("Which planet? (1 - 10) ");
		int choice = keyboard.nextInt();
		while (choice < 1 || choice > 10) //prompts user to re enter choice until valid
		{
			System.out.print("Invalid planet. Which planet (1 - 10)? ");
			choice = keyboard.nextInt();
		}
		return choice - 1; //return choice 
			
		
	}
	
	//@param The method takes in the parameter planet of the array type PlanetData[]
	public static void showMostSimilar(PlanetData[] planet)
	{
		PlanetData[] mostSimilarData = new PlanetData[1]; //creates new array of 1 element
		double mostSimilar = 0.0;
		int j = 0;
		for (int i = 0; i < planet.length; i++) //loops through planet array and compares Esi's 
		{										//if new max found, saves to new array
			double esi = planet[i].getEsi();
			if (esi > mostSimilar)
			{
				mostSimilar = esi;
				mostSimilarData[j] = planet[i];
			}
			
		}
		System.out.printf("\nThe planet with the greatest Earth similarity index is:" //prints planet data of highest Esi
				+ "\n%-20s%20s\n%-20s%20.2f\n%-20s%20.2f\n%-20s%20.2f\n%-20s%20.2f\n\n", 
		   "Name:", mostSimilarData[j].getName(), "Planetary Radius:", mostSimilarData[j].getRadius(), "Stellar Flux:", 
		   mostSimilarData[j].getFlux(), "Similarity Index:", mostSimilarData[j].getEsi(), "Distance from Earth:", 
		   mostSimilarData[j].getDistance());
	}
	
	//@param The method takes in the parameter planet of the array type PlanetData[]
	public static void showLeastSimilar(PlanetData[] planet)
	{
		PlanetData[] leastSimilarData = new PlanetData[1]; //creates new array of 1 element
		double leastSimilar = 100.0;
		int j = 0;
		for (int i = 0; i < planet.length; i++)//loops through planet array and compares Esi's
		{									   //if new min found, saves to new array
			double esi = planet[i].getEsi();
			if (esi < leastSimilar)
			{
				leastSimilar = esi;
				leastSimilarData[j] = planet[i];
			}
		}
		System.out.printf("\nThe planet with the lowest Earth similarity index is:"  //prints planet data of lowest Esi
				+ "\n%-20s%20s\n%-20s%20.2f\n%-20s%20.2f\n%-20s%20.2f\n%-20s%20.2f\n\n", 
				   "Name:", leastSimilarData[j].getName(), "Planetary Radius:", leastSimilarData[j].getRadius(), "Stellar Flux:", 
				   leastSimilarData[j].getFlux(), "Similarity Index:", leastSimilarData[j].getEsi(), "Distance from Earth:", 
				   leastSimilarData[j].getDistance());
		}
	
	//@param The method takes in the parameter planet of the array type PlanetData[]
	public static void showAverageSimilarity(PlanetData[] planet)
	{
		double averageEsi = 0.0;
		for (int i = 0; i < planet.length; i++) //loops through array and adds up all Esi's
		{
			double esi = planet[i].getEsi();
			averageEsi += esi;
		}
		averageEsi /= planet.length; //calculates average Esi
		System.out.printf("\nThe average Earth similarity index of planets in the data file is: %.2f\n", averageEsi); //displays average esi
	}

}