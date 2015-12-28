package edu.ku.eecs168.lab5;

import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;
import edu.ku.swingemu.AndroidJApplet;

public abstract class AbsLab5 extends AndroidJApplet{

	
	public abstract void onDialogReturned(int num);
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
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
	
	private void createDialog() {
		AlertDialog.Builder b = new Builder(this);
		b.setMessage("Enter the amount of shapes to draw");
		final EditText input = (EditText)View.inflate(this, R.layout.input, null);
		b.setView(input);
		b.setPositiveButton("Ok", new OnClickListener() {
			
			public void onClick(DialogInterface dialog, int which) {
				String text = input.getText().toString();
				dialog.dismiss();
				try{
					onDialogReturned(Integer.valueOf(text));
				}catch(NumberFormatException e){
					Toast.makeText(AbsLab5.this, "Please enter a number.", Toast.LENGTH_SHORT).show();
				}
			}
		});
		b.show();
	}
}
