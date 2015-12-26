package edu.ku.lab12;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;

import android.graphics.Bitmap;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

import edu.ku.swingemu.AndroidJApplet;

public class ImageProcessor extends AndroidJApplet {

	public static final String EXTRA_FILE = "extra_file";

	File pgmFile;
	Bitmap bitmap;
	int[][] colors;
	//added width and height variables
	int width;
	int height;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		pgmFile = (File) getIntent().getExtras().getSerializable(EXTRA_FILE);
		colors = createArrayFromPGM(pgmFile.getAbsolutePath());
		bitmap = createBitmapFromColorArray();
	}

	// Given the absolute file name of a PGM image, this routine should
	// return a multidimensional array containing an image to display on the
	// screen.
	// The first dimension should be height (vertical), and the second should be
	// width (horizontal).
	// Color values should range from 0 to 255, just like they do in the PGM
	// image.

	@SuppressWarnings({ "resource" })
	private int[][] createArrayFromPGM(String filename) {
		FileReader inStream;
		int[][] image = null;
		//created second array to flip
		int[][] color2 = null;

		try {
			inStream = new FileReader(filename);
			BufferedReader in = new BufferedReader(inStream);

			in.readLine();
			in.readLine();
			String Line = in.readLine();
			Scanner input = new Scanner(Line);
			// splits 3rd line of pgm
			int picWidth = input.nextInt();
			int picHeight = input.nextInt();
			//lets log cat print out height and width
			Log.i("Lab 12", "Height = " + picHeight + ", width = " + picWidth);
			//setting width and height to public variables for other methods
			width = picWidth;
			height = picHeight;
			
			color2 = new int[picHeight][picWidth];
			//nested loops grabbing info from pgm and setting it to color
			for (int i = 0; i < picHeight; i++) {
				for (int j = 0; j < picWidth; j++) {
					color2[i][j] = Integer.parseInt(in.readLine());
				}

			}
			image = new int[picWidth][picHeight];
			//nested loop turning image upright and giving info to image[][]
			for (int i = 0; i < picWidth; i++) {
				for (int j = 0; j < picHeight; j++) {
					image[i][j] = color2[j][picWidth - 1 - i];
				}

			}

		} catch (FileNotFoundException e) {

			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		// TODO open the file and create a color array from the values in the
		// file
		return image;
	}

	// ---------------------------------------------------------------------------------------------------//
	// Image Processing
	void onPhotonegative() {
		// nested loop to change each pixel to opposite value
		for (int row = 0; row < width; row++) {
			for (int col = 0; col < height; col++) {

				colors[row][col] = 255 - colors[row][col];
			}
		}

	}

	void setOriginal() {
		// gets oringal pgm information (already flipped)
		int[][] temp = new int[width][height];
		temp = createArrayFromPGM(pgmFile.getAbsolutePath());
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				colors[i][j] = temp[i][j];
			}

		}
	}

	void onEmboss() {
		// nested loop to set scan through array checking values next to each other
		for (int row = 0; row < width - 1; row++) {
			for (int col = 0; col < height; col++) {
				// formula to change array values depending on the array value to the left
				colors[row][col] = (int) (140 + (colors[row+1][col] - colors[row][col]) / 2);
				

			}
		}

	}

	void onBlur() {
		int sum = 0;
		int number=0;
		int[][] blurredArray = new int[width][height];
		//nested loops to set blurred array
		for (int row = 0; row < width; row++) {
			for (int col = 0; col < height; col++) {
				//resets number and sum
				number =0;
				sum =0;
				
				for (int row2 = row-5; row2 < row+6; row2++) {
					for (int col2 = col-5; col2 < col+6; col2++) {
						//if statement makes sure to keep index from being out of bounds
						if((col2<0)||(row2<0)||(col2>=height)||(row2>=width)){
							
							continue;
						}else{
						number++;
						sum+=colors[row2][col2];
						
						}
						
							
						
						
					}
				}
				
				sum /=number;
				
				blurredArray[row][col]=sum;
		
			}

		}
		colors=blurredArray;
	}
	//failed attempt to double the size of the image
	void fullScreen(){
		boolean next=false;
		int[][] temp = new int[width][height];
		int[][] fittemp = new int[width*2][height*2];
		temp = createArrayFromPGM(pgmFile.getAbsolutePath());
		for (int i = 0; i < width; i++) {
			if(next){
				next=false;
				continue;
		}
			for (int j = 0; j < height; j++) {
				
				if(next)
					break;
				
				 for (int k = 0; k < width*2; k++) {
					 if(next)
						 break;
					 
						for (int l = 0; l < height*2; l++) {
							int two= 0;
							
							if(two<2){
							 fittemp[k][l]= temp[i][j];
							
							two++;
							}else{
								next=true;
								break;
							}
						}
				 }
				 
				 
			}

		}
		
	    
		
	}
	
	
	
	
	

	// ---------------------------------------------------------------------------------------------------//
	/**
	 * Creates a grayscale bitmap given an array of integers representing a
	 * value of luminosity ranging between 0 and 255. The array should be
	 * allocated with width as the first dimension. int[width][height]
	 * 
	 * @param colors
	 *            - values between 0 and 255
	 * @return
	 */
	private Bitmap createBitmapFromColorArray() {
		if (colors == null)
			return null;
		Bitmap bm = Bitmap.createBitmap(colors.length, colors[0].length,
				Bitmap.Config.ARGB_8888);
		int curColor;
		for (int row = 0; row < bm.getHeight(); row++) {
			for (int col = 0; col < bm.getWidth(); col++) {
				curColor = colors[col][row];
				bm.setPixel(col, row, Color.rgb(curColor, curColor, curColor));
			}
		}
		repaint();
		return bm;
	}

	@Override
	public void paint(Graphics canvas) {
		canvas.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
		if (bitmap != null)
			canvas.setBitmap(bitmap, 0, 0);
	}

	// ---------------------------------------------------------------------------------------------------//
	// Handle menu options
	private static final int MENU_NEG = Menu.FIRST;
	private static final int MENU_POSTERIZE = Menu.FIRST + 1;
	private static final int MENU_BLUR = Menu.FIRST + 2;
	private static final int MENU_EMBOSS = Menu.FIRST + 3;
	private static final int MENU_JPEG = Menu.FIRST + 4;
	private static final int MENU_FULL = Menu.FIRST + 5;
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		menu.add(0, MENU_FULL, 2, "Photonegative").setShowAsAction(
				MenuItem.SHOW_AS_ACTION_ALWAYS);
		menu.add(0, MENU_NEG, 0, "Full Screen").setShowAsAction(
				MenuItem.SHOW_AS_ACTION_ALWAYS);
		menu.add(0, MENU_EMBOSS, 1, "Emboss").setShowAsAction(
				MenuItem.SHOW_AS_ACTION_ALWAYS);
		menu.add(0, MENU_BLUR, 2, "Blur").setShowAsAction(
				MenuItem.SHOW_AS_ACTION_ALWAYS);
		menu.add(0, MENU_POSTERIZE, 3, "Get Original").setShowAsAction(
				MenuItem.SHOW_AS_ACTION_ALWAYS);
		menu.add(0, MENU_JPEG, 4, "Save").setShowAsAction(
				MenuItem.SHOW_AS_ACTION_ALWAYS);
		
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		
		if (item.getItemId() == MENU_FULL) {
			onPhotonegative();
			bitmap = createBitmapFromColorArray();
		}

		if (item.getItemId() == MENU_NEG) {
			fullScreen();
			bitmap = createBitmapFromColorArray();
		}

		if (item.getItemId() == MENU_POSTERIZE) {
			setOriginal();
			bitmap = createBitmapFromColorArray();
		}

		if (item.getItemId() == MENU_BLUR) {
			onBlur();
			bitmap = createBitmapFromColorArray();
		}

		if (item.getItemId() == MENU_EMBOSS) {
			onEmboss();
			bitmap = createBitmapFromColorArray();
		}

		if (item.getItemId() == MENU_JPEG) {
			onSave();
		}

		return super.onOptionsItemSelected(item);
	}

	private void onSave() {
		saveScreenToJPG("myscreen");
	}
}
