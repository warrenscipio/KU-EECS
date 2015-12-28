package edu.ku.lab12;

import java.io.File;

import android.content.Intent;
import android.hardware.Camera;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

import edu.ku.camera.CameraTemplateActivity;

public class Lab12 extends CameraTemplateActivity {

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		Log.i("Lab12", "onCreate has been called.");
//		causeAForceClose();
	}
	
	@Override
	public void onPictureTaken(byte[] image) {
		Log.i("Lab12", "a new picture has been taken.");
		File pgm = createPGMFile(image);
		Intent i = new Intent(this, ImageProcessor.class);
		i.putExtra(ImageProcessor.EXTRA_FILE, pgm);
		startActivity(i);
	}

	@Override
	public void onShutter() {
		Toast.makeText(this, "creating pgm file please wait", Toast.LENGTH_SHORT).show();
	}

	public void causeAForceClose(){
		String s = null;
		char oops = s.charAt(1);
	}
	
}
