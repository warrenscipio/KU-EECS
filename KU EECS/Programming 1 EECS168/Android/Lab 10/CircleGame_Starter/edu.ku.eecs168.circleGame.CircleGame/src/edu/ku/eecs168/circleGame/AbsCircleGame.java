package edu.ku.eecs168.circleGame;

import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;
import edu.ku.eecs168.circleGame.R;
import edu.ku.swingemu.AndroidJApplet;

public abstract class AbsCircleGame extends AndroidJApplet{

	private static final int UPDATE = 1;
	private Handler mHandler;
	private static final double FRAMES_PER_SECOND = 60;
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		mHandler = new Handler(){
			@Override
			public void handleMessage(Message msg) {
				repaint();
				this.sendEmptyMessageDelayed(UPDATE, (long)(1000/FRAMES_PER_SECOND));//24fps
			}
		};
		//start the simulation
		mHandler.sendEmptyMessage(UPDATE);
	}
	
	@Override
	protected void onPause() {
		super.onPause();
		if(mHandler.hasMessages(UPDATE)) mHandler.removeMessages(UPDATE);
	}
	
	@Override
	protected void onResume() {
		super.onResume();
		mHandler.sendEmptyMessage(UPDATE);
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		//Add options from xml file
		getMenuInflater().inflate(R.menu.menu, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		if(item.getItemId() == R.id.b1){
			//Add Shapes button has been pressed
			createDialog();
		}
		return super.onOptionsItemSelected(item);
	}
	
	public void onDialogReturned(int num){
		//if already simulating stop
		if(mHandler.hasMessages(UPDATE)) mHandler.removeMessages(UPDATE);
		//start the simulation
		mHandler.sendEmptyMessage(UPDATE);
	}
	
	private void createDialog() {
		AlertDialog.Builder b = new Builder(this);
		b.setMessage("Enter the amount of time in Seconds");
		final EditText input = (EditText)View.inflate(this, R.layout.input, null);
		b.setView(input);
		b.setPositiveButton("Ok", new OnClickListener() {
			
			public void onClick(DialogInterface dialog, int which) {
				String text = input.getText().toString();
				dialog.dismiss();
				try{
					onDialogReturned(Integer.valueOf(text));
				}catch(NumberFormatException e){
					Toast.makeText(AbsCircleGame.this, "Please enter a number.", Toast.LENGTH_SHORT).show();
				}
			}
		});
		b.show();
	}
}
