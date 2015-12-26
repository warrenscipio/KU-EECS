package edu.ku.camera;

import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.hardware.Camera;
import android.hardware.Camera.Parameters;
import android.hardware.Camera.Size;
import android.os.Bundle;
import android.os.Environment;
import android.view.Menu;
import android.view.MenuItem;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.ViewGroup.LayoutParams;
import android.widget.Toast;

public abstract class CameraTemplateActivity extends Activity implements Camera.AutoFocusCallback, Camera.PictureCallback, Camera.ShutterCallback, SurfaceHolder.Callback {

	private static final int MENU_PICTURE = Menu.FIRST;
	private static final int MENU_CAMERA = MENU_PICTURE + 1;
	
	private static final int SURFACE_ID = 1000;
	
	private int mCurCamera;
	private Camera mCamera;
	private SurfaceHolder mSurfaceHolder;
	
	/**
	 * Will be called after the take picture button is pressed.
	 * @param image - The byte array of the jpeg taken by the camera
	 */
	public abstract void onPictureTaken(byte[] image);
	
	@Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

    	//Creating our own view and assigning id to avoid using the R file
        //This way the file will not need to be edited to use with different labs.
        SurfaceView v = new SurfaceView(this);
        v.setId(SURFACE_ID);
        v.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
        setContentView(v);
        //when the device is rotated the activity is destroyed
        //but we persist the camera being used in
        //onSaveInstanceState(Bundle outState) 
        if(savedInstanceState != null){
        	mCurCamera = savedInstanceState.getInt("cam");
        }
        else{
        	mCurCamera = 0;
        }
        
    }
	
	@Override
	protected void onResume() {
		super.onResume();

		SurfaceView surface = (SurfaceView)findViewById(SURFACE_ID);
		SurfaceHolder holder = surface.getHolder();
		if(mSurfaceHolder != null){
			//Activity was paused but not destroyed so the surface still exists it is safe to 
			//re-attach the camera.
			initCamera(holder);
		}
		else{
			//this will call surfaceCreated() when our new surface is ready to be used
			holder.addCallback(this);
		}
	}
	
	@Override
	protected void onPause() {
		super.onPause();
		//must release the camera on pause otherwise other applications
		//will not be able to use the camera
		if(mCamera != null){
			mCamera.release();
			mCamera = null;
		}
	}
	
	private void initCamera(SurfaceHolder holder){
		if(mCamera != null){
			//camera had already been initiated, we are switching cameras
			mCamera.release();
		}
		//mCurCamera is an integer denoting front-facing or back camera
		mCamera = Camera.open(mCurCamera);
		Camera.Parameters p = mCamera.getParameters();

		//if the camera has a flash enable auto flash
		List<String> supportedFlash = p.getSupportedFlashModes();
		if(supportedFlash != null && supportedFlash.contains(Parameters.FLASH_MODE_AUTO)){
			p.setFlashMode(Parameters.FLASH_MODE_AUTO);
		}

		List<Size> sizes = p.getSupportedPictureSizes();
		//find smallest size supported
		if(sizes != null && sizes.size() > 0){
			Size smallest = sizes.get(0);
			for(Size s : sizes){
				if (Math.abs(s.width*s.height - 480000) <
						Math.abs(smallest.width*smallest.height - 480000)) smallest = s;
			}
			p.setPictureSize(smallest.width, smallest.height);
		}
		
		mCamera.setParameters(p);
		
		//set camera rotation based off devices orientation
		//this is taken from the Camera class documentation 
		Camera.CameraInfo info = new Camera.CameraInfo();
	    Camera.getCameraInfo(mCurCamera, info);
	    int rotation = getWindowManager().getDefaultDisplay().getRotation();
	    int degrees = 0;
	    switch (rotation) {
	        case Surface.ROTATION_0: degrees = 0; break;
	        case Surface.ROTATION_90: degrees = 90; break;
	        case Surface.ROTATION_180: degrees = 180; break;
	        case Surface.ROTATION_270: degrees = 270; break;
	    }
	
	    int result;
	    if (info.facing == Camera.CameraInfo.CAMERA_FACING_FRONT) {
	        result = (info.orientation + degrees) % 360;
	        result = (360 - result) % 360;  // compensate the mirror
	    } else {  // back-facing
	        result = (info.orientation - degrees + 360) % 360;
	    }
	    mCamera.setDisplayOrientation(result);
		
		try {
			//attach the surface view to the camera can not take pictures without it
			mCamera.setPreviewDisplay(holder);
		} catch (IOException e) {
			Toast.makeText(this, "Failed to attach preview display", Toast.LENGTH_SHORT).show();
			e.printStackTrace();
		}
		
		mCamera.startPreview();
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		menu.add(0,MENU_PICTURE, 1, "Take Picture").setShowAsAction(MenuItem.SHOW_AS_ACTION_ALWAYS);
		if(Camera.getNumberOfCameras() > 1) menu.add(0, MENU_CAMERA, 0, "Switch Camera").setShowAsAction(MenuItem.SHOW_AS_ACTION_ALWAYS);
		return true;
	}
	
	@Override
	public boolean onOptionsItemSelected(MenuItem item) {

		if(item.getItemId() == MENU_PICTURE){
			if(mCamera != null){
				//start autofocus, once the camera is focused the autofocus callback will take the picture
				mCamera.autoFocus(this);
			}
		}
		
		else if(item.getItemId() == MENU_CAMERA){
			if(mSurfaceHolder != null){
				mCurCamera = mCurCamera == 0? 1 : 0;
				initCamera(mSurfaceHolder);
			}
		}
		
		return super.onOptionsItemSelected(item);
	}
	
	@Override
	protected void onSaveInstanceState(Bundle outState) {
		//persist the users camera selection when device is rotated 
		outState.putInt("cam", mCurCamera);
		super.onSaveInstanceState(outState);
	}
	
	public void onAutoFocus(boolean success, Camera camera) {
		if(success){
			camera.takePicture(this, null, this);
		}
	}

	public void onShutter() {
		//not used
	}
	
	public void onPictureTaken(byte[] data, Camera camera) {
		
		//callback implemented by students
		onPictureTaken(data);
		
		//must start preview again to enable a new picture to be taken
		camera.startPreview();
	}
	
	public void surfaceChanged(SurfaceHolder holder, int format, int width,
			int height) {
		// not used
		
	}

	public void surfaceCreated(SurfaceHolder holder) {
		mSurfaceHolder = holder;
		initCamera(holder);
	}

	public void surfaceDestroyed(SurfaceHolder holder) {
		mSurfaceHolder = null;
	}

	public File createPGMFile(byte[] data){
		Bitmap bm = BitmapFactory.decodeByteArray(data, 0, data.length);
		return createPGMFile(bm);
	}
	
	public static File createPGMFile(Bitmap bm){
		
		try{
			File pictureDirectory = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
			File pictureLoc = new File(pictureDirectory, "output.pgm");
			PrintWriter writer = new PrintWriter(pictureLoc);
			BufferedWriter savedFile = new BufferedWriter(writer);
			//Write PGM header to the file
			savedFile.write("P2\n");
			savedFile.write("# ku lab\n");
			int color;
			char r,g,b;
			savedFile.write(String.format("%s %s%n", bm.getWidth(), bm.getHeight()));
			for(int row = 0; row < bm.getHeight(); row++){
				for(int col = 0; col < bm.getWidth(); col++){
					//Extract current pixel and convert to grayscale 
					color = bm.getPixel(col, row);
					r = (char) (Color.red(color) * 0.2989f);
					g = (char) (Color.green(color) * 0.5870f);
					b = (char) (Color.blue(color) *  0.1140f);
					//Cast to string to preserve ascii output required for pgm format
					//all other types output as binary.
					savedFile.write(String.valueOf(r + g + b));
					savedFile.write('\n');
				}
			}
			savedFile.flush();
			savedFile.close();
			return pictureLoc;
		}catch(Exception e){
			return null;
		}
	}
	
}